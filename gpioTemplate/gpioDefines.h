/*
 * gpioDefines.h
 *
 *  Created on: Sep 8, 2024
 *      Author: jzurita
 */

#ifndef INC_GPIODEFINES_H_
#define INC_GPIODEFINES_H_


#define GPIO_MODER_INPUT 		(0x00UL)
#define GPIO_MODER_OUTPUT 	(0x01UL)
#define GPIO_MODER_AF			  (0x02UL)
#define GPIO_MODER_ANALOG		(0x03UL)

#define GPIO_OTYPER_PP			(0x00UL)
#define GPIO_OTYPER_OD 			(0x01UL)

#define GPIO_ODR_HIGH			  (0x01UL)
#define GPIO_ODR_LOW 			  (0x00UL)

#define GPIO_OSPEEDR_LOW 		(0x00UL)
#define GPIO_OSPEEDR_MED 		(0x01UL)
#define GPIO_OSPEEDR_HIGH 	(0x02UL)
#define GPIO_OSPEEDR_MAX 		(0x03UL)

#define GPIO_PUPDR_NOPULL		(0x00UL)
#define GPIO_PUPDR_PULLUP		(0x01UL)
#define GPIO_PUPDR_PULLDWN 	(0x02UL)

#define GPIO_AF0_SEL			(0x00UL)
#define GPIO_AF1_SEL			(0x01UL)
#define GPIO_AF2_SEL			(0x02UL)
#define GPIO_AF3_SEL			(0x03UL)
#define GPIO_AF4_SEL			(0x04UL)
#define GPIO_AF5_SEL			(0x05UL)
#define GPIO_AF6_SEL			(0x06UL)
#define GPIO_AF7_SEL			(0x07UL)
#define GPIO_AF8_SEL			(0x08UL)
#define GPIO_AF9_SEL			(0x09UL)
#define GPIO_AF10_SEL			(0x0AUL)
#define GPIO_AF11_SEL			(0x0BUL)
#define GPIO_AF12_SEL			(0x0CUL)
#define GPIO_AF13_SEL			(0x0DUL)
#define GPIO_AF14_SEL			(0x0EUL)
#define GPIO_AF15_SEL			(0x0FUL)

#define GPIO_AFRL_AFRL0_Pos		(0U)
#define GPIO_AFRL_AFRL1_Pos		(4U)
#define GPIO_AFRL_AFRL2_Pos		(8U)
#define GPIO_AFRL_AFRL3_Pos		(12U)
#define GPIO_AFRL_AFRL4_Pos		(16U)
#define GPIO_AFRL_AFRL5_Pos		(20U)
#define GPIO_AFRL_AFRL6_Pos		(24U)
#define GPIO_AFRL_AFRL7_Pos		(28U)

#define GPIO_AFRH_AFRH0_Pos		(0U)
#define GPIO_AFRH_AFRH1_Pos		(4U)
#define GPIO_AFRH_AFRH2_Pos		(8U)
#define GPIO_AFRH_AFRH3_Pos		(12U)
#define GPIO_AFRH_AFRH4_Pos		(16U)
#define GPIO_AFRH_AFRH5_Pos		(20U)
#define GPIO_AFRH_AFRH6_Pos		(24U)
#define GPIO_AFRH_AFRH7_Pos		(28U)


#define GPIO_PUPDR_PUPDR0_Pos	(0U)
#define GPIO_PUPDR_PUPDR1_Pos	(2U)
#define GPIO_PUPDR_PUPDR2_Pos	(4U)
#define GPIO_PUPDR_PUPDR3_Pos	(6U)
#define GPIO_PUPDR_PUPDR4_Pos	(8U)
#define GPIO_PUPDR_PUPDR5_Pos	(10U)
#define GPIO_PUPDR_PUPDR6_Pos	(12U)
#define GPIO_PUPDR_PUPDR7_Pos (14U)
#define GPIO_PUPDR_PUPDR8_Pos	(16U)
#define GPIO_PUPDR_PUPDR9_Pos	(18U)
#define GPIO_PUPDR_PUPDR10_Pos	(20U)
#define GPIO_PUPDR_PUPDR11_Pos	(22U)
#define GPIO_PUPDR_PUPDR12_Pos	(24U)
#define GPIO_PUPDR_PUPDR13_Pos	(26U)
#define GPIO_PUPDR_PUPDR14_Pos	(28U)
#define GPIO_PUPDR_PUPDR15_Pos	(30U)

#define GPIO_OSPEEDER_OSPEEDR6_Pos (12UL)
#define GPIO_OSPEEDER_OSPEEDR7_Pos (14UL)

#endif /* INC_GPIODEFINES_H_ */
