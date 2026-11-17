# 电控组第三次培训作业

- 姓名：**黄予涵**
- 学号：**20253008098**

## 一、完成的功能

| 功能 | 实现方式 |
|---|---|
| 三灯流水，同一时刻只亮一颗 | 灯表 + 状态机，`Led_ShowIndex()` 先把三颗全灭再点亮目标灯 |
| 按键 1 切换正/反向 | PA11 下降沿外部中断 → 置标志 → 主循环翻转方向 |
| 按键 2 切换暂停/继续 | PA12 下降沿外部中断 → 置标志 → 主循环翻转运行标志 |
| 暂停保留当前灯、恢复后按当前方向继续 | 暂停时 `LedFlow_Task()` 直接返回，既不动灯也不推进计时 |
| 按键消抖，按一次只触发一次 | 200 ms 锁定窗口 + 回读引脚电平（见第四节） |
| 串口数据包控制运行/方向/间隔 | USART1 接收中断 + 6 字节 packed 结构体 + 校验和 |
| OLED 显示当前状态 | 软件 I²C（PB1-SCL / PB0-SDA），四行状态 |
| 串口中断发送状态反馈 | `HAL_UART_Transmit_IT()` + 忙/待发标志 |

## 二、硬件接线

| 功能 | 引脚 | 接法 |
|---|---|---|
| LED1 / LED2 / LED3 | PA0 / PA2 / PA4 | LED 串限流电阻到 GND，**高电平点亮** |
| 按键 1（方向） | PA11 | 一端接 PA11，另一端接 GND，内部上拉，按下产生下降沿 |
| 按键 2（暂停/继续） | PA12 | 同上 |
| 串口 | PA9 / PA10 | PA9→模块 RX，PA10←模块 TX，**必须共地**，VCC 不接 |
| OLED（4 针 I²C） | PB1 / PB0 | PB1→SCL，PB0→SDA，VCC→3.3V，GND→GND |

时钟为 HSE 8 MHz 经 PLL×9 = 72 MHz，串口 115200-8-N-1。

![接线图](docs/wiring.svg)

图中蓝点表示引脚连接点；三路灯的 GND、两个按键的 GND、OLED 的 GND、串口模块的 GND 最终都连到板上任意 GND 引脚，**共地是串口能通信的前提**。串口模块的 VCC 不要接（模块由 USB 供电）。

## 三、程序结构

所有功能共用**同一份运行状态**，这是"按键、串口、显示、反馈一致"的前提：

```c
static uint8_t  s_run      = 1U;    /* 1 运行 / 0 暂停 */
static uint8_t  s_dir      = 0U;    /* 0 正向 / 1 反向 */
static uint16_t s_stepMs   = 300U;  /* 100 ~ 2000 */
static uint8_t  s_ledIndex = 0U;    /* 0~2，对应 LED1~LED3 */
```

主循环只跑五个任务，每个都不阻塞：

```c
while (1)
{
  Key_Task();       /* 按键消抖 + 状态切换 */
  Packet_Task();    /* 数据包校验 + 应用设置 */
  LedFlow_Task();   /* 流水灯推进 */
  Display_Task();   /* 状态变了才刷 OLED */
  Uart_Task();      /* 补发被忙时挤掉的反馈 */
}
```

**中断只做"记录事件"，处理全在主循环**：EXTI 回调只置 `s_keyDirFlag` / `s_keyPauseFlag`，串口接收回调只把 6 字节整体复制到 `s_readyPacket` 并置 `s_packetReady`。校验、解析、状态更新、刷屏都在主循环完成，中断时间恒定在微秒级。

| 文件 | 职责 |
|---|---|
| `Core/Src/main.c` | 状态机、按键处理、数据包解析、显示与反馈 |
| `Core/Src/usart.c` | CubeMX 生成的 USART1 初始化（115200-8-N-1） |
| `Core/Src/gpio.c` | 三灯推挽输出 + 两键上拉下降沿中断 |
| `Core/Src/OLED.c` | 软件 I²C + SSD1306 驱动（8×16 字模） |

## 四、关键实现说明

### 1. 流水灯用非阻塞计时

没有用 `HAL_Delay()`，而是记住上次换灯的时刻，每次进函数只判断一次时间差：

