
/* Please ensure you enable the NVIC interrupt vector
 * before writing the ISR. 
*/

void USART1_IRQHandler(void) {

	if(USART1->SR & USART_SR_TC) {

		USART1->SR &= ~(USART_SR_TC);
	}

	if(USART1->SR & USART_SR_FE) {

		USART1->SR &= ~(USART_SR_FE);

	}

}
