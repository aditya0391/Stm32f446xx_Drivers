/*
 * Stm32f446xx_Spi.c
 *
 *  Created on: Mar 22, 2026
 *      Author: Aditya A Vilayatkar
 */


#include "Stm32f446xx_Spi.h"

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClkCtrl(SPI_RegDef_t *pSPIx, uint8_t status)
{
	if (status == ENABLE)
	{
	    if(pSPIx == SPI1)
	    {
	        SPI1_CLK_EN();
	    }
	    else if (pSPIx == SPI2)
	    {
	    	SPI2_CLK_EN();
	    }
	    else if (pSPIx == SPI3)
	    {
	    	SPI3_CLK_EN();
	    }
	    else if (pSPIx == SPI4)
	    {
	    	SPI4_CLK_EN();
	    }
	}
	else
	{
	    if(pSPIx == SPI1)
	    {
	    	SPI1_CLK_DIS();
	    }
	    else if (pSPIx == SPI2)
	    {
	        SPI2_CLK_DIS();
	    }
	    else if (pSPIx == SPI3)
	    {
	    	SPI3_CLK_DIS();
	    }
	    else if (pSPIx == SPI4)
	    {
	    	SPI4_CLK_DIS();
	    }
	}
}

/*
 * Init and De-Init
 */
void SPI_Init(SPI_Handle_t *pSPI_Handle_t)
{
	uint32_t temp = 0;  /*can be initialized as a whole register since only one register contains all the parameters*/
	// 1. Configure Device Mode
	temp |= pSPI_Handle_t->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	// 2. Configure the Bus Config
	if(pSPI_Handle_t->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//Bi Di should be cleared
		temp &= ~(1 << SPI_CR1_BIDI);
	}
	else if (pSPI_Handle_t->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		// Bi Di should be set
		temp |= (1 << SPI_CR1_BIDI);
	}
	else if (pSPI_Handle_t->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX)
	{
		//Bi Di should be cleared
		temp &= ~(1 << SPI_CR1_BIDI);
		// RX only bit should be set
		temp |= (1 << SPI_CR1_RXONLY);
	}
	// 3. Configure the SPI clock speed
	temp |= (pSPI_Handle_t->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR);

	// 4. Configure the DFF
	temp |= (pSPI_Handle_t->SPIConfig.SPI_DFF << SPI_CR1_DFF);

	// 5. Configure the CPOL
	temp |= (pSPI_Handle_t->SPIConfig.SPI_CPOL << SPI_CR1_CPOL);

	// 6. Configure the CPHA
	temp |= (pSPI_Handle_t->SPIConfig.SPI_CPHA << SPI_CR1_CPHA);

    pSPI_Handle_t->pSPIx->CR1 = temp;

}

void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}

/*
 * Data Send and Receive
 */

static uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx->SR && FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}

// Note: Blocking call, Polling based
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
    while (Len > 0)
    {
    	// Wait until TXE is set
    	while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG))
    	{
    		// check the DFF bit in CR1
    		if (pSPIx->CR1 & (1 << SPI_CR1_DFF))
    		{
    		     // 16 bit DFF
    			// load the data into DR
    			pSPIx->DR = *((uint16_t*)pTxBuffer);
    			Len--;
    			Len--;
    			(uint16_t*)pTxBuffer++;
    		}
    		else
    			pSPIx->DR = *pTxBuffer;
    		    Len--;
    		    pTxBuffer++;
    	}
    }
}

void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}

/*
 * IRQ Configuration and IRQ Handling
 */
void SPI_IRQConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t status)
{

}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}

void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle_t)
{

}
