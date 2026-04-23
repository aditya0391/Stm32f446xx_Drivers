/*
 * Pwm_test.c
 *
 *  Created on: Apr 20, 2026
 *      Author: Aditya Vilayatkar
 */
#include "Stm32f446xx.h"
#include <string.h>
uint16_t onTime = 100U;

void EXTI15_10_IRQHandler(void);
int main(void)
{
	/* GPIO and TIM Clock enable*/
	GPIO_Handle_t Gpio_led;
	GPIO_Handle_t GpioBtn;

	memset(&Gpio_led,0,sizeof(Gpio_led));
	memset(&GpioBtn,0,sizeof(GpioBtn));

	TIM6_CLK_EN();
	uint16_t max_cnt = 0;

	/* GPIOA configuration for LED */

	Gpio_led.pGPIOx = GPIOA;
	Gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	Gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpio_led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&Gpio_led);

	GpioBtn.pGPIOx = GPIOC;

	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
	GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GPIO_Init(&GpioBtn);

	TIM6->PSC = 99U;
	TIM6->ARR = 1199U;
	TIM6->CR1 |= (1 << 0);
	/* Di1vide 90 MHz by 9000 → 10 kHz tick */
	//TIM9->ARR = 999;             /* Counter will reset every 1000 ticks*/

	GPIO_IRQInterruptConfig(IRQ_NUMBER_EXTI15_10, ENABLE);
	GPIO_IRQPriorityConfig(IRQ_NUMBER_EXTI15_10, IRQ_PRIO_9);

	while(1)
	{

	    if (TIM6->CNT <= onTime)
	    {
		    GPIO_WriteToOutputPin(GPIOA, 5,1);
	    }
	    else
	    {
		    GPIO_WriteToOutputPin(GPIOA, 5,0);
	    }

	    if(TIM6->CNT > max_cnt)
	    {
	    	max_cnt = TIM6->CNT;
	    }

	}
    return 0;
}

void EXTI15_10_IRQHandler()
	{
		GPIO_IRQHandling(GPIO_PIN_13);
		onTime += 100U ;
	}
