/*
 * user_button_interrupt.c
 *
 *  Created on: Apr 3, 2026
 *      Author: Aditya Vilayatkar
 */

#include "Stm32f446xx_Gpio.h"
#define LOW 0U
#define BTN_PRESSED LOW

void EXTI15_10_IRQHandler(void);

void delay (void)
{
	for(uint32_t i = 0; i <500000/2; i++);
}

int main(void)
{
	GPIO_Handle_t GpioBtn;
	GPIO_Handle_t GpioLED;

		GpioBtn.pGPIOx = GPIOC;
		GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
		GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_RFT;
		GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
		GPIO_Init(&GpioBtn);

		GpioLED.pGPIOx = GPIOA;
		GpioLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		GpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GpioLED);

		// IRQ Configurations

		GPIO_IRQPriorityConfig(IRQ_NUMBER_EXTI15_10, IRQ_PRIO_10);
		GPIO_IRQInterruptConfig(IRQ_NUMBER_EXTI15_10, ENABLE);

//		while(1)
//		    {
//			    if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_13) == BTN_PRESSED)
//			    {
//			    	EXTI15_10_IRQHandler();
//			    }
//		    }
		while(1);

}


void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_13);
	delay();
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
}
