#include "stm32f1xx_hal.h"

#ifdef HAL_RCC_MODULE_ENABLED

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  uint32_t tickstart = 0U, temp_reg = 0U;
#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t  pllactive = 0U;
#endif

  assert_param(IS_RCC_PERIPHCLOCK(PeriphClkInit->PeriphClockSelection));

  if ((((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC))
  {
    FlagStatus pwrclkchanged = RESET;

    assert_param(IS_RCC_RTCCLKSOURCE(PeriphClkInit->RTCClockSelection));

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

    temp_reg = (RCC->BDCR & RCC_BDCR_RTCSEL);
    if ((temp_reg != 0x00000000U) && (temp_reg != (PeriphClkInit->RTCClockSelection & RCC_BDCR_RTCSEL)))
    {

      temp_reg = (RCC->BDCR & ~(RCC_BDCR_RTCSEL));

      __HAL_RCC_BACKUPRESET_FORCE();
      __HAL_RCC_BACKUPRESET_RELEASE();

      RCC->BDCR = temp_reg;

      if (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSEON))
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
    }
    __HAL_RCC_RTC_CONFIG(PeriphClkInit->RTCClockSelection);

    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }

  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)
  {

    assert_param(IS_RCC_ADCPLLCLK_DIV(PeriphClkInit->AdcClockSelection));

    __HAL_RCC_ADC_CONFIG(PeriphClkInit->AdcClockSelection);
  }

#if defined(STM32F105xC) || defined(STM32F107xC)

  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2S2) == RCC_PERIPHCLK_I2S2)
  {

    assert_param(IS_RCC_I2S2CLKSOURCE(PeriphClkInit->I2s2ClockSelection));

    __HAL_RCC_I2S2_CONFIG(PeriphClkInit->I2s2ClockSelection);
  }

  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2S3) == RCC_PERIPHCLK_I2S3)
  {

    assert_param(IS_RCC_I2S3CLKSOURCE(PeriphClkInit->I2s3ClockSelection));

    __HAL_RCC_I2S3_CONFIG(PeriphClkInit->I2s3ClockSelection);
  }

  if (HAL_IS_BIT_SET(RCC->CFGR2, RCC_CFGR2_I2S2SRC) || HAL_IS_BIT_SET(RCC->CFGR2, RCC_CFGR2_I2S3SRC))
  {

    pllactive = 1;
  }

  if (pllactive == 1)
  {

    if (HAL_IS_BIT_CLR(RCC->CR, RCC_CR_PLL3ON))
    {

      assert_param(IS_RCC_PLLI2S_MUL(PeriphClkInit->PLLI2S.PLLI2SMUL));
      assert_param(IS_RCC_HSE_PREDIV2(PeriphClkInit->PLLI2S.HSEPrediv2Value));

      if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLL2ON) && \
          (__HAL_RCC_HSE_GET_PREDIV2() != PeriphClkInit->PLLI2S.HSEPrediv2Value))
      {
        return HAL_ERROR;
      }

      __HAL_RCC_HSE_PREDIV2_CONFIG(PeriphClkInit->PLLI2S.HSEPrediv2Value);

      __HAL_RCC_PLLI2S_CONFIG(PeriphClkInit->PLLI2S.PLLI2SMUL);

      __HAL_RCC_PLLI2S_ENABLE();

      tickstart = HAL_GetTick();

      while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLI2SRDY)  == RESET)
      {
        if ((HAL_GetTick() - tickstart) > PLLI2S_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {

      if (READ_BIT(RCC->CFGR2, RCC_CFGR2_PLL3MUL) != PeriphClkInit->PLLI2S.PLLI2SMUL)
      {
        return HAL_ERROR;
      }
    }
  }
#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)

  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USB) == RCC_PERIPHCLK_USB)
  {

    assert_param(IS_RCC_USBPLLCLK_DIV(PeriphClkInit->UsbClockSelection));

    __HAL_RCC_USB_CONFIG(PeriphClkInit->UsbClockSelection);
  }
#endif

  return HAL_OK;
}

void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  uint32_t srcclk = 0U;

  PeriphClkInit->PeriphClockSelection = RCC_PERIPHCLK_RTC;

  srcclk = __HAL_RCC_GET_RTC_SOURCE();

  PeriphClkInit->RTCClockSelection = srcclk;

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_ADC;
  PeriphClkInit->AdcClockSelection = __HAL_RCC_GET_ADC_SOURCE();

#if defined(STM32F105xC) || defined(STM32F107xC)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2S2;
  PeriphClkInit->I2s2ClockSelection = __HAL_RCC_GET_I2S2_SOURCE();

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2S3;
  PeriphClkInit->I2s3ClockSelection = __HAL_RCC_GET_I2S3_SOURCE();

#endif

