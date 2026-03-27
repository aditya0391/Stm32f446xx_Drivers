/*
 * Spi_echo_test.c
 *
 *  Created on: Mar 26, 2026
 *      Author: Aditya A Vilayatkar
 */

#include "Stm32f446xx.h"
#include <string.h>

/*
 * PA4    SPI1 NSS
 * PA5    SPI1 CLK
 * PA6    SPI1 MISO
 * PA7    SPI1 MOSI
 * Alt functionality mode 5
 */

void SPI_GPIOInits(void);
void SPI1_Inits(void);
void SPI_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;
	SPIPins.pGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;
	SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;  // SCLK
	GPIO_Init(&SPIPins);

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_6;  // MISO
	GPIO_Init(&SPIPins);

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_7;  // MOSI
	GPIO_Init(&SPIPins);

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;  // NSS
    GPIO_Init(&SPIPins);
}

void SPI1_Inits(void)
{
	SPI_Handle_t SPI1Handle;
	SPI1Handle.pSPIx = SPI1;
	SPI1Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1Handle.SPIConfig.SPI_DeviceMode =SPI_DEVICE_MODE_MASTER;
	SPI1Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;
	SPI1Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI1Handle.SPIConfig.SPI_SSM  = SPI_SSM_ENABLE;
    SPI_Init(&SPI1Handle);
}


int main (void)
{
	char user_data[] = "Aditya";
	char received_data[50];

	SPI_GPIOInits();

	SPI1_Inits();

	SPI_SSIConfig(SPI1, ENABLE);

	// enable the spi1 peripheral
	SPI_PerpheralControl(SPI1, ENABLE);

	SPI_SendData(SPI1, (uint8_t*)user_data, strlen(user_data));
	SPI_ReceiveData(SPI1, (uint8_t*)received_data, strlen(received_data));

	for(;;);

	return 0;
}
