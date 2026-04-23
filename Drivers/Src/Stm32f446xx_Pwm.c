/*
 * Stm32f446xx_Pwm.c
 *
 *  Created on: Apr 23, 2026
 *      Author: Aditya A Vilayatkar
 */

#include "Stm32f446xx.h"

void Set_Timer_Prescalar(TIM_Handle_t *pTIM_Handle_t)
{
	pTIM_Handle_t->pTIMx->PSC = pTIM_Handle_t->TIM_Config.Prescaler;
}

void Set_Timer_AutoReload(TIM_Handle_t *pTIM_Handle_t)
{
	pTIM_Handle_t->pTIMx->ARR = pTIM_Handle_t->TIM_Config.AutoReload;
}

void Set_Timer_Status(TIM_Handle_t *pTIM_Handle_t)
{
	if(pTIM_Handle_t->TIM_Config.Status == ENABLE)
	{
		pTIM_Handle_t->pTIMx->CR1 |= (1 << 0);
	}
	if(pTIM_Handle_t->TIM_Config.Status != ENABLE)
	{
		pTIM_Handle_t->pTIMx->CR1 &= ~(1 << 0);
	}
}


void Timer_Init(TIM_Handle_t *pTIM_Handle_t)
{
	Set_Timer_Prescalar(pTIM_Handle_t);
	Set_Timer_AutoReload(pTIM_Handle_t);
	Set_Timer_Status(pTIM_Handle_t);
}
