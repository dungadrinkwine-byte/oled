#include "stm32f1xx_hal.h"

#ifdef HAL_RCC_MODULE_ENABLED

#define MCO1_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define MCO1_GPIO_PORT        GPIOA
#define MCO1_PIN              GPIO_PIN_8

static void RCC_Delay(uint32_t mdelay);

HAL_StatusTypeDef HAL_RCC_DeInit(void)
{
  uint32_t tickstart;

  tickstart = HAL_GetTick();

  SET_BIT(RCC->CR, RCC_CR_HSION);

  while (READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RESET)
  {
    if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, (0x10U << RCC_CR_HSITRIM_Pos));

  tickstart = HAL_GetTick();

  CLEAR_REG(RCC->CFGR);

  while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  SystemCoreClock = HSI_VALUE;

  if (HAL_InitTick(uwTickPrio) != HAL_OK)
  {
    return HAL_ERROR;
  }

  tickstart = HAL_GetTick();

  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);

  while (READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  CLEAR_REG(RCC->CFGR);

  tickstart = HAL_GetTick();

  CLEAR_BIT(RCC->CR, RCC_CR_HSEON | RCC_CR_CSSON);

  while (READ_BIT(RCC->CR, RCC_CR_HSERDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);

#if defined(RCC_PLL2_SUPPORT)

  tickstart = HAL_GetTick();

  CLEAR_BIT(RCC->CR, RCC_CR_PLL2ON);

  while (READ_BIT(RCC->CR, RCC_CR_PLL2RDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL2_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
#endif

#if defined(RCC_PLLI2S_SUPPORT)

  tickstart = HAL_GetTick();

  CLEAR_BIT(RCC->CR, RCC_CR_PLL3ON);

  while (READ_BIT(RCC->CR, RCC_CR_PLL3RDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLLI2S_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
#endif

#if defined(RCC_CFGR2_PREDIV1)

  CLEAR_REG(RCC->CFGR2);
#endif

  SET_BIT(RCC->CSR, RCC_CSR_RMVF);

  CLEAR_REG(RCC->CIR);

  return HAL_OK;
}

HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  uint32_t tickstart;
  uint32_t pll_config;

  if (RCC_OscInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_RCC_OSCILLATORTYPE(RCC_OscInitStruct->OscillatorType));

  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
  {

    assert_param(IS_RCC_HSE(RCC_OscInitStruct->HSEState));

    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSE)
        || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE)))
    {
      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET) && (RCC_OscInitStruct->HSEState == RCC_HSE_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {

      __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);

      if (RCC_OscInitStruct->HSEState != RCC_HSE_OFF)
      {

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }

  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI)
  {

    assert_param(IS_RCC_HSI(RCC_OscInitStruct->HSIState));
    assert_param(IS_RCC_CALIBRATION_VALUE(RCC_OscInitStruct->HSICalibrationValue));

    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSI)
        || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSI_DIV2)))
    {

      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET) && (RCC_OscInitStruct->HSIState != RCC_HSI_ON))
      {
        return HAL_ERROR;
      }

      else
      {

        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
    }
    else
    {

      if (RCC_OscInitStruct->HSIState != RCC_HSI_OFF)
      {

        __HAL_RCC_HSI_ENABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
      else
      {

        __HAL_RCC_HSI_DISABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }

  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI)
  {

    assert_param(IS_RCC_LSI(RCC_OscInitStruct->LSIState));

    if (RCC_OscInitStruct->LSIState != RCC_LSI_OFF)
    {

      __HAL_RCC_LSI_ENABLE();

      tickstart = HAL_GetTick();

      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }

      RCC_Delay(1);
    }
    else
    {

      __HAL_RCC_LSI_DISABLE();

      tickstart = HAL_GetTick();

      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }

  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)
  {
    FlagStatus       pwrclkchanged = RESET;

    assert_param(IS_RCC_LSE(RCC_OscInitStruct->LSEState));

    if (__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if (HAL_IS_BIT_CLR(PWR->CR, PWR_CR_DBP))
    {

      SET_BIT(PWR->CR, PWR_CR_DBP);

      tickstart = HAL_GetTick();

      while (HAL_IS_BIT_CLR(PWR->CR, PWR_CR_DBP))
      {
        if ((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }

    __HAL_RCC_LSE_CONFIG(RCC_OscInitStruct->LSEState);

    if (RCC_OscInitStruct->LSEState != RCC_LSE_OFF)
    {

      tickstart = HAL_GetTick();

      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {

      tickstart = HAL_GetTick();

      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }

    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }

#if defined(RCC_CR_PLL2ON)

  assert_param(IS_RCC_PLL2(RCC_OscInitStruct->PLL2.PLL2State));
  if ((RCC_OscInitStruct->PLL2.PLL2State) != RCC_PLL2_NONE)
  {

    if ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE) && \
        (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && \
        ((READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC)) == RCC_CFGR2_PREDIV1SRC_PLL2))
    {
      return HAL_ERROR;
    }
    else
    {
      if ((RCC_OscInitStruct->PLL2.PLL2State) == RCC_PLL2_ON)
      {

        assert_param(IS_RCC_PLL2_MUL(RCC_OscInitStruct->PLL2.PLL2MUL));
        assert_param(IS_RCC_HSE_PREDIV2(RCC_OscInitStruct->PLL2.HSEPrediv2Value));

        if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLL3ON) && \
            (__HAL_RCC_HSE_GET_PREDIV2() != RCC_OscInitStruct->PLL2.HSEPrediv2Value))
        {
          return HAL_ERROR;
        }

        __HAL_RCC_PLL2_DISABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLL2RDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL2_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        __HAL_RCC_HSE_PREDIV2_CONFIG(RCC_OscInitStruct->PLL2.HSEPrediv2Value);

        __HAL_RCC_PLL2_CONFIG(RCC_OscInitStruct->PLL2.PLL2MUL);

        __HAL_RCC_PLL2_ENABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLL2RDY)  == RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL2_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {

        CLEAR_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC);

        __HAL_RCC_PLL2_DISABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLL2RDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL2_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }

#endif

  assert_param(IS_RCC_PLL(RCC_OscInitStruct->PLL.PLLState));
  if ((RCC_OscInitStruct->PLL.PLLState) != RCC_PLL_NONE)
  {

    if (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_SYSCLKSOURCE_STATUS_PLLCLK)
    {
      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_ON)
      {

        assert_param(IS_RCC_PLLSOURCE(RCC_OscInitStruct->PLL.PLLSource));
        assert_param(IS_RCC_PLL_MUL(RCC_OscInitStruct->PLL.PLLMUL));

        __HAL_RCC_PLL_DISABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        if (RCC_OscInitStruct->PLL.PLLSource == RCC_PLLSOURCE_HSE)
        {

          assert_param(IS_RCC_HSE_PREDIV(RCC_OscInitStruct->HSEPredivValue));
#if defined(RCC_CFGR2_PREDIV1SRC)
          assert_param(IS_RCC_PREDIV1_SOURCE(RCC_OscInitStruct->Prediv1Source));

          SET_BIT(RCC->CFGR2, RCC_OscInitStruct->Prediv1Source);
#endif

          __HAL_RCC_HSE_PREDIV_CONFIG(RCC_OscInitStruct->HSEPredivValue);
        }

        __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLSource,
                             RCC_OscInitStruct->PLL.PLLMUL);

        __HAL_RCC_PLL_ENABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  == RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {

        __HAL_RCC_PLL_DISABLE();

        tickstart = HAL_GetTick();

        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    else
    {

      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_OFF)
      {
        return HAL_ERROR;
      }
      else
      {

        pll_config = RCC->CFGR;
        if ((READ_BIT(pll_config, RCC_CFGR_PLLSRC) != RCC_OscInitStruct->PLL.PLLSource) ||
            (READ_BIT(pll_config, RCC_CFGR_PLLMULL) != RCC_OscInitStruct->PLL.PLLMUL))
        {
          return HAL_ERROR;
        }
      }
    }
  }

  return HAL_OK;
}

HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency)
{
  uint32_t tickstart;

  if (RCC_ClkInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_RCC_CLOCKTYPE(RCC_ClkInitStruct->ClockType));
  assert_param(IS_FLASH_LATENCY(FLatency));

#if defined(FLASH_ACR_LATENCY)

  if (FLatency > __HAL_FLASH_GET_LATENCY())
  {

    __HAL_FLASH_SET_LATENCY(FLatency);

    if (__HAL_FLASH_GET_LATENCY() != FLatency)
  {
    return HAL_ERROR;
  }
}

#endif

if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_HCLK) == RCC_CLOCKTYPE_HCLK)
  {

    if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
    {
      MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_HCLK_DIV16);
    }

    if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
    {
      MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, (RCC_HCLK_DIV16 << 3));
    }

    assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_ClkInitStruct->AHBCLKDivider);
  }

  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK)
  {
    assert_param(IS_RCC_SYSCLKSOURCE(RCC_ClkInitStruct->SYSCLKSource));

    if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_HSE)
    {

      if (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
      {
        return HAL_ERROR;
      }
    }

    else if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {

      if (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY) == RESET)
      {
        return HAL_ERROR;
      }
    }

    else
    {

      if (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
      {
        return HAL_ERROR;
      }
    }
    __HAL_RCC_SYSCLK_CONFIG(RCC_ClkInitStruct->SYSCLKSource);

    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_SYSCLK_SOURCE() != (RCC_ClkInitStruct->SYSCLKSource << RCC_CFGR_SWS_Pos))
    {
      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }

