
#include "Stm32f446xx_Gpio.h"
GPIO_RegDef_t     *pGPIOx;
static uint8_t Led_status = 0;
void delay (void)
{
	for(uint32_t i = 0; i <500000; i++);
}

int main(void)
{

	GPIO_Handle_t Gpio_led;

	Gpio_led.pGPIOx = GPIOA;
	Gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	Gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpio_led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	Gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;

	GPIO_PeriClkCtrl(GPIOA, ENABLE);
	GPIO_Init(&Gpio_led);

	if (Led_status == 1)  // added this to keep LED in control during debugging
	{
	    while(1)
	    {
		    GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
		    delay();
	    }
	}





	return 0;
/*
	pGPIOx = GPIOA;
	RCC_REG->AHB1ENR |= (1 << 0);          // Enable clock for GPIOA

	// Configure PA5 as output
	GPIOA->MODER &= ~(3 << (2*5));         // Clear mode bits
	GPIOA->MODER |=  (1 << (2*5));         // Set output mode

	GPIOA->ODR &= ~(1 << 5);               // Ensure PA5 starts low

	while(1)
	{
	    GPIOA->ODR ^= (1 << 5);            // Toggle PA5
	    delay();
	}
*/
}