```c
static void LedFlow_Task(void)
{
  uint32_t now = HAL_GetTick();

  if (s_run == 0U) return;                                  /* 暂停：灯和计时都停 */
  if ((uint32_t)(now - s_lastStepTick) < (uint32_t)s_stepMs) return;

  s_lastStepTick = now;                                     /* 以实际换灯时刻为基准 */

  if (s_dir == 0U) s_ledIndex = (uint8_t)((s_ledIndex + 1U) % LED_NUM);
  else             s_ledIndex = (uint8_t)((s_ledIndex + LED_NUM - 1U) % LED_NUM);

  Led_ShowIndex(s_ledIndex);
  s_displayDirty = 1U;
}
```

两个细节：

- **时间差用无符号相减**（`now - s_lastStepTick`）。`HAL_GetTick()` 是 32 位毫秒计数，约 49.7 天回绕一次，无符号减法按模 2³² 计算，回绕时差值仍然正确；写成 `now > last + 300` 则会因为加法溢出而出错。
- **基准取"实际换灯那一刻"而不是 `+= step`**。后者把基准锁在理想网格上，主循环一旦被拖慢就会连续补跳。

方向用 `(idx + N - 1) % N` 表达反向，避免 `idx - 1` 在 `idx = 0` 时下溢成 255。

### 2. 按键消抖

外部中断在每次下降沿都会触发，而机械按键按下瞬间会抖动出多次边沿。消抖放在主循环里，用"锁定窗口 + 回读电平"两重判断：

```c
if (((uint32_t)(now - s_dirKeyTick) >= KEY_LOCKOUT_MS) &&
    (HAL_GPIO_ReadPin(KEY_DIR_GPIO_Port, KEY_DIR_Pin) == GPIO_PIN_RESET))
{
  s_dirKeyTick = now;
  s_dir ^= 1U;
}
```

- **锁定窗口 200 ms**：抖动集中在按下后十毫秒内，这个窗口足以滤掉重复边沿；同时 200 ms 远小于人手连按的最短间隔，不影响正常操作。
- **回读电平**：只有此刻引脚仍然是低电平才认这次按下，可以排除线上毛刺导致的假中断。

### 3. 串口数据包

数据包格式 `AA RUN DIR STEP_L STEP_H CHECK`，共 6 字节。接收侧直接用打包结构体承接：

```c
typedef struct __attribute__((packed))
{
  uint8_t  header;      /* 0xAA */
  uint8_t  run;         /* 00 暂停 / 01 运行 */
  uint8_t  dir;         /* 00 正向 / 01 反向 */
  uint16_t step_ms;     /* 低字节在前 */
  uint8_t  checksum;
} CtrlPacket_t;
```

`__attribute__((packed))` 让成员之间不插入对齐填充，`sizeof` 恰好是 6。**必须加**：`uint16_t` 默认要求 2 字节对齐，不加会多出 1 字节填充变成 7 字节，接收长度和字段位置全错。

`step_ms` 能用 `uint16_t` 直接读，是因为 STM32 是小端，发送方按"低字节在前"发，正好对上内存布局。所以收包后不需要手工拼字节，直接用 `pkt.step_ms` 就是毫秒数。

校验和应用：

```c
const uint8_t *bytes = (const uint8_t *)&pkt;              /* 按原始字节看这份包 */
uint8_t expected = (uint8_t)(bytes[0] + bytes[1] + bytes[2] + bytes[3] + bytes[4]);

if (pkt.header != 0xAA)          return;   /* 帧头不对，整包丢弃 */
if (pkt.checksum != expected)    return;   /* 校验和不对，整包丢弃 */
if (pkt.run > 1U || pkt.dir > 1U) return;
if (pkt.step_ms < 100U || pkt.step_ms > 2000U) return;
```

所有字段全部合法才一次性更新状态，避免"改了一半"的中间态。

接收流程（能连续收多包）：

```c
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
    if (s_packetReady == 0U)            /* 主循环还没处理完就丢弃新包 */
    {
      s_readyPacket = s_rxPacket;       /* 6 字节整体复制 */
      s_packetReady = 1U;
    }
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&s_rxPacket, sizeof(s_rxPacket));
  }
}
```

回调里**立刻重启接收**，主循环处理当前包的同时串口还能继续收，所以电脑连续发多包不会只收到第一包。`s_rxPacket` 和 `s_readyPacket` 分工，避免主循环读到一半被下一包覆盖。

### 4. OLED 显示

四行固定内容，`STATE` / `DIR` / `STEP` / `LED`，每次状态变化整屏重画一遍：

```c
OLED_BufClear();                                        /* 整帧从全 0 开始拼 */
snprintf(buf, sizeof(buf), "STATE: %s", ...);
Display_Line(1U, buf);                                  /* 不足 16 字符补空格 */
...
OLED_Flush();                                           /* 8 页整块推送 */
```

