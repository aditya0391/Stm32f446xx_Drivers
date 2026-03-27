/*
 * Spi_echo_test.c
 *
 *  Created on: Mar 26, 2026
 *      Author: Aditya A Vilayatkar
 */

#include "Stm32f446xx.h"

void GPIOA_Init(void);
void SPI1_Init(void);

GPIO_Handle_t Spi1_Clk;
GPIO_Handle_t Spi1_Miso;
GPIO_Handle_t Spi1_Mosi;
SPI_Handle_t SPI1_PERI;

void SPI1_Init(void)
{
	SPI1_PERI.pSPIx = SPI1;
	SPI_PerpheralControl(SPI1, ENABLE);

	SPI1_PERI.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1_PERI.SPIConfig.SPI_CPHA = SPI_CPHA_HIGH;
	SPI1_PERI.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1_PERI.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1_PERI.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1_PERI.SPIConfig.SPI_SSI = SPI_SSI_ENABLE;
	SPI1_PERI.SPIConfig.SPI_SSM = SPI_SSM_DISABLE;
	SPI1_PERI.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;


	SPI_Init(&SPI1_PERI);
}

void GPIOA_Init(void)
{
	Spi1_Clk.pGPIOx = GPIOA;
	Spi1_Clk.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;
	Spi1_Clk.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	Spi1_Clk.GPIO_PinConfig.GPIO_PinNumber = 5;
	Spi1_Clk.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Spi1_Clk.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Spi1_Clk.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&Spi1_Clk);

	Spi1_Miso.pGPIOx = GPIOA;
	Spi1_Miso.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;
	Spi1_Miso.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	Spi1_Miso.GPIO_PinConfig.GPIO_PinNumber = 6;
	Spi1_Miso.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Spi1_Miso.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Spi1_Miso.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&Spi1_Miso);

	Spi1_Mosi.pGPIOx = GPIOA;
	Spi1_Mosi.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;
	Spi1_Mosi.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	Spi1_Mosi.GPIO_PinConfig.GPIO_PinNumber = 7;
	Spi1_Mosi.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Spi1_Mosi.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Spi1_Mosi.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&Spi1_Mosi);
}
int main (void)
{
	uint8_t send_value = 15u;
	uint8_t received_value = 0U;
	GPIO_PeriClkCtrl(GPIOA, ENABLE);
	GPIOA_Init();
	SPI_PeriClkCtrl(SPI1, ENABLE);
	SPI1_Init();
	for(uint8_t i = 0; i < 5; i ++)
	{
	    SPI_SendData(SPI1, (uint8_t*)send_value, sizeof(send_value));
	    SPI_ReceiveData(SPI1, (uint8_t*)received_value, sizeof(received_value));
	    if (i == 5)
	    {
	    	i = 0;
	    }
	}
	 SPI_PerpheralControl(SPI1, DISABLE);
	return 0;
}
