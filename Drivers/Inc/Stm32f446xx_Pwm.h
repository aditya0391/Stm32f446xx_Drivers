/*
 * Stm32f446xx_Pwm.h
 *
 *  Created on: Apr 20, 2026
 *      Author: Admin
 */

#ifndef INC_STM32F446XX_PWM_H_
#define INC_STM32F446XX_PWM_H_

#include "Stm32f446xx.h"


typedef struct
{
    uint16_t Prescaler;       // PSC value
    uint16_t AutoReload;      // ARR value
    uint8_t  Status;          // Enable or Disable.
}TIM_Config_t;

typedef struct
{
	TIM6_7_Regdef_t *pTIMx;       // Base address of TIM peripheral
    TIM_Config_t TIM_Config;  // Timer configuration
}TIM_Handle_t;

void Set_Timer_Prescalar(TIM_Handle_t *pTIM_Handle_t);
void Set_Timer_AutoReload(TIM_Handle_t *pTIM_Handle_t);
void Set_Timer_Status(TIM_Handle_t *pTIM_Handle_t);
void Timer_Init(TIM_Handle_t *pTIM_Handle_t);

#endif /* INC_STM32F446XX_PWM_H_ */