#if defined(STM32F103xE) || defined(STM32F103xG)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2S2;
  PeriphClkInit->I2s2ClockSelection = RCC_I2S2CLKSOURCE_SYSCLK;

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_I2S3;
  PeriphClkInit->I2s3ClockSelection = RCC_I2S3CLKSOURCE_SYSCLK;

#endif

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)

  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_USB;
  PeriphClkInit->UsbClockSelection = __HAL_RCC_GET_USB_SOURCE();
#endif
}

uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk)
{
#if defined(STM32F105xC) || defined(STM32F107xC)
  static const uint8_t aPLLMULFactorTable[14U] = {0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 13};
  static const uint8_t aPredivFactorTable[16U] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

  uint32_t prediv1 = 0U, pllclk = 0U, pllmul = 0U;
  uint32_t pll2mul = 0U, pll3mul = 0U, prediv2 = 0U;
#endif
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6) || \
    defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
  static const uint8_t aPLLMULFactorTable[16U] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 16};
  static const uint8_t aPredivFactorTable[2U] = {1, 2};

  uint32_t prediv1 = 0U, pllclk = 0U, pllmul = 0U;
#endif
  uint32_t temp_reg = 0U, frequency = 0U;

  assert_param(IS_RCC_PERIPHCLOCK(PeriphClk));

  switch (PeriphClk)
  {
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
    case RCC_PERIPHCLK_USB:
    {

      temp_reg = RCC->CFGR;

      if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLON))
      {
        pllmul = aPLLMULFactorTable[(uint32_t)(temp_reg & RCC_CFGR_PLLMULL) >> RCC_CFGR_PLLMULL_Pos];
        if ((temp_reg & RCC_CFGR_PLLSRC) != RCC_PLLSOURCE_HSI_DIV2)
        {
#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
          prediv1 = aPredivFactorTable[(uint32_t)(RCC->CFGR2 & RCC_CFGR2_PREDIV1) >> RCC_CFGR2_PREDIV1_Pos];
#else
          prediv1 = aPredivFactorTable[(uint32_t)(RCC->CFGR & RCC_CFGR_PLLXTPRE) >> RCC_CFGR_PLLXTPRE_Pos];
#endif

#if defined(STM32F105xC) || defined(STM32F107xC)
          if (HAL_IS_BIT_SET(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC))
          {

            prediv2 = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> RCC_CFGR2_PREDIV2_Pos) + 1;
            pll2mul = ((RCC->CFGR2 & RCC_CFGR2_PLL2MUL) >> RCC_CFGR2_PLL2MUL_Pos) + 2;
            pllclk = (uint32_t)((((HSE_VALUE / prediv2) * pll2mul) / prediv1) * pllmul);
          }
          else
          {

            pllclk = (uint32_t)((HSE_VALUE / prediv1) * pllmul);
          }

          if (pllmul == aPLLMULFactorTable[(uint32_t)(RCC_CFGR_PLLMULL6_5) >> RCC_CFGR_PLLMULL_Pos])
          {
            pllclk = pllclk / 2;
          }
#else
          if ((temp_reg & RCC_CFGR_PLLSRC) != RCC_PLLSOURCE_HSI_DIV2)
          {

            pllclk = (uint32_t)((HSE_VALUE / prediv1) * pllmul);
          }
#endif
        }
        else
        {

          pllclk = (uint32_t)((HSI_VALUE >> 1) * pllmul);
        }

#if defined(STM32F105xC) || defined(STM32F107xC)

        if (__HAL_RCC_GET_USB_SOURCE() == RCC_USBCLKSOURCE_PLL_DIV2)
        {

          frequency = pllclk;
        }
        else
        {

          frequency = (2 * pllclk) / 3;
        }
#else

        if (__HAL_RCC_GET_USB_SOURCE() == RCC_USBCLKSOURCE_PLL)
        {

          frequency = pllclk;
        }
        else
        {

          frequency = (pllclk * 2) / 3;
        }
#endif
      }
      break;
    }
#endif
#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
    case RCC_PERIPHCLK_I2S2:
    {
#if defined(STM32F103xE) || defined(STM32F103xG)

      frequency = HAL_RCC_GetSysClockFreq();
#else
      if (__HAL_RCC_GET_I2S2_SOURCE() == RCC_I2S2CLKSOURCE_SYSCLK)
      {

        frequency = HAL_RCC_GetSysClockFreq();
      }
      else
      {

        if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLL3ON))
        {

          prediv2 = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> RCC_CFGR2_PREDIV2_Pos) + 1;
          pll3mul = ((RCC->CFGR2 & RCC_CFGR2_PLL3MUL) >> RCC_CFGR2_PLL3MUL_Pos) + 2;
          frequency = (uint32_t)(2 * ((HSE_VALUE / prediv2) * pll3mul));
        }
      }
