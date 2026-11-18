#include "stm32f1xx_hal.h"

#ifdef HAL_FLASH_MODULE_ENABLED

FLASH_ProcessTypeDef pFlash;

static  void   FLASH_Program_HalfWord(uint32_t Address, uint16_t Data);
static  void   FLASH_SetErrorCode(void);
extern void    FLASH_PageErase(uint32_t PageAddress);

HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  uint8_t index = 0;
  uint8_t nbiterations = 0;

  __HAL_LOCK(&pFlash);

  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));
  assert_param(IS_FLASH_PROGRAM_ADDRESS(Address));

#if defined(FLASH_BANK2_END)
  if(Address <= FLASH_BANK1_END)
  {
#endif

    status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);
#if defined(FLASH_BANK2_END)
  }
  else
  {

    status = FLASH_WaitForLastOperationBank2(FLASH_TIMEOUT_VALUE);
  }
#endif

  if(status == HAL_OK)
  {
    if(TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
    {

      nbiterations = 1U;
    }
    else if(TypeProgram == FLASH_TYPEPROGRAM_WORD)
    {

      nbiterations = 2U;
    }
    else
    {

      nbiterations = 4U;
    }

    for (index = 0U; index < nbiterations; index++)
    {
      FLASH_Program_HalfWord((Address + (2U*index)), (uint16_t)(Data >> (16U*index)));

#if defined(FLASH_BANK2_END)
      if(Address <= FLASH_BANK1_END)
      {
#endif

        status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);

        CLEAR_BIT(FLASH->CR, FLASH_CR_PG);
#if defined(FLASH_BANK2_END)
      }
      else
      {

        status = FLASH_WaitForLastOperationBank2(FLASH_TIMEOUT_VALUE);

        CLEAR_BIT(FLASH->CR2, FLASH_CR2_PG);
      }
#endif

      if (status != HAL_OK)
      {
        break;
      }
    }
  }

  __HAL_UNLOCK(&pFlash);

  return status;
}

HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));
  assert_param(IS_FLASH_PROGRAM_ADDRESS(Address));

#if defined(FLASH_BANK2_END)

  if (pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
  {
    return HAL_ERROR;
  }

  if(Address <= FLASH_BANK1_END)
  {

    __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP_BANK1 | FLASH_IT_ERR_BANK1);

  }else
  {

    __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP_BANK2 | FLASH_IT_ERR_BANK2);
  }
#else

  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);
#endif

  pFlash.Address = Address;
  pFlash.Data = Data;

  if(TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMHALFWORD;

    pFlash.DataRemaining = 1U;
  }
  else if(TypeProgram == FLASH_TYPEPROGRAM_WORD)
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMWORD;

    pFlash.DataRemaining = 2U;
  }
  else
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMDOUBLEWORD;

    pFlash.DataRemaining = 4U;
  }

  FLASH_Program_HalfWord(Address, (uint16_t)Data);

  return status;
}

void HAL_FLASH_IRQHandler(void)
{
  uint32_t addresstmp = 0U;

#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK1) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK1) || \
    (__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2)))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) ||__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
#endif
  {

    addresstmp = pFlash.Address;

    pFlash.Address = 0xFFFFFFFFU;

    FLASH_SetErrorCode();

    HAL_FLASH_OperationErrorCallback(addresstmp);

    pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
  }

#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP_BANK1))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK1);
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
#endif

    if(pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
    {
      if(pFlash.ProcedureOnGoing == FLASH_PROC_PAGEERASE)
      {

        pFlash.DataRemaining--;

        if(pFlash.DataRemaining != 0U)
        {
          addresstmp = pFlash.Address;

          HAL_FLASH_EndOfOperationCallback(addresstmp);

          addresstmp = pFlash.Address + FLASH_PAGE_SIZE;
          pFlash.Address = addresstmp;

          CLEAR_BIT(FLASH->CR, FLASH_CR_PER);

          FLASH_PageErase(addresstmp);
        }
        else
        {

          pFlash.Address = addresstmp = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;

          HAL_FLASH_EndOfOperationCallback(addresstmp);
        }
      }
      else if(pFlash.ProcedureOnGoing == FLASH_PROC_MASSERASE)
      {

        CLEAR_BIT(FLASH->CR, FLASH_CR_MER);

#if defined(FLASH_BANK2_END)

        if (HAL_IS_BIT_CLR(FLASH->CR2, FLASH_CR2_MER))
        {
#endif

          HAL_FLASH_EndOfOperationCallback(0U);

          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
#if defined(FLASH_BANK2_END)
      }
#endif
      else
      {

        pFlash.DataRemaining--;

        if(pFlash.DataRemaining != 0U)
        {

          pFlash.Address += 2U;
          addresstmp = pFlash.Address;

          pFlash.Data = (pFlash.Data >> 16U);

          CLEAR_BIT(FLASH->CR, FLASH_CR_PG);

          FLASH_Program_HalfWord(addresstmp, (uint16_t)pFlash.Data);
        }
        else
        {

          if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMHALFWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address);
          }
          else if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address - 2U);
          }
          else
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address - 6U);
          }

          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
    }
  }

