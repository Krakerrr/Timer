/*
 * SysTimer.h
 *
 *  Created on: 26 Ağu 2023
 *      Author: Administrator
 */

#ifndef INC_SYSTIMER_H_
#define INC_SYSTIMER_H_
#include "main_app.h"


#define SYSTIMER_CHANNEL			TIM6
#define SYSTIMER_PRESCALER			999
#define SYSTIMER_PERIOD				250-1
#define __SYSTIMER_CLK_ENABLE()   	do { \
											__HAL_RCC_TIM6_CLK_ENABLE(); \
										} while(0U)
#define __SYSTIMER_NVIC_ENABLE()   	do { \
											HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0); \
											HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn); \
										} while(0U)

extern TIM_HandleTypeDef hSYSTIMER;

void SYSTIMER_Init(void);
void SYSTIMER_GPIOInit(void);
void SYSTIMER_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void SYSTIMER_100HzTASK1(void);
void SYSTIMER_100HzTASK2(void);
void SYSTIMER_200HzTASK(void);

#endif /* INC_SYSTIMER_H_ */
