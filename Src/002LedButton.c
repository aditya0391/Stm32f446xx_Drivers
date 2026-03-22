#include "Stm32f446xx_Gpio.h"
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

		GpioBtn.pGPIOx = GPIOC;
		GpioLED.pGPIOx = GPIOA;
		GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
		GpioLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
		GpioLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GpioLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

		GPIO_PeriClkCtrl(GPIOC, ENABLE);
		GPIO_PeriClkCtrl(GPIOA, ENABLE);
		GPIO_Init(&GpioBtn);
		GPIO_Init(&GpioLED);

		while(1)
		    {
			    if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_13) == BTN_PRESSED)
			    {
			    	delay();
			    	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
			    }
		    }

		return 0;
}