#if defined(FLASH_ACR_LATENCY)

  if (FLatency < __HAL_FLASH_GET_LATENCY())
  {

    __HAL_FLASH_SET_LATENCY(FLatency);

    if (__HAL_FLASH_GET_LATENCY() != FLatency)
  {
    return HAL_ERROR;
  }
}
#endif

if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB1CLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_ClkInitStruct->APB1CLKDivider);
  }

  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB2CLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, ((RCC_ClkInitStruct->APB2CLKDivider) << 3));
  }

  SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos];

  HAL_InitTick(uwTickPrio);

  return HAL_OK;
}

void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv)
{
  GPIO_InitTypeDef gpio = {0U};

  assert_param(IS_RCC_MCO(RCC_MCOx));
  assert_param(IS_RCC_MCODIV(RCC_MCODiv));
  assert_param(IS_RCC_MCO1SOURCE(RCC_MCOSource));

  UNUSED(RCC_MCOx);
  UNUSED(RCC_MCODiv);

  gpio.Mode      = GPIO_MODE_AF_PP;
  gpio.Speed     = GPIO_SPEED_FREQ_HIGH;
  gpio.Pull      = GPIO_NOPULL;
  gpio.Pin       = MCO1_PIN;

  MCO1_CLK_ENABLE();

  HAL_GPIO_Init(MCO1_GPIO_PORT, &gpio);

  __HAL_RCC_MCO1_CONFIG(RCC_MCOSource, RCC_MCODiv);
}

