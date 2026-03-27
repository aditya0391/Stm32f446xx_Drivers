/*
 * Spi_Tx.c
 *
 *  Created on: Mar 24, 2026
 *      Author: Aditya A Vilayatkar
 */

/*
 * As per Alternate functionality register mapping
 *  PB3 - SPI1_SCK
 *  PB4 - SPI1_MISO
 *  PB5 - SPI1_MOSI
 *  PA15 - SPI1_NSS
 *  ALT Function Mode : 5
 */
#include "Stm32f446xx.h"

void SPI1_GPIO_Init(void);
void SPI1_Init(void);

void SPI1_Init(void)
{
	SPI_Handle_t  SPI1handle;

	SPI_PeriClkCtrl(SPI1, ENABLE);

	SPI1handle.pSPIx = SPI1;
	SPI1handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;  // Generates Serial Clk of 8 Mhz
	SPI1handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI1handle.SPIConfig.SPI_SSM = SPI_SSM_ENABLE;
	SPI1handle.SPIConfig.SPI_SSI = SPI_SSI_ENABLE;

	SPI_Init(&SPI1handle);
}

void SPI1_GPIO_Init(void)
{
	GPIO_Handle_t SPIPin1;
	GPIO_Handle_t SPIPin2;

	GPIO_PeriClkCtrl(GPIOA, ENABLE);
	GPIO_PeriClkCtrl(GPIOB, ENABLE);

	SPIPin1.pGPIOx = GPIOA;
	SPIPin2.pGPIOx = GPIOB;

	SPIPin1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPin2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;

	SPIPin1.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;
	SPIPin2.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;

	SPIPin1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	SPIPin2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	SPIPin1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPin2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	SPIPin1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	SPIPin2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	SPIPin1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
	SPIPin2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_3;

	//SCLK and NSS
	GPIO_Init(&SPIPin1);
//	GPIO_Init(&SPIPin2);

	//MOSI
	SPIPin2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	GPIO_Init(&SPIPin2);

	//MISO
//	SPIPin2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_4;
//	GPIO_Init(&SPIPin2);
}

int main (void)
{
	char user_data[] = "Hello World";

	// This function is used to initialize GPIO pins to behave as SPI1 pins
	SPI1_GPIO_Init();

	// This function is used to initialize SPI peripheral parameters
    SPI1_Init();

    // Enable the SPI peripheral
    SPI_PerpheralControl(SPI1, ENABLE);

    SPI_SendData(SPI1, (uint8_t*)user_data, strlen(user_data));

    SPI_PerpheralControl(SPI1, DISABLE);

    while(1);

	return 0;
}