显示走的是"RAM 帧缓冲 + 整页写入"，而不是原来的"逐列设光标 + 逐字节传输"：

| 做法 | 一帧的 I²C 传输次数 | 特点 |
|---|---|---|
| 逐列写（原驱动写法） | 8 页 × 128 列 × 2 = 2048 次 | 任何一次传输出问题，那一列就留下旧数据，且无法自愈 |
| 帧缓冲 + 整页写（当前） | 8 次，每页 132 字节一次传完 | 每帧把可见区每个字节显式写一遍，空白处就是 0x00 |

- **补空格**：新内容比旧内容短时（比如 `PAUSE` → `RUN`、`2000ms` → `300ms`），不补齐会残留上一帧的字符。
- **不做"内容没变就跳过"**：曾经试过用行缓存只重画变化的行，但一旦某次写入失败让屏幕和缓存不一致，跳过逻辑会让残字永远留在屏上，只能复位才好。
- **每帧写满 132 列**：1.3 寸模块显存是 132×64，可见区比 0.96 寸宽；只写 128 列会让最右边几列保留上电随机值，表现为一条竖条噪点。对 128 列的 0.96 寸屏，多写的 4 个 `0x00` 绕回本页最左边，写的仍是 0，没有副作用。
- 一帧约 1 ms（8 次传输 × 132 字节），相对 100 ms 的最小切换间隔可以忽略。
- 暂停期间 `s_displayDirty` 仍会因按键或串口设置被置位，所以暂停时改参数屏幕照样更新。

### 5. 串口中断反馈

```c
static void Status_Send(void)
{
  if (s_txBusy != 0U) { s_txPending = 1U; return; }    /* 忙：只记待发 */

  len = snprintf(s_txBuf, sizeof(s_txBuf), "STATE=%s,DIR=%s,STEP=%u,LED=%u\r\n", ...);

  if (HAL_UART_Transmit_IT(&huart1, (uint8_t *)s_txBuf, (uint16_t)len) == HAL_OK)
    s_txBusy = 1U;
}
```

- `s_txBuf` 是 `static` 全局数组。中断发送期间缓冲区必须一直有效且不能被改写，所以不能用局部变量。
- 发送忙时不覆盖缓冲区，只置 `s_txPending`，等 `HAL_UART_TxCpltCallback()` 清掉 `s_txBusy` 后由 `Uart_Task()` 用最新状态补发。这样连续按键不会写出半截乱码。
- 只回传"状态级"的变化（开关、方向、收到新命令），换灯不打印，避免 300 ms 一包把串口刷满。

## 五、串口反馈格式

单片机上电和状态变化后回传一行 ASCII：

```
STATE=RUN,DIR=FWD,STEP=300,LED=1
```

| 字段 | 取值 | 含义 |
|---|---|---|
| `STATE` | `RUN` / `PAUSE` | 运行 / 暂停 |
| `DIR` | `FWD` / `REV` | 正向 / 反向 |
| `STEP` | 100~2000 | 相邻 LED 切换间隔，单位 ms，不带单位后缀 |
| `LED` | 1~3 | 当前点亮的灯编号 |

固定顺序、逗号分隔、`\r\n` 结尾，四个字段总是全部给出（不省略未变化的项），方便串口助手直接比对整行。

## 六、参考资料与驱动来源

- 培训指南《STM32 第三、四次培训学习指南》及其中的案例（外部中断、串口收发、数据包、软件 I²C OLED、DMA）。
- B 站 **Keysking**《STM32 入门教程》（HAL 库主线）：GPIO 输入与内部原理、外部中断、串口轮询/中断、IIC 通信。
- B 站 **江协科技**《STM32 入门教程》（标准库）：[3-3][3-4] GPIO 输入、[4-1][4-2] OLED、[5-1] EXTI、[9-1]~[9-5] 串口与数据包、[10-1] I²C 协议。
- ST 官方：UM1850（STM32F1 HAL 手册）、RM0008 参考手册、STM32F103C8 数据手册。
- **OLED 驱动来源**：电控组群文件中的 `OLED.c` / `OLED.h` / `OLED_Font.h`（江协科技风格，软件 I²C + 8×16 字模），本仓库原样放在 `Core/Src`、`Core/Inc`。

对该驱动做了三处修改：

