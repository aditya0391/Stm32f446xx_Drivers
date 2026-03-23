/*
 * Stm32f446xx.h
 *
 *  Created on: Mar 11, 2026
 *      Author: Aditya A Vilayatkar
 */


#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

/*****************************START: Processor Specific Details******************************/
/*
 * ARM CORTEX Mx Processor NVIC ISERx Register Addresses
 */

#define NVIC_ISER0              ( (volatile uint32_t*)0xE000E100 )
#define NVIC_ISER1              ( (volatile uint32_t*)0xE000E104 )
#define NVIC_ISER2              ( (volatile uint32_t*)0xE000E108 )
#define NVIC_ISER3              ( (volatile uint32_t*)0xE000E10C )

/*
 * ARM CORTEX Mx Processor NVIC ICERx Register Addresses
 */

#define NVIC_ICER0              ( (volatile uint32_t*)0xE000E180 )
#define NVIC_ICER1              ( (volatile uint32_t*)0xE000E184 )
#define NVIC_ICER2              ( (volatile uint32_t*)0xE000E188 )
#define NVIC_ICER3              ( (volatile uint32_t*)0xE000E18C )

/*
 * ARM CORTEX Mx Processor NVIC IPRx Register Addresses
 */

#define NVIC_IPR                ( (volatile uint32_t*)0xE000E400 )

/*
 * ARM CORTEX Mx Processor Number of Priority bits implemented in priority register
 */

#define NO_PR_BITS_IMPLEMENTED        4

/*****************************END: Processor Specific Details******************************/
/*
 * Generic Macros
 */

#define ENABLE             1
#define DISABLE            0
#define SET                ENABLE
#define RESET              DISABLE
#define GPIO_PIN_SET       SET
#define GPIO_PIN_RESET     RESET
#define FLAG_SET           SET
#define FLAG_RESET         RESET

/*BASEADDR Addresses of Flash and SRAM Memory*/

#include <stdint.h>
#include <stdlib.h>


#define FLASH_BASEADDR        0x08000000U  /* Flash BASEADDR Address*/
#define SRAM1_BASEADDR        0x20000000U  /* SRAM1 BASEADDR Address 112KB*/
#define SRAM2_BASEADDR        0x2001C000U  /* SRAM2 BASEADDR Address*/
#define SYS_MEMORYADDR        0x1FFF0000U  /* System Memory Address*/
#define ROM                   0x080D0000U  /* ROM Address*/

#define SRAM                  SRAM1_BASEADDR


/*AHBx and APBx Bus Peripheral BASEADDR addresses */

#define PERIPH_BASEADDR           0x40000000U  /*Peripheral BASEADDR Address*/
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
#define GPIOH_BASEADDR        (AHB1PERIPH_BASEADDR + 0x1C00)

#define RCC_BASEADDR          (AHB1PERIPH_BASEADDR + 0x3800)

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


typedef struct
{
	volatile uint32_t CR1;              /*SPI control register 1*/
	volatile uint32_t CR2;              /*SPI control register 2*/
	volatile uint32_t SR;               /*SPI status register*/
	volatile uint32_t DR;               /*SPI data register*/
	volatile uint32_t CRCPR;            /*SPI CRC polynomial register*/
	volatile uint32_t RXCRCR;           /*SPI RX CRC register*/
	volatile uint32_t TXCRCR;           /*SPI TX CRC register*/
	volatile uint32_t I2SCFGR;          /*SPI_I2S configuration register*/
	volatile uint32_t I2SPR;            /*SPI_I2S Prescaler register*/
}SPI_RegDef_t;


/*SPI Registers*/
#define SPI1    ((SPI_RegDef_t*) SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t*) SPI2_BASEADDR)
#define SPI3    ((SPI_RegDef_t*) SPI3_BASEADDR)
#define SPI4    ((SPI_RegDef_t*) SPI4_BASEADDR)


/*GPIO register structures can be used like below
 *
 *    GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t*)GPIOA_BASEADDR;
      pGPIOA->MODER = 0x1 ;
      to minimize adding address, create macro
 **/

