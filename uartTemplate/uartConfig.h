/*
 * uartConfig.h
 *
 *  Created on: Sep 9, 2024
 *      Author: jzurita
 */

#ifndef INC_UARTCONFIG_H_
#define INC_UARTCONFIG_H_

void UART1_GPIO_Config(void) {

	// clear both MODE registers
	GPIOA->MODER &= ~(GPIO_MODER_MODE9_Msk);
	GPIOA->MODER &= ~(GPIO_MODER_MODE10_Msk);

	// configure PA9 and PA10 as Alt function
	GPIOA->MODER |= (GPIO_MODER_AF << GPIO_MODER_MODE9_Pos);
	GPIOA->MODER |= (GPIO_MODER_AF << GPIO_MODER_MODE10_Pos);

	// clear both registers
	GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH1;
	GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH2;

	// set each to USART1 AFSEL
	GPIOA->AFR[1] |= (GPIO_AF7_SEL << GPIO_AFRH_AFRH1_Pos);
	GPIOA->AFR[1] |= (GPIO_AF7_SEL << GPIO_AFRH_AFRH2_Pos);

}

void UART1_Config(void){

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // enable USART clock

	USART1->CR1 &= ~(USART_CR1_OVER8); // 16-bit over-sampling
	USART1->CR3 &= ~(USART_CR3_ONEBIT);
	USART1->CR1 &= ~(USART_CR1_PCE); // no parity bit
	USART1->CR1 &= ~(USART_CR1_M); // 1 Start, 8 data, n stop
	USART1->CR2 &= ~(USART_CR2_STOP_Msk); // 1 stop bit

	uint32_t UART_clk = 40000000; // 40 Mhz
	uint32_t baud_rate = 153000; // 153k baud

	/*  Please consult pages 808-809 on RM0390
   *  Reference manual in order to configure Baud Rate Register (BRR)
	 */

	USART1->BRR = 262; // value depends on desired Baud Rate, SYSCLK and APB2 frequency

	//USART1->CR1 |= USART_CR1_RXNEIE; // enable reception interrupt if you choose so
	USART1->CR1 |= USART_CR1_TCIE; // enable transmit complete interrupt
	USART1->CR3 |= USART_CR3_EIE; // enable framing error interrupt

	USART1->CR1 |= USART_CR1_RE; // enable RX UART
	USART1->CR1 |= USART_CR1_TE; // enable TX UART
	USART1->CR1 |= USART_CR1_UE; // enable USART1

	NVIC_SetPriority(USART1_IRQn, 0);
	NVIC_EnableIRQ(USART1_IRQn);
}

/*  A more efficient way to send a char via UART would be with interrupts, please consult 
 *  uartInterruptTest.c to see an example of a interrupt-driven UART
 */ 
void UART1_TransmitChar(uint8_t chr) {

	// if transmit buffer is full, wait
	while(!(USART1->SR & USART_SR_TXE)) {
	}
  
	// write char to USART1 TX BUF
	USART1->DR = chr;

}

#endif /* INC_UARTCONFIG_H_ */
