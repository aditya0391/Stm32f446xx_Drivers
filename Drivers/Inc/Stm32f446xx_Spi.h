/*
 * Stm32f446xx_Spi.h
 *
 *  Created on: Mar 22, 2026
 *      Author: Aditya A Vilayatkar
 */

#ifndef INC_STM32F446XX_SPI_H_
#define INC_STM32F446XX_SPI_H_

#include "Stm32f446xx.h"
#include "Stm32f446xx_Gpio.h"

/*Configuration Structure for SPIx peripheral*/

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_SPE;
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
#define SPI_CPOL_HIGH     1
#define SPI_CPOL_LOW      0

/*
 * @CPHA
 */
#define SPI_CPHA_HIGH     1
#define SPI_CPHA_LOW      0

/*
 *  @SPI_SSM
 */
#define SPI_SSM_ENABLE    1
#define SPI_SSM_DISABLE   0

/*
 * @SPI_SSI
 */
#define SPI_SSI_ENABLE    1
#define SPI_SSI_DISABLE   0

/*
 * SPI Related Status Flag definitions
 */
#define SPI_TXE_FLAG     (1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG    (1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG    (1 << SPI_SR_BSY)

/*
 * SPI RESET for de initialization
 */

#define SPI1_REG_RESET()       do{(RCC_REG->APB2RSTR |= (1 << 12)); (RCC_REG->APB2RSTR &= ~(1 << 12));}while(0)
#define SPI2_REG_RESET()       do{(RCC_REG->APB1RSTR |= (1 << 14)); (RCC_REG->APB1RSTR &= ~(1 << 14));}while(0)
#define SPI3_REG_RESET()       do{(RCC_REG->APB1RSTR |= (1 << 15)); (RCC_REG->APB1RSTR &= ~(1 << 15));}while(0)
#define SPI4_REG_RESET()       do{(RCC_REG->APB2RSTR |= (1 << 13)); (RCC_REG->APB2RSTR &= ~(1 << 13));}while(0)


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
void SPI_TransmitReceive(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and IRQ Handling
 */
void SPI_IRQConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t status); /*To do IRQ configuration*/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle_t);

/*
 * SPI Peripheral enable API
 */
void SPI_PerpheralControl(SPI_RegDef_t *pSPIx, uint8_t status);

void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t status);


#endif /* INC_STM32F446XX_SPI_H_ */
