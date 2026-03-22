/*
 * Stm32f446xx_Spi.h
 *
 *  Created on: Mar 22, 2026
 *      Author: Aditya A Vilayatkar
 */

#ifndef INC_STM32F446XX_SPI_H_
#define INC_STM32F446XX_SPI_H_

#include "Stm32f446xx.h"

/*Configuration Structure for SPIx peripheral*/

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

/*Handle Structure for SPIx peripheral*/

typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPIConfig;
}SPI_Handle_t;

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER  1
#define SPI_DEVICE_MODE_SLAVE   0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD             1
#define SPI_BUS_CONFIG_HD             2
#define SPI_BUS_CONFIG_SIMPLEX_RX     3

/*
 * @SPI_CLKSPEED
 */
#define SPI_SCLK_SPEED_DIV2           0
#define SPI_SCLK_SPEED_DIV4           1
#define SPI_SCLK_SPEED_DIV8           2
#define SPI_SCLK_SPEED_DIV16          3
#define SPI_SCLK_SPEED_DIV32          4
#define SPI_SCLK_SPEED_DIV64          5
#define SPI_SCLK_SPEED_DIV128         6
#define SPI_SCLK_SPEED_DIV256         7


/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS     0
#define SPI_DFF_16BITS    1

/*
 * @CPOL
 */
#define SPI_CPHA_HIGH     1
#define SPI_CPHA_LOW      0

/*
 *  @SPI_SSM
 */
#define SPI_SSM_ENABLE    1
#define SPI_SSM_DISABLE   0

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClkCtrl(SPI_RegDef_t *pSPIx, uint8_t status);

/*
 * Init and De-Init
 */
void SPI_Init(SPI_Handle_t *pSPI_Handle_t);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data Send and Receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and IRQ Handling
 */
void SPI_IRQConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t status); /*To do IRQ configuration*/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle_t);


#endif /* INC_STM32F446XX_SPI_H_ */
