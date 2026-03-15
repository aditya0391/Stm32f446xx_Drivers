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
	//1. configure the mode of GPIO pin
    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
    	/*since each pin take 2 bit fields*/
    	temp = (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    	pGPIO_Handle->pGPIOx->MODER &= ~( 0x3 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    	pGPIO_Handle->pGPIOx->MODER |= temp;

    	temp = 0;
    }
    else
    {
        // interrupt mode
    }
    temp = 0;

	//2. configure the speed
    temp = ((pGPIO_Handle->GPIO_PinConfig.GPIO_PinSpeed << 2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->OSPEEDER &= ~(0x3 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIO_Handle->pGPIOx->OSPEEDER |= temp;
    temp = 0;

	//3. configure the pupd settings
    temp = ((pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl << 2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->PUPDR &= ~(0x3 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIO_Handle->pGPIOx->PUPDR |= temp;
    temp = 0;

	//4. configure the optype
    pGPIO_Handle->pGPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIO_Handle->pGPIOx->OTYPER |= pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPType;

	//5. configure the alternate functionality
    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
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