#endif
      break;
    }
    case RCC_PERIPHCLK_I2S3:
    {
#if defined(STM32F103xE) || defined(STM32F103xG)

      frequency = HAL_RCC_GetSysClockFreq();
#else
      if (__HAL_RCC_GET_I2S3_SOURCE() == RCC_I2S3CLKSOURCE_SYSCLK)
      {

        frequency = HAL_RCC_GetSysClockFreq();
      }
      else
      {

        if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLL3ON))
        {

          prediv2 = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> RCC_CFGR2_PREDIV2_Pos) + 1;
          pll3mul = ((RCC->CFGR2 & RCC_CFGR2_PLL3MUL) >> RCC_CFGR2_PLL3MUL_Pos) + 2;
          frequency = (uint32_t)(2 * ((HSE_VALUE / prediv2) * pll3mul));
        }
      }
#endif
      break;
    }
#endif
    case RCC_PERIPHCLK_RTC:
    {

      temp_reg = RCC->BDCR;

      if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_LSE) && (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }

      else if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_LSI) && (HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)))
      {
        frequency = LSI_VALUE;
      }
      else if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_HSE_DIV128) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSERDY)))
      {
        frequency = HSE_VALUE / 128U;
      }

      else
      {

      }
      break;
    }
    case RCC_PERIPHCLK_ADC:
    {
      frequency = HAL_RCC_GetPCLK2Freq() / (((__HAL_RCC_GET_ADC_SOURCE() >> RCC_CFGR_ADCPRE_Pos) + 1) * 2);
      break;
    }
    default:
    {
      break;
    }
  }
  return (frequency);
}

#if defined(STM32F105xC) || defined(STM32F107xC)

HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit)
{
  uint32_t tickstart = 0U;

  if (HAL_IS_BIT_CLR(RCC->CFGR2, RCC_CFGR2_I2S2SRC) && HAL_IS_BIT_CLR(RCC->CFGR2, RCC_CFGR2_I2S3SRC))
  {

    assert_param(IS_RCC_PLLI2S_MUL(PLLI2SInit->PLLI2SMUL));
    assert_param(IS_RCC_HSE_PREDIV2(PLLI2SInit->HSEPrediv2Value));

    if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLL2ON) && \
        (__HAL_RCC_HSE_GET_PREDIV2() != PLLI2SInit->HSEPrediv2Value))
    {
      return HAL_ERROR;
    }

    __HAL_RCC_PLLI2S_DISABLE();

    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLI2SRDY)  != RESET)
    {
      if ((HAL_GetTick() - tickstart) > PLLI2S_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }

    __HAL_RCC_HSE_PREDIV2_CONFIG(PLLI2SInit->HSEPrediv2Value);

    __HAL_RCC_PLLI2S_CONFIG(PLLI2SInit->PLLI2SMUL);

    __HAL_RCC_PLLI2S_ENABLE();

    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLI2SRDY)  == RESET)
    {
      if ((HAL_GetTick() - tickstart) > PLLI2S_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }
  else
  {

    return HAL_ERROR;
  }

  return HAL_OK;
}

HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void)
{
  uint32_t tickstart = 0U;

  if (HAL_IS_BIT_CLR(RCC->CFGR2, RCC_CFGR2_I2S2SRC) && HAL_IS_BIT_CLR(RCC->CFGR2, RCC_CFGR2_I2S3SRC))
  {

    __HAL_RCC_PLLI2S_DISABLE();

    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLI2SRDY)  != RESET)
    {
      if ((HAL_GetTick() - tickstart) > PLLI2S_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }
  else
  {

    return HAL_ERROR;
  }

  return HAL_OK;
}

HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(RCC_PLL2InitTypeDef  *PLL2Init)
{
  uint32_t tickstart = 0U;

  if ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE) && \
      (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && \
      ((READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC)) == RCC_CFGR2_PREDIV1SRC_PLL2))
  {
    return HAL_ERROR;
  }
  else
  {

    assert_param(IS_RCC_PLL2_MUL(PLL2Init->PLL2MUL));
    assert_param(IS_RCC_HSE_PREDIV2(PLL2Init->HSEPrediv2Value));

    if (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLL3ON) && \
        (__HAL_RCC_HSE_GET_PREDIV2() != PLL2Init->HSEPrediv2Value))
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

    __HAL_RCC_HSE_PREDIV2_CONFIG(PLL2Init->HSEPrediv2Value);

    __HAL_RCC_PLL2_CONFIG(PLL2Init->PLL2MUL);

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

  return HAL_OK;
}

HAL_StatusTypeDef HAL_RCCEx_DisablePLL2(void)
{
  uint32_t tickstart = 0U;

  if ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE) && \
      (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) && \
      ((READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1SRC)) == RCC_CFGR2_PREDIV1SRC_PLL2))
  {
    return HAL_ERROR;
  }
  else
  {

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

  return HAL_OK;
}

#endif

#endif

