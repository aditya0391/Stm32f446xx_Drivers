/*
 * main.c
 *
 *  Created on: Mar 15, 2026
 *      Author: Admin
 */


#include "Stm32f446xx.h"
#include "Stm32f446xx_Gpio.h"

/*************************************************************************************
 * @function Name          - GPIO_INIT
 *
 * @Brief                  - This Function enables or Disables the Peripheral Clock for the given GPIO port
 *
 * @Param[in]              - base of address of GPIO peripheral
 * @Param[in]              - enable or disable status
 * @Param[in]              - None
 * @Return                 - None
 *
 * @Note                   - None
 *
 *************************************************************************************/

void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status)
{
     if (status == ENABLE)
     {
    	  if(pGPIOx == GPIOA)
    	  {
    	 	  GPIOA_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOB)
    	  {
    		  GPIOB_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOC)
    	  {
    		  GPIOC_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOD)
    	  {
    		  GPIOD_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOE)
    	  {
    		  GPIOE_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOF)
    	  {
    		  GPIOF_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOG)
    	  {
    		  GPIOG_CLK_EN();
    	  }
    	  else if (pGPIOx == GPIOH)
    	  {
    		  GPIOH_CLK_EN();
    	  }
     }
     else
     {
    	 if(pGPIOx == GPIOA)
         {
    	      GPIOA_CLK_DIS();
         }
         else if (pGPIOx == GPIOB)
         {
          GPIOB_CLK_DIS();
         }
         else if (pGPIOx == GPIOC)
         {
          GPIOC_CLK_DIS();
         }
         else if (pGPIOx == GPIOD)
         {
          GPIOD_CLK_DIS();
         }
         else if (pGPIOx == GPIOE)
         {
          GPIOE_CLK_DIS();
         }
         else if (pGPIOx == GPIOF)
         {
          GPIOF_CLK_DIS();
         }
         else if (pGPIOx == GPIOG)
         {
          GPIOG_CLK_DIS();
         }
         else if (pGPIOx == GPIOH)
         {
          GPIOH_CLK_DIS();
         }
     }
}

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
	uint32_t temp = 0;
	uint32_t temp3 = 0;
	uint32_t temp4 = 0;

	GPIO_PeriClkCtrl(pGPIO_Handle->pGPIOx, ENABLE);

	//1. configure the mode of GPIO pin
    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
    	/*since each pin take 2 bit fields*/
    	temp = (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    	pGPIO_Handle->pGPIOx->MODER &= ~( 0x3 << (2 * pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    	pGPIO_Handle->pGPIOx->MODER |= temp;

    	temp = 0;
    }
    else
    {
        // interrupt mode
    	if (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
    	{
    		// Clear the RTSR Bit corresponding to the pin number
    		EXTI->RTSR &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    		// Configure the FTSR Falling trigger selection register
    		EXTI->FTSR |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    	}
    	else if (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
    	{
    		// Clear the FTSR Bit corresponding to the pin number
    		EXTI->FTSR &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    		// Configure the RTSR Rising trigger selection register
    		EXTI->RTSR |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    	}
    	else if (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
    	{
    		// Configure the RTSR & FTSR
    		EXTI->RTSR |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    		EXTI->FTSR |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    	}
    	// configure the GPIO Port selection in SYSCFG_EXTICR
    	SYSCFG_CLK_EN();
    	temp3 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber / 4;
    	temp4 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber % 4;
    	SYSCFG->EXTICR[temp3] = 1 << (temp4 * 4);

    	uint8_t portcode = GPIOxPORT(pGPIO_Handle->pGPIOx);
    	//enable the EXTI interrupt delivery using IMR Interrupt Mask Register
    	EXTI->IMR |= (portcode << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    }
    temp = 0;

	//2. configure the speed
    temp = ((pGPIO_Handle->GPIO_PinConfig.GPIO_PinSpeed << 2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->OSPEEDER &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->OSPEEDER |= temp;
    temp = 0;

	//3. configure the pupd settings
    temp = ((pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl << 2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->PUPDR |= temp;
    temp = 0;

	//4. configure the optype
    temp = pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPType;
    pGPIO_Handle->pGPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIO_Handle->pGPIOx->OTYPER |= temp;


    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
    	//5. configure the alternate functionality
        uint8_t temp1, temp2;
        temp1 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIO_Handle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
        pGPIO_Handle->pGPIOx->AFR[temp1] |= (pGPIO_Handle->GPIO_PinConfig.GPIO_PinAltFuncMode << (4 * temp2));
    }
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	  if(pGPIOx == GPIOA)
	  {
	 	  GPIOA_REG_RESET();
	  }
	  else if (pGPIOx == GPIOB)
	  {
		  GPIOB_REG_RESET();
	  }
	  else if (pGPIOx == GPIOC)
	  {
		  GPIOC_REG_RESET();
	  }
	  else if (pGPIOx == GPIOD)
	  {
		  GPIOD_REG_RESET();
	  }
	  else if (pGPIOx == GPIOE)
	  {
		  GPIOE_REG_RESET();
	  }
	  else if (pGPIOx == GPIOF)
	  {
		  GPIOF_REG_RESET();
	  }
	  else if (pGPIOx == GPIOG)
	  {
		  GPIOG_REG_RESET();
	  }
	  else if (pGPIOx == GPIOH)
	  {
		  GPIOH_REG_RESET();
	  }
}


uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint16_t Value)
{
	if (Value == GPIO_PIN_SET)
	{
		//Write 1 to the Output Data Register at the bit field corresponding to the pin number
		pGPIOx->ODR |= 1 << PinNumber;
	}
	else
	{
		//write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

void GPIO_IRQInterruptConfig(uint8_t IRQ_Number, uint8_t status) /*To do IRQ configuration*/
{
    if(status == ENABLE)
    {
    	if (IRQ_Number <= 31)
    	{
    		// Program ISER0 register
    		*NVIC_ISER0 |= 1 << IRQ_Number;
    	}
    	else if (IRQ_Number > 31 && IRQ_Number < 64)
    	{
    		// Program ISER1 register
    		*NVIC_ISER1 |= 1 << (IRQ_Number % 32);
    	}
    	else if (IRQ_Number >= 65 && IRQ_Number < 96)
    	{
    		// Program ISER2 register
    		*NVIC_ISER2 |= 1 << (IRQ_Number % 64);
    	}

    }
    else
    {
    	if (IRQ_Number <= 31)
    	{
    	    // Program ICER0 register
    		*NVIC_ICER0 |= 1 << IRQ_Number;
    	}
    	else if (IRQ_Number > 31 && IRQ_Number < 64)
    	{
    	    // Program ICER1 register
    		*NVIC_ICER1 |= 1 << (IRQ_Number % 32);
    	}
    	else if (IRQ_Number >= 65 && IRQ_Number < 96)
    	{
    		// Program ICER2 register
    		*NVIC_ICER2 |= 1 << (IRQ_Number % 64);
    	}
    }
}

void GPIO_IRQPriorityConfig(uint8_t IRQPriority)
{
    uint8_t iprx = IRQPriority / 4;
    uint8_t iprx_section = IRQPriority % 4;
    uint8_t shift_amount = (iprx_section * 8) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_IPR + (iprx * 4)) |= IRQPriority << shift_amount ;
}
void GPIO_IRQHandling(uint8_t PinNumber) /*To do IRQ Handling*/
{
	//Clear the EXTI Pending Register corresponding to the pin number
    if (EXTI->PR & (1 << PinNumber))
    {
    	EXTI->PR |= (1 << PinNumber);
    }
}
