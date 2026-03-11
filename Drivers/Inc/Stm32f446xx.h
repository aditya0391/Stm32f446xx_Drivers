/*
 * Stm32f446xx.h
 *
 *  Created on: Mar 11, 2026
 *      Author: Admin
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#define FLASH_BASEADDR        0x08000000U  /* Flash Base Address*/
#define SRAM1_BASEADDR        0x20000000U  /* SRAM1 Base Address*/
#define SRAM2_BASEADDR        0x2001C000U  /* SRAM2 Base Address*/
#define SYS_MEMORYADDR        0x1FFF0000U  /* System Memory Address*/
#define ROM                   0x080D0000U  /* Rom Address*/s

#define SRAM                  SRAM1_BASEADDR
#endif /* INC_STM32F446XX_H_ */
