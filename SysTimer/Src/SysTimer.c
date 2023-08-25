/*
 * SysTimer.c
 *
 *  Created on: 26 Ağu 2023
 *      Author: Administrator
 */

#include "SysTimer.h"


__weak void SYSTIMER_200HzTASK(void)
{
//	runs before 100hz tasks
}

__weak void SYSTIMER_100HzTASK1(void)
{

}

__weak void SYSTIMER_100HzTASK2(void)
{

}


void SYSTIMER_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == SYSTIMER_CHANNEL)
	{
		static uint8_t counter = 0;
		counter++;
		if(counter > 1)
			counter = 0;

		// 200hz Task (runs before 100hz tasks)
		SYSTIMER_200HzTASK();

		switch (counter)
		{
		case 0:
			// 100hz Task 1
			SYSTIMER_100HzTASK1();

			break;
		case 1:
			// 100hz Task 2
			SYSTIMER_100HzTASK2();
			break;
		}
	}

}

void SYSTIMER_Init(void)
{
	hSYSTIMER.Instance 			= SYSTIMER_CHANNEL;
	hSYSTIMER.Init.Prescaler 	= SYSTIMER_PRESCALER;
	hSYSTIMER.Init.Period 		= SYSTIMER_PERIOD; // update events after reset
	if( HAL_TIM_Base_Init(&hSYSTIMER) != HAL_OK)
	{
		Error_Handler();
	}

	if(HAL_TIM_Base_Start_IT(&hSYSTIMER) != HAL_OK)
	{
		Error_Handler();
	}
}


void SYSTIMER_GPIOInit(void)
{
	__SYSTIMER_CLK_ENABLE();
	__SYSTIMER_NVIC_ENABLE();
}
