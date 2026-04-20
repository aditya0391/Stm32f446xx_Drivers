/*
 * Pwm_test.c
 *
 *  Created on: Apr 20, 2026
 *      Author: Aditya Vilayatkar
 */
#include "Stm32f446xx.h"


int main(void)
{
	/* GPIO and TIM Clock enable*/
	TIM9_CLK_EN();

	/* GPIOA configuration for LED */

	GPIO_Handle_t Gpio_led;

	Gpio_led.pGPIOx = GPIOA;
	Gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	Gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpio_led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&Gpio_led);

	GPIO_Handle_t Gpio_timer;

	/* GPIOA configuration for Timer */

	Gpio_timer.pGPIOx = GPIOA;
	Gpio_timer.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	Gpio_timer.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	Gpio_timer.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpio_timer.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpio_timer.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Gpio_timer.GPIO_PinConfig.GPIO_PinAltFuncMode = 3;

	GPIO_Init(&Gpio_timer);

    return 0;
}
