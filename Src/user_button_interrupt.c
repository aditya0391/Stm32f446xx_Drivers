/*
 * user_button_interrupt.c
 *
 *  Created on: Apr 3, 2026
 *      Author: Aditya Vilayatkar
 */

#include "Stm32f446xx_Gpio.h"
#include <string.h>
#define LOW 0U
#define BTN_PRESSED LOW


void delay (void)
{
	for(uint32_t i = 0; i <500000/2; i++);
}

int main(void)
{
	GPIO_Handle_t GpioBtn;
	GPIO_Handle_t GpioLED;



		memset(&GpioLED,0,sizeof(GpioLED));
		memset(&GpioBtn,0,sizeof(GpioBtn));

		GpioBtn.pGPIOx = GPIOC;
		GpioLED.pGPIOx = GPIOA;

		GpioLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		GpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GpioLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIO_Init(&GpioLED);

		GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
		GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
		GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
		//GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
		GPIO_Init(&GpioBtn);

		// IRQ Configurations


		GPIO_IRQInterruptConfig(IRQ_NUMBER_EXTI15_10, ENABLE);
		GPIO_IRQPriorityConfig(IRQ_NUMBER_EXTI15_10, IRQ_PRIO_9);



//		while(1)
//		    {
//			    if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_13) == BTN_PRESSED)
//			    {
//			    	EXTI15_10_IRQHandler();
//			    }
//		    }
		while(1);

}


void EXTI15_10_IRQHandler()
{
	GPIO_IRQHandling(GPIO_PIN_13);
	delay();
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
}
