/*
 * clockConfig.h
 *
 *  Created on: Sep 8, 2024
 *      Author: jzurita
 */

#ifndef INC_CLOCKCONFIG_H_
#define INC_CLOCKCONFIG_H_


void SystemClock_Config(void) {

    // Enable HSI (High-Speed Internal) clock
	// HSI is 16MHz for this STM32F446RE model
    RCC->CR |= RCC_CR_HSION;            // Enable HSI
    while (!(RCC->CR & RCC_CR_HSIRDY)); // Wait for HSI to be ready

    // if SYSCLK is (160-180)MHz, use 5 cycle wait state
    FLASH->ACR = FLASH_ACR_LATENCY_5WS;

    // VCO (voltage-controlled oscillator) calculation = (16MHz) * (PLLN / PLLM)
    // SYSCLK = VCO / PLLP
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLSRC_Msk); // enables HSI clock for PLL

    // clear previous PLL values
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk);
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_Msk);
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP_Msk);

    /* Determining the PLL freq:
     * (HSI * PLLN) / (PLLM * PLLP) = PLL_finalFreq
     */
    RCC->PLLCFGR |= (16 << RCC_PLLCFGR_PLLM_Pos); // divide by 16
    RCC->PLLCFGR |= (320 << RCC_PLLCFGR_PLLN_Pos); // multiply by 320
    RCC->PLLCFGR |= (0 << RCC_PLLCFGR_PLLP_Pos); // divide by 2

    // enable the PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // enables PLLP as SYSCLK
    RCC->CFGR &= ~(RCC_CFGR_SW_Msk);
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    // wait until timer module is confirmed using PLLP
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    RCC->CFGR &= ~(RCC_CFGR_HPRE_Msk);
    RCC->CFGR &= ~(RCC_CFGR_PPRE1_Msk);
    RCC->CFGR &= ~(RCC_CFGR_PPRE1_Msk);

    // configure AHB prescaler to be 1
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    // configure APB1 clock to 20 MHz (160MHz / 8) (Timer Clocks are now 40 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV8;

    // configure APB2 clock to 40 Mhz (160Mhz / 4) (Timer Clocks are now 80 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV4;

    // you are now done with SYSCLK timer initialization!

}


#endif /* INC_CLOCKCONFIG_H_ */