#if defined(FLASH_BANK2_END)

  if(__HAL_FLASH_GET_FLAG( FLASH_FLAG_EOP_BANK2))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK2);

    if(pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
    {
      if(pFlash.ProcedureOnGoing == FLASH_PROC_PAGEERASE)
      {

        pFlash.DataRemaining--;

        if(pFlash.DataRemaining != 0U)
        {

          HAL_FLASH_EndOfOperationCallback(pFlash.Address);

          pFlash.Address += FLASH_PAGE_SIZE;
          addresstmp = pFlash.Address;

          CLEAR_BIT(FLASH->CR2, FLASH_CR2_PER);

          FLASH_PageErase(addresstmp);
        }
        else
        {

          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;

          HAL_FLASH_EndOfOperationCallback(pFlash.Address);
        }
      }
      else if(pFlash.ProcedureOnGoing == FLASH_PROC_MASSERASE)
      {

        CLEAR_BIT(FLASH->CR2, FLASH_CR2_MER);

        if (HAL_IS_BIT_CLR(FLASH->CR, FLASH_CR_MER))
        {

          HAL_FLASH_EndOfOperationCallback(0U);

          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
      else
      {

        pFlash.DataRemaining--;

        if(pFlash.DataRemaining != 0U)
        {

          pFlash.Address += 2U;
          addresstmp = pFlash.Address;

          pFlash.Data = (pFlash.Data >> 16U);

          CLEAR_BIT(FLASH->CR2, FLASH_CR2_PG);

          FLASH_Program_HalfWord(addresstmp, (uint16_t)pFlash.Data);
        }
        else
        {

          if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMHALFWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address);
          }
          else if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address-2U);
          }
          else
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address-6U);
          }

          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
    }
  }
#endif

  if(pFlash.ProcedureOnGoing == FLASH_PROC_NONE)
  {
#if defined(FLASH_BANK2_END)

    CLEAR_BIT(FLASH->CR, (FLASH_CR_PG | FLASH_CR_PER | FLASH_CR_MER));
    CLEAR_BIT(FLASH->CR2, (FLASH_CR2_PG | FLASH_CR2_PER | FLASH_CR2_MER));

    __HAL_FLASH_DISABLE_IT(FLASH_IT_EOP_BANK1 | FLASH_IT_ERR_BANK1 | FLASH_IT_EOP_BANK2 | FLASH_IT_ERR_BANK2);
#else

    CLEAR_BIT(FLASH->CR, (FLASH_CR_PG | FLASH_CR_PER | FLASH_CR_MER));

    __HAL_FLASH_DISABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);
#endif

  }
}

__weak void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue)
{

  UNUSED(ReturnValue);

}

__weak void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{

  UNUSED(ReturnValue);

}

HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
  {

    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR, FLASH_KEY2);

    if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }
#if defined(FLASH_BANK2_END)
  if(READ_BIT(FLASH->CR2, FLASH_CR2_LOCK) != RESET)
  {

    WRITE_REG(FLASH->KEYR2, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR2, FLASH_KEY2);

    if(READ_BIT(FLASH->CR2, FLASH_CR2_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }
#endif

  return status;
}

HAL_StatusTypeDef HAL_FLASH_Lock(void)
{

  SET_BIT(FLASH->CR, FLASH_CR_LOCK);

#if defined(FLASH_BANK2_END)

  SET_BIT(FLASH->CR2, FLASH_CR2_LOCK);

#endif
  return HAL_OK;
}

HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void)
{
  if (HAL_IS_BIT_CLR(FLASH->CR, FLASH_CR_OPTWRE))
  {

    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY1);
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY2);
  }
  else
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}

HAL_StatusTypeDef HAL_FLASH_OB_Lock(void)
{

  CLEAR_BIT(FLASH->CR, FLASH_CR_OPTWRE);

  return HAL_OK;
}

void HAL_FLASH_OB_Launch(void)
{

  HAL_NVIC_SystemReset();
}

uint32_t HAL_FLASH_GetError(void)
{
   return pFlash.ErrorCode;
}

static void FLASH_Program_HalfWord(uint32_t Address, uint16_t Data)
{

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

#if defined(FLASH_BANK2_END)
  if(Address <= FLASH_BANK1_END)
  {
#endif

    SET_BIT(FLASH->CR, FLASH_CR_PG);
#if defined(FLASH_BANK2_END)
  }
  else
  {

    SET_BIT(FLASH->CR2, FLASH_CR2_PG);
  }
#endif

  *(__IO uint16_t*)Address = Data;
}

HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout)
{

  uint32_t tickstart = HAL_GetTick();

  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY))
  {
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    }
  }

  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
  }

  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR)  ||
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_OPTVERR) ||
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
  {

    FLASH_SetErrorCode();
    return HAL_ERROR;
  }

  return HAL_OK;
}

#if defined(FLASH_BANK2_END)

HAL_StatusTypeDef FLASH_WaitForLastOperationBank2(uint32_t Timeout)
{

  uint32_t tickstart = HAL_GetTick();

  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY_BANK2))
  {
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    }
  }

  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP_BANK2))
  {

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK2);
  }

  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2))
  {

    FLASH_SetErrorCode();
    return HAL_ERROR;
  }

  return HAL_OK;

}
#endif

static void FLASH_SetErrorCode(void)
{
  uint32_t flags = 0U;

#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR))
#endif
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_WRP;
#if defined(FLASH_BANK2_END)
    flags |= FLASH_FLAG_WRPERR | FLASH_FLAG_WRPERR_BANK2;
#else
    flags |= FLASH_FLAG_WRPERR;
#endif
  }
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
#endif
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PROG;
#if defined(FLASH_BANK2_END)
    flags |= FLASH_FLAG_PGERR | FLASH_FLAG_PGERR_BANK2;
#else
    flags |= FLASH_FLAG_PGERR;
#endif
  }
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_OPTVERR))
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_OPTV;
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);
  }

  __HAL_FLASH_CLEAR_FLAG(flags);
}

#endif

