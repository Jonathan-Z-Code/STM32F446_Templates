/*
 * gpioConfig.h
 *
 *  Created on: Sep 8, 2024
 *      Author: jzurita
 */

#ifndef INC_GPIOCONFIG_H_
#define INC_GPIOCONFIG_H_

void GPIOA_Config(void) {


    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock

    GPIOA->MODER &= ~(GPIO_MODER_MODE5_Msk); // Clear mode for PA5

    GPIOA->MODER |=  (GPIO_MODER_OUTPUT << GPIO_MODER_MODE5_Pos);  // Set PA5 as GPIO_OUTPUT

    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5_Msk); // Clear Output register, default is push-pull

    GPIOA->OSPEEDR |= (GPIO_OSPEEDR_MED << GPIO_OSPEEDR_OSPEED5_Pos); // Set PA5 to medium speed

    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5); // Clear pull up/down register, default is none
}


#endif /* INC_GPIOCONFIG_H_ */
