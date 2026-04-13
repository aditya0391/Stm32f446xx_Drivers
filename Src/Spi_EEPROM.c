/*
 * Spi_echo_test.c
 *
 *  Created on: Mar 26, 2026
 *      Author: Aditya A Vilayatkar
 */

#include "Stm32f446xx.h"
#include <string.h>

#define CS_LOW()   GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_4, 0)
#define CS_HIGH()  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_4, 1)
void flash_WriteByte(uint32_t addr, uint8_t data);
uint8_t flash_ReadByte(uint32_t addr, uint8_t transmit_data);
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

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_4;  // NSS
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
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
	SPI1Handle.SPIConfig.SPI_CPHA = SPI_CPHA_HIGH;
	SPI1Handle.SPIConfig.SPI_SSM  = SPI_SSM_ENABLE;
    SPI_Init(&SPI1Handle);
}

void busyflag(void);


void busyflag(void)
{
	CS_LOW();
	uint8_t status;
	uint8_t cmd = 0x05;
	SPI_TransmitReceive(SPI1, &cmd, &status, 1);
	SPI_TransmitReceive(SPI1, (uint8_t*)0xFF, &status, 1);
	while(status == SET)
	{
		SPI_TransmitReceive(SPI1, &cmd, &status, 1);
	}
	CS_HIGH();
	return;
}


void flash_WriteByte(uint32_t addr, uint8_t data)
{
    uint8_t cmd;

    // 1. Write Enable
    CS_LOW();
    cmd = 0x06;
    SPI_SendData(SPI1, &cmd, 1);
    CS_HIGH();

    // 2. Page Program
    CS_LOW();
    cmd = 0x02;
    SPI_SendData(SPI1, &cmd, 1);

    uint8_t addr_bytes[3];
    addr_bytes[0] = (addr >> 16) & 0xFF;
    addr_bytes[1] = (addr >> 8) & 0xFF;
    addr_bytes[2] = (addr) & 0xFF;

    SPI_SendData(SPI1, addr_bytes, 3);

    SPI_SendData(SPI1, &data, 1);

    CS_HIGH();

    // 3. Wait till write completes ✅ IMPORTANT
    busyflag();
}


uint8_t flash_ReadByte(uint32_t addr, uint8_t transmit_data)
{
    uint8_t cmd = 0x03;
    uint8_t data;
    uint8_t dummy = 0xFF;

    CS_LOW();

    // 1. Send Read Command
    SPI_SendData(SPI1, &cmd, 1);

    // 2. Send Address
    uint8_t addr_bytes[3];
    addr_bytes[0] = (addr >> 16) & 0xFF;
    addr_bytes[1] = (addr >> 8) & 0xFF;
    addr_bytes[2] = (addr) & 0xFF;

    SPI_SendData(SPI1, addr_bytes, 3);

    // 3. Dummy → Read actual data
    SPI_TransmitReceive(SPI1, &dummy, &data, 1);
    SPI_TransmitReceive(SPI1, &transmit_data, &data, 1);

    CS_HIGH();

    return data;
}

int main (void)
{
    char transmit_data[] = "Hello World";
    uint8_t n = strlen(transmit_data);
    char received_data[n];



    SPI_GPIOInits();
    SPI1_Inits();

    SPI_SSIConfig(SPI1, ENABLE);
    SPI_PerpheralControl(SPI1, ENABLE);

    flash_WriteByte(0x00001000, transmit_data);

    strcpy(received_data, flash_ReadByte(0x00001000, (uint8_t)transmit_data));

    return 0;
}
