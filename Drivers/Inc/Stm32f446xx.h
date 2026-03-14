/*
 * Stm32f446xx.h
 *
 *  Created on: Mar 11, 2026
 *      Author: Admin
 */


#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_


/*BASEADDR Addresses of Flash and SRAM Memory*/

#include <stdint.h>
#include <stdlib.h>

#define FLASH_BASEADDR        0x08000000U  /* Flash BASEADDR Address*/
#define SRAM1_BASEADDR        0x20000000U  /* SRAM1 BASEADDR Address 112KB*/
#define SRAM2_BASEADDR        0x2001C000U  /* SRAM2 BASEADDR Address*/
#define SYS_MEMORYADDR        0x1FFF0000U  /* System Memory Address*/
#define ROM                   0x080D0000U  /* ROM Address*/

#define SRAM                  SRAM1_BASEADDR


/*AHBx and APBx Bus Peripherel BASEADDR addresses */

#define PERIPH_BASEADDR           0x40000000U  /*Peripherel BASEADDR Address*/
#define APB1PERIPH_BASEADDR       PERIPH_BASEADDR  /*APB1 BASEADDR Address*/
#define APB2PERIPH_BASEADDR       0x40010000U  /*APB2 BASEADDR Address*/
#define AHB1PERIPH_BASEADDR       0x40020000U  /*AHB1 BASEADDR Address*/
#define AHB2PERIPH_BASEADDR       0x50000000U  /*AHB2 BASEADDR Address*/
#define AHB3PERIPH_BASEADDR       0x60000000U  /*AHB3 BASEADDR Address*/

/*BASEADDR Addresses of peripherals which are hanging on AHB1 Bus */

#define GPIOA_BASEADDR        (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR        (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR        (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR        (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR        (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR        (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR        (AHB1PERIPH_BASEADDR + 0x1800)

/*BASEADDR Addresses of peripherals which are hanging on APB1 Bus */

#define I2C1_BASEADDR         (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR         (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR         (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR         (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR         (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR       (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR       (APB1PERIPH_BASEADDR + 0x4800)

#define UART4_BASEADDR        (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR        (APB1PERIPH_BASEADDR + 0x5000)

/*BASEADDR Addresses of peripherals which are hanging on APB2 Bus */

#define USART1_BASEADDR       (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR       (APB2PERIPH_BASEADDR + 0x1400)

#define SPI1_BASEADDR         (APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR         (APB2PERIPH_BASEADDR + 0x3400)

#define EXTI_BASEADDR         (APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR       (APB2PERIPH_BASEADDR + 0x3800)


/*Peripheral Register definition structure*/

typedef struct
{
	volatile uint32_t MODER;            /*GPIO port mode register */
	volatile uint32_t OTYPER;           /*GPIO port output type register*/
	volatile uint32_t OSPEEDER;         /*GPIO port output speed register*/
	volatile uint32_t PUPDR;            /*GPIO port pull-up/pull-down register*/
	volatile uint32_t IDR;              /*GPIO port input data register*/
	volatile uint32_t ODR ;             /*GPIO port output data register*/
	volatile uint32_t BSRR;             /*GPIO port bit set/reset register*/
	volatile uint32_t LCKR;             /*GPIO port configuration lock register*/
	volatile uint32_t AFR[2] ;          /*GPIO alternate function register, AFR[0]: GPIO alternate function low register, AFR[1]: GPIO alternate function high register*/
}GPIO_RegDef_t;

/*GPIO register structures can be used like below8
 *
 *    GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t*)GPIOA_BASEADDR;
      pGPIOA->MODER = 0x1 ;
      to minimize adding address, create macro
 **/

#define GPIOA           (GPIO_RegDef_t*)GPIOA_BASEADDR
#endif /* INC_STM32F446XX_H_ */