1. `OLED_I2C_Init()` 里的 `GPIO_InitTypeDef` 原本没有初始化，`Pull` 字段是栈上随机值，可能让 SCL/SDA 带上拉低。已改成 `= {0}` 并显式设 `GPIO_PULLUP`。
2. `OLED_Clear()` 改为按 `OLED_RAM_WIDTH = 132` 列清屏。1.3 寸模块的控制器显存是 132×64，可见区比 0.96 寸的 128 列宽出 4 列，只清 128 列时最右侧几列会一直保留上电随机数据，表现为屏幕右边缘一条竖条噪点。对 0.96 寸的 128 列模块，多写的 4 个 `0x00` 只是绕回左侧、写的仍是 0，没有副作用。
3. 增加 `OLED_WriteMulti()` 与帧缓冲接口（`OLED_BufClear` / `OLED_BufPixel` / `OLED_BufChar` / `OLED_BufString` / `OLED_Flush`），显示改为"先拼帧、再按页整块写入"。原驱动每写一个字节都要一次完整的 Start/地址/控制字/Stop，整屏 2048 次传输，任何一次被干扰都会在该列留下旧数据；现在每页一次传输写 132 字节，每帧把可见区每个字节显式覆盖一遍。原有 `OLED_ShowChar` / `OLED_ShowString` 等接口保持不动，仍可单独使用。

## 七、思考题

> 流水灯切换间隔较长（如 2000 ms）时，按按键和发串口指令不能立刻执行，有延迟。问题在哪里，怎么改？

问题出在 **`HAL_Delay()` 是阻塞的**。它的内部就是一个原地等 tick 的循环：

```c
uint32_t tickstart = HAL_GetTick();
while ((HAL_GetTick() - tickstart) < Delay) { }
```

这 2000 ms 里 CPU 被锁在函数内部，虽然中断仍然能进来、标志仍然会被置位，但**没有人去读这些标志**——主循环被卡在延时里回不来。所以现象就是"按了没反应，等这段延时结束才突然生效"，间隔越长延迟越明显。串口也一样：中断把数据收进缓冲区，但解析和状态更新要等主循环转起来。

本实现从两处解决：

1. **换灯不用 `HAL_Delay()`**，改成 `HAL_GetTick()` 判时间差（见第四节），2000 ms 的间隔里主循环照样每几百微秒跑一圈。
2. **中断只置标志，处理放主循环**，且每个任务都是非阻塞的，主循环一轮的总耗时在微秒到毫秒级，按键和串口指令的响应延迟与流水灯间隔**解耦**。

顺带一提，如果显示刷新很慢（软件 I²C 整屏重画），也会造成可感知的延迟，所以显示部分只在状态变化时才重画，不做无意义的周期性刷屏；整屏刷新本身也优化成了一帧 8 次传输、约 1 ms。

## 八、选做说明

本次**未做**选做内容：

- **DMA 发送反馈**：仍用 `HAL_UART_Transmit_IT()` 中断发送。反馈只有一行几十字节，中断发送每个字节进一次中断的开销完全可以接受；DMA 更适合长数据或高频上报。
- **硬件 I²C 驱动 OLED**：仍用软件 I²C。

如果后续要补 DMA，改动点是：`Status_Send()` 里换成 `HAL_UART_Transmit_DMA()`，`usart.c` 增加 `USART1_TX` 的 DMA 请求（F103C8 上是 DMA1 Channel4、Normal 模式、内存→外设、字节宽度），并关掉半传输中断 `__HAL_DMA_DISABLE_IT(huart1.hdmatx, DMA_IT_HT)`，完成回调仍用 `HAL_UART_TxCpltCallback()` 清忙标志。忙/待发那套逻辑可以原样保留。

## 九、编译与烧录

工程由 STM32CubeMX 6.15.0 生成（`hw3.ioc`），用 CMake + arm-none-eabi-gcc 构建，可以直接用 CLion 打开：

1. CLion → Open → 选本目录，等待 CMake reload。
2. Settings → Build, Execution, Deployment → CMake → **Toolchain 选 `MinGW (STM32 gcc/g++)`**（交叉编译器是 CLion 自带的 arm-none-eabi-gcc）。
3. Build 生成 `cmake-build-debug/hw3.elf`（同时输出 `.hex` / `.bin`），用 ST-LINK 下载即可。

命令行方式：

```bash
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -B cmake-build-debug -S .
cmake --build cmake-build-debug
```

## 十、演示视频

待补充：`video/hw3_demo.mp4`

录制建议（覆盖验收标准四条）：上电后流水灯运行且 OLED 显示正确 → 按方向键看 LED 顺序反转、OLED 与串口同步 → 按暂停键停在当前灯 → 暂停期间发数据包改间隔和方向 → 恢复运行确认新设置生效。
