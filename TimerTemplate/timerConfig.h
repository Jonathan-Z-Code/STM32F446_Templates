/*
 * timerConfig.h
 *
 *  Created on: Sep 8, 2024
 *      Author: jzurita
 */

#ifndef INC_TIMERCONFIG_H_
#define INC_TIMERCONFIG_H_


void TIM2_Config(void) {

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->CR1 &= ~(TIM_CR1_CMS_Msk); // edge counter
	TIM2->CR1 &= ~(TIM_CR1_DIR_Msk); // counts up
	TIM2->PSC = 4000 - 1; // tim2 frequency is now 10kHz
	TIM2->ARR = 10000 - 1; // Overflow is now 1Hz, every second
	TIM2->DIER = 0; // clear IFG
	TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
	TIM2->CR1 |= TIM_CR1_CEN; // enable tim2 timer

	NVIC_SetPriority(TIM2_IRQn, 1);
	NVIC_EnableIRQ(TIM2_IRQn); // enable NVIC vector

}


#endif /* INC_TIMERCONFIG_H_ */