typedef struct
{
	volatile uint32_t CR;             /*RCC clock control register*/
	volatile uint32_t PLLCFGR;        /*RCC PLL configuration register*/
	volatile uint32_t CFGR;           /*RCC clock configuration register*/
	volatile uint32_t CIR;            /*RCC clock interrupt register*/
	volatile uint32_t AHB1RSTR;       /*RCC AHB1 peripheral reset register*/
	volatile uint32_t AHB2RSTR;       /*RCC AHB2 peripheral reset register*/
	volatile uint32_t AHB3RSTR;       /*RCC AHB3 peripheral reset register*/
	uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;       /*RCC APB1 peripheral reset register*/
	volatile uint32_t APB2RSTR;       /*RCC APB2 peripheral reset register*/
	uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;        /*RCC AHB1 peripheral clock enable register*/
	volatile uint32_t AHB2ENR;        /*RCC AHB2 peripheral clock enable register*/
	volatile uint32_t AHB3ENR;        /*RCC AHB3 peripheral clock enable register*/
	uint32_t RESERVED2;
	volatile uint32_t APB1ENR;        /*RCC APB1 peripheral clock enable register*/
	volatile uint32_t APB2ENR;        /*RCC APB2 peripheral clock enable register*/
	uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENR;      /*RCC AHB1 peripheral clock enable in low power mode register*/
	volatile uint32_t AHB2LPENR;      /*RCC AHB2 peripheral clock enable in low power mode register*/
	volatile uint32_t AHB3LPENR;      /*RCC AHB3 peripheral clock enable in low power mode register*/
	uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;      /*RCC APB1 peripheral clock enable in low power mode register*/
	volatile uint32_t APB2LPENR;      /*RCC APB2 peripheral clock enable in low power mode register*/
	uint32_t RESERVED5[2];
	volatile uint32_t BDCR;           /*RCC Backup domain control register*/
	volatile uint32_t CSR;            /*RCC clock control and status register*/
	uint32_t RESERVED6[2];
	volatile uint32_t SSCGR;          /*RCC spread spectrum clock generation register*/
	volatile uint32_t PLLI2SCFGR;     /*RCC PLLI2S configuration register*/
	volatile uint32_t PLLSAICFGR;     /*RCC PLL configuration register*/
	volatile uint32_t DCKCFGR;        /*RCC dedicated clock configuration register*/
	volatile uint32_t CKGATENR;           /*RCC clocks gated enable register*/
	volatile uint32_t DCKCFGR2;           /*RCC dedicated clocks configuration register 2*/
}RCC_RegDef_t;

/*
 * EXTI peripheral Register structure
 */

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

/*
 * SYSCFG peripheral Register structure
 */

typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;
	volatile uint32_t CFGR;
}SYSCFG_RegDef_t;



#define GPIOA           ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB           ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC           ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD           ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE           ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF           ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG           ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH           ((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC_REG         ((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI            ((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG          ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 *  Clock Enable Macros for GPIOx Peripheral
 **/

#define GPIOA_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 0) )
#define GPIOB_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 1) )
#define GPIOC_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 2) )
#define GPIOD_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 3) )
#define GPIOE_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 4) )
#define GPIOF_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 5) )
#define GPIOG_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 6) )
#define GPIOH_CLK_EN()      ( RCC_REG->AHB1ENR |= (1 << 7) )

/*
 * Returns port code for given GPIOx port base address
 */

#define GPIOxPORT(x)        ( (x == GPIOA)? 0 : \
		                      (x == GPIOB)? 1 : \
		                      (x == GPIOC)? 2 : \
		                      (x == GPIOD)? 3 : \
		                      (x == GPIOE)? 4 : \
		                      (x == GPIOF)? 5 : \
		                      (x == GPIOG)? 6 : \
		                      (x == GPIOH)? 7 : 0 )


/*
 * IRQ Numbers for EXTI Lines
 */

#define IRQ_NUMBER_EXTI0         6
#define IRQ_NUMBER_EXTI1         7
#define IRQ_NUMBER_EXTI2         8
#define IRQ_NUMBER_EXTI3         9
#define IRQ_NUMBER_EXTI4         10
#define IRQ_NUMBER_EXTI9_5       23
#define IRQ_NUMBER_EXTI15_10     40

/*
 * IRQ Priority for EXTI Lines
 */

#define IRQ_PRIORITY_EXTI0         13
#define IRQ_PRIORITY_EXTI1         14
#define IRQ_PRIORITY_EXTI2         15
#define IRQ_PRIORITY_EXTI3         16
#define IRQ_PRIORITY_EXTI4         17
#define IRQ_PRIORITY_EXTI9_5       30
#define IRQ_PRIORITY_EXTI15_10     47

/*
 *  Clock Disable Macros for GPIOx Peripheral
 **/

#define GPIOA_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 0) )
#define GPIOB_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 1) )
#define GPIOC_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 2) )
#define GPIOD_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 3) )
#define GPIOE_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 4) )
#define GPIOF_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 5) )
#define GPIOG_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 6) )
#define GPIOH_CLK_DIS()      ( RCC_REG->AHB1ENR &= ~(1 << 7) )

/*
 *  Clock Enable Macros for SPIx Peripheral
 */

#define SPI2_CLK_EN()       ( RCC_REG->APB1ENR |= (1 << 14))
#define SPI3_CLK_EN()       ( RCC_REG->APB1ENR |= (1 << 15))

