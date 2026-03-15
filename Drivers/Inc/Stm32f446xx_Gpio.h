/*
 * Stm32f446xx_Gpio.h
 *
 *  Created on: Mar 15, 2026
 *      Author: Admin
 */

#ifndef INC_STM32F446XX_GPIO_H_
#define INC_STM32F446XX_GPIO_H_


/*
 * @GPIO_PIN_NUMBERS
 */

#define GPIO_PIN_0           0
#define GPIO_PIN_1           1
#define GPIO_PIN_2           2
#define GPIO_PIN_3           3
#define GPIO_PIN_4           4
#define GPIO_PIN_5           5
#define GPIO_PIN_6           6
#define GPIO_PIN_7           7
#define GPIO_PIN_8           8
#define GPIO_PIN_9           9
#define GPIO_PIN_10          10
#define GPIO_PIN_11          11
#define GPIO_PIN_12          12
#define GPIO_PIN_13          13
#define GPIO_PIN_14          14
#define GPIO_PIN_15          15
/*
 * @GPIO_PIN_MODES
 * GPIO Pin possible modes
 */

#define GPIO_MODE_IN         0
#define GPIO_MODE_OUT        1
#define GPIO_MODE_ALTFN      2
#define GPIO_MODE_ANALOG     3
#define GPIO_MODE_IT_FT      4
#define GPIO_MODE_IT_RT      5
#define GPIO_MODE_IT_RFT     6

/*
 * @GPIO_PIN_OP_TYPES
 * GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP      0
#define GPIO_OP_TYPE_OD      1

/*
 * @GPIO_PIN_SPEEDS
 * GPIO pin possible output Speeds
 */

#define GPIO_SPEED_LOW       0
#define GPIO_SPEED_MED       1
#define GPIO_SPEED_FAST      2
#define GPIO_SPEED_HIGH      3

/*
 * @GPIO_PIN_PUPD
 * GPIO pin possible PullUp PullDown Configurations
 */

#define GPIO_NO_PUPD         0
#define GPIO_PU              1
#define GPIO_PD              2


#include "Stm32f446xx.h"

/*
 *  Handle Structure for a GPIO Pin
 */

typedef struct
{
	uint8_t GPIO_PinNumber;             /*Possible values from @GPIO_PIN_NUMBERS*/
	uint8_t GPIO_PinMode;               /*Possible values from @GPIO_PIN_MODES*/
	uint8_t GPIO_PinSpeed;              /*Possible values from @GPIO_PIN_SPEEDS*/
	uint8_t GPIO_PinPuPdControl;        /*Possible values from @GPIO_PIN_PUPD*/
	uint8_t GPIO_PinOPType;             /*Possible values from @GPIO_PIN_OP_TYPES*/
	uint8_t GPIO_PinAltFuncMode;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_PinConfig_t  GPIO_PinConfig;   /*This holds GPIO Pin Configuration Settings*/
	GPIO_RegDef_t     *pGPIOx;          /*This holds the base address of the GPIO port to which the pin belongs*/
}GPIO_Handle_t;

/****************************************************************************************************
 *                            API's supported by Driver
 *
 ****************************************************************************************************/

/*
 *  Init and De-Init
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Peripheral clock setup
 */
void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status);

/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint16_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */
void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t status);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F446XX_GPIO_H_ */