void HAL_RCC_EnableCSS(void)
{
  *(__IO uint32_t *) RCC_CR_CSSON_BB = (uint32_t)ENABLE;
}

void HAL_RCC_DisableCSS(void)
{
  *(__IO uint32_t *) RCC_CR_CSSON_BB = (uint32_t)DISABLE;
}

uint32_t HAL_RCC_GetSysClockFreq(void)
{
#if defined(RCC_CFGR2_PREDIV1SRC)
  static const uint8_t aPLLMULFactorTable[14U] = {0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 13};
  static const uint8_t aPredivFactorTable[16U] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
#else
  static const uint8_t aPLLMULFactorTable[16U] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 16};
#if defined(RCC_CFGR2_PREDIV1)
  static const uint8_t aPredivFactorTable[16U] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
#else
  static const uint8_t aPredivFactorTable[2U] = {1, 2};
#endif

#endif
  uint32_t tmpreg = 0U, prediv = 0U, pllclk = 0U, pllmul = 0U;
  uint32_t sysclockfreq = 0U;
#if defined(RCC_CFGR2_PREDIV1SRC)
  uint32_t prediv2 = 0U, pll2mul = 0U;
#endif

  tmpreg = RCC->CFGR;

  switch (tmpreg & RCC_CFGR_SWS)
  {
    case RCC_SYSCLKSOURCE_STATUS_HSE:
    {
      sysclockfreq = HSE_VALUE;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_PLLCLK:
    {
      pllmul = aPLLMULFactorTable[(uint32_t)(tmpreg & RCC_CFGR_PLLMULL) >> RCC_CFGR_PLLMULL_Pos];
      if ((tmpreg & RCC_CFGR_PLLSRC) != RCC_PLLSOURCE_HSI_DIV2)
      {
#if defined(RCC_CFGR2_PREDIV1)
        prediv = aPredivFactorTable[(uint32_t)(RCC->CFGR2 & RCC_CFGR2_PREDIV1) >> RCC_CFGR2_PREDIV1_Pos];
#else
        prediv = aPredivFactorTable[(uint32_t)(RCC->CFGR & RCC_CFGR_PLLXTPRE) >> RCC_CFGR_PLLXTPRE_Pos];
#endif
#if defined(RCC_CFGR2_PREDIV1SRC)

        if (HAL_IS_BIT_SET(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC))
        {

          prediv2 = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> RCC_CFGR2_PREDIV2_Pos) + 1;
          pll2mul = ((RCC->CFGR2 & RCC_CFGR2_PLL2MUL) >> RCC_CFGR2_PLL2MUL_Pos) + 2;
          pllclk = (uint32_t)(((uint64_t)HSE_VALUE * (uint64_t)pll2mul * (uint64_t)pllmul) / ((uint64_t)prediv2 * (uint64_t)prediv));
        }
        else
        {

          pllclk = (uint32_t)((HSE_VALUE * pllmul) / prediv);
        }

        if (pllmul == aPLLMULFactorTable[(uint32_t)(RCC_CFGR_PLLMULL6_5) >> RCC_CFGR_PLLMULL_Pos])
        {
          pllclk = pllclk / 2;
        }
#else

        pllclk = (uint32_t)((HSE_VALUE  * pllmul) / prediv);
#endif
      }
      else
      {

        pllclk = (uint32_t)((HSI_VALUE >> 1) * pllmul);
      }
      sysclockfreq = pllclk;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_HSI:
    default:
    {
      sysclockfreq = HSI_VALUE;
      break;
    }
  }
  return sysclockfreq;
}

uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return SystemCoreClock;
}

uint32_t HAL_RCC_GetPCLK1Freq(void)
{

  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos]);
}

uint32_t HAL_RCC_GetPCLK2Freq(void)
{

  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos]);
}

void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{

  assert_param(RCC_OscInitStruct != NULL);

  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI  \
                                      | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI;

#if defined(RCC_CFGR2_PREDIV1SRC)

  RCC_OscInitStruct->Prediv1Source = READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC);
#endif

  if ((RCC->CR & RCC_CR_HSEBYP) == RCC_CR_HSEBYP)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_BYPASS;
  }
  else if ((RCC->CR & RCC_CR_HSEON) == RCC_CR_HSEON)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_ON;
  }
  else
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_OFF;
  }
  RCC_OscInitStruct->HSEPredivValue = __HAL_RCC_HSE_GET_PREDIV();

  if ((RCC->CR & RCC_CR_HSION) == RCC_CR_HSION)
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_ON;
  }
  else
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_OFF;
  }

  RCC_OscInitStruct->HSICalibrationValue = (uint32_t)((RCC->CR & RCC_CR_HSITRIM) >> RCC_CR_HSITRIM_Pos);

  if ((RCC->BDCR & RCC_BDCR_LSEBYP) == RCC_BDCR_LSEBYP)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_BYPASS;
  }
  else if ((RCC->BDCR & RCC_BDCR_LSEON) == RCC_BDCR_LSEON)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_ON;
  }
  else
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_OFF;
  }

  if ((RCC->CSR & RCC_CSR_LSION) == RCC_CSR_LSION)
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_ON;
  }
  else
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_OFF;
  }

  if ((RCC->CR & RCC_CR_PLLON) == RCC_CR_PLLON)
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_OFF;
  }
  RCC_OscInitStruct->PLL.PLLSource = (uint32_t)(RCC->CFGR & RCC_CFGR_PLLSRC);
  RCC_OscInitStruct->PLL.PLLMUL = (uint32_t)(RCC->CFGR & RCC_CFGR_PLLMULL);
#if defined(RCC_CR_PLL2ON)

  if ((RCC->CR & RCC_CR_PLL2ON) == RCC_CR_PLL2ON)
  {
    RCC_OscInitStruct->PLL2.PLL2State = RCC_PLL2_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL2.PLL2State = RCC_PLL2_OFF;
  }
  RCC_OscInitStruct->PLL2.HSEPrediv2Value = __HAL_RCC_HSE_GET_PREDIV2();
  RCC_OscInitStruct->PLL2.PLL2MUL = (uint32_t)(RCC->CFGR2 & RCC_CFGR2_PLL2MUL);
#endif
}

void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
{

  assert_param(RCC_ClkInitStruct != NULL);
  assert_param(pFLatency != NULL);

  RCC_ClkInitStruct->ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

  RCC_ClkInitStruct->SYSCLKSource = (uint32_t)(RCC->CFGR & RCC_CFGR_SW);

  RCC_ClkInitStruct->AHBCLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_HPRE);

  RCC_ClkInitStruct->APB1CLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_PPRE1);

  RCC_ClkInitStruct->APB2CLKDivider = (uint32_t)((RCC->CFGR & RCC_CFGR_PPRE2) >> 3);

#if   defined(FLASH_ACR_LATENCY)

  *pFLatency = (uint32_t)(FLASH->ACR & FLASH_ACR_LATENCY);
#else

  *pFLatency = (uint32_t)FLASH_LATENCY_0;
#endif
}

void HAL_RCC_NMI_IRQHandler(void)
{

  if (__HAL_RCC_GET_IT(RCC_IT_CSS))
  {

    HAL_RCC_CSSCallback();

    __HAL_RCC_CLEAR_IT(RCC_IT_CSS);
  }
}

static void RCC_Delay(uint32_t mdelay)
{
  __IO uint32_t Delay = mdelay * (SystemCoreClock / 8U / 1000U);
  do
  {
    __NOP();
  }
  while (Delay --);
}

__weak void HAL_RCC_CSSCallback(void)
{

}

#endif