#define SPI1_CLK_EN()       ( RCC_REG->APB2ENR |= (1 << 12))
#define SPI4_CLK_EN()       ( RCC_REG->APB2ENR |= (1 << 13))

/*
 *  Clock Disable Macros for SPIx Peripheral
 */

#define SPI2_CLK_DIS()       ( RCC_REG->APB1ENR &= ~(1 << 14))
#define SPI3_CLK_DIS()       ( RCC_REG->APB1ENR &= ~(1 << 15))

#define SPI1_CLK_DIS()       ( RCC_REG->APB2ENR &= ~(1 << 12))
#define SPI4_CLK_DIS()       ( RCC_REG->APB2ENR &= ~(1 << 13))

/*
 *  Clock Enable Macros for I2Cx Peripheral
 */

#define I2C1_CLK_EN()       ( RCC_REG->APB1ENR |= (1 << 21))
#define I2C2_CLK_EN()       ( RCC_REG->APB1ENR |= (1 << 22))
#define I2C3_CLK_EN()       ( RCC_REG->APB1ENR |= (1 << 23))

/*
 *  Clock Disable Macros for I2Cx Peripheral
 */

#define I2C1_CLK_DIS()       ( RCC_REG->APB1ENR &= ~(1 << 21))
#define I2C2_CLK_DIS()       ( RCC_REG->APB1ENR &= ~(1 << 22))
#define I2C3_CLK_DIS()       ( RCC_REG->APB1ENR &= ~(1 << 23))

/*
 * Clock Enable Macros for USARTx Peripheral
 */

#define USART1_CLK_EN()     ( RCC_REG->APB2ENR |= (1 << 4))
#define USART6_CLK_EN()     ( RCC_REG->APB2ENR |= (1 << 5))

#define USART2_CLK_EN()     ( RCC_REG->APB1ENR |= (1 << 17))
#define USART3_CLK_EN()     ( RCC_REG->APB1ENR |= (1 << 18))

#define UART4_CLK_EN()      ( RCC_REG->APB1ENR |= (1 << 19))
#define UART5_CLK_EN()      ( RCC_REG->APB1ENR |= (1 << 20))

/*
 * Clock Disable Macros for USARTx Peripheral
 */

#define USART1_CLK_DIS()     ( RCC_REG->APB2ENR &= ~(1 << 4))
#define USART6_CLK_DIS()     ( RCC_REG->APB2ENR &= ~(1 << 5))

#define USART2_CLK_DIS()     ( RCC_REG->APB1ENR &= ~(1 << 17))
#define USART3_CLK_DIS()     ( RCC_REG->APB1ENR &= ~(1 << 18))

#define UART4_CLK_DIS()      ( RCC_REG->APB1ENR &= ~(1 << 19))
#define UART5_CLK_DIS()      ( RCC_REG->APB1ENR &= ~(1 << 20))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_CLK_EN()     ( RCC_REG->APB1ENR |= (1 << 14))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_CLK_DIS()     ( RCC_REG->APB1ENR &= ~(1 << 14))

/*
 * Register Reset needs to be set and then reset
 * Here, First line: puts GPIOx into reset (all its registers return to default values).
 * Second line: immediately releases GPIOx from reset so you can use it again.
 */
#define GPIOA_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 0)); (RCC_REG->AHB1RSTR &= ~(1 << 0));} while(0)
#define GPIOB_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 1)); (RCC_REG->AHB1RSTR &= ~(1 << 1));} while(0)
#define GPIOC_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 2)); (RCC_REG->AHB1RSTR &= ~(1 << 2));} while(0)
#define GPIOD_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 3)); (RCC_REG->AHB1RSTR &= ~(1 << 3));} while(0)
#define GPIOE_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 4)); (RCC_REG->AHB1RSTR &= ~(1 << 4));} while(0)
#define GPIOF_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 5)); (RCC_REG->AHB1RSTR &= ~(1 << 5));} while(0)
#define GPIOG_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 6)); (RCC_REG->AHB1RSTR &= ~(1 << 6));} while(0)
#define GPIOH_REG_RESET()    do{(RCC_REG->AHB1RSTR |= (1 << 7)); (RCC_REG->AHB1RSTR &= ~(1 << 7));} while(0)

/*
 * BIT position definitions of SPI peripheral
 */

#define SPI_CR1_CPHA     0
#define SPI_CR1_CPOL     1
#define SPI_CR1_MSTR     2
#define SPI_CR1_RXONLY   10
#define SPI_CR1_DFF      11
#define SPI_CR1_BIDI     15
#define SPI_CR1_BR       3

/*
 * BIT Position definition of SPI SR Register
 */


#define SPI_SR_RXNE       0
#define SPI_SR_TXE        1
#define SPI_CHSIDE        2
#define SPI_UDR           3


#endif /* INC_STM32F446XX_H_ */
