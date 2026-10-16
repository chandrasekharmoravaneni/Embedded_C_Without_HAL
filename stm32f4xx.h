/*
 * stm32f4xx.h
 *
 *  Created on: 7 Oct 2026
 *      Author: chandrasekharmoravaneni
 */

#ifndef STM32F4XX_H_
#define STM32F4XX_H_

#include <stdint.h>

#define 	__vo      volatile

/* Peripheral Bus Address*/

#define PERIPHERAL_BASE_ADDR        0X40000000U
#define APB1_BASE_ADDR 				PERIPHERAL_BASE_ADDR
#define APB2_BASE_ADDR				0x40007400U
#define AHB1_BASE_ADDR				0x40020000U
#define AHB2_BASE ADDR				0x50000000U

#define RCC_BASE_ADDR				0x40023800U


/* GPIO base address*/
#define GPIOA_BASE_ADDR 			(AHB1_BASE_ADDR + 0x0000U)
#define GPIOB_BASE_ADDR 			(AHB1_BASE_ADDR + 0x0400U)
#define GPIOC_BASE_ADDR    			(AHB1_BASE_ADDR + 0x0800U)
#define GPIOD_BASE_ADDR 			(AHB1_BASE_ADDR + 0x0C00U)
#define GPIOE_BASE_ADDR				(AHB1_BASE_ADDR + 0x1000U)
#define GPIOH_BASE_ADDR				(AHB1_BASE_ADDR + 0x1C00U)

/* GPIO Ports*/
#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE				((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOH				((GPIO_RegDef_t*)GPIOH_BASE_ADDR)

#define RCC					((RCC_RegDef_t*)RCC_BASE_ADDR)


/* Clock enable for GPIOx ports*/

#define GPIOA_PCLK_EN()       (RCC -> AHB1ENR |= (1U<<0))
#define GPIOB_PCLK_EN()       (RCC -> AHB1ENR |= (1U<<1))
#define GPIOC_PCLK_EN()       (RCC -> AHB1ENR |= (1U<<2))
#define GPIOD_PCLK_EN()       (RCC -> AHB1ENR |= (1U<<3))
#define GPIOE_PCLK_EN()       (RCC -> AHB1ENR |= (1U<<4))
#define GPIOH_PCLK_EN()       (RCC -> AHB1ENR |= (1U<<7))

/* Clock disable for GPIOx ports*/

#define GPIOA_PCLK_DI()       (RCC -> AHB1ENR &= ~(1U<<0))
#define GPIOB_PCLK_DI()       (RCC -> AHB1ENR &= ~(1U<<1))
#define GPIOC_PCLK_DI()       (RCC -> AHB1ENR &= ~(1U<<2))
#define GPIOD_PCLK_DI()       (RCC -> AHB1ENR &= ~(1U<<3))
#define GPIOE_PCLK_DI()       (RCC -> AHB1ENR &= ~(1U<<4))
#define GPIOH_PCLK_DI()       (RCC -> AHB1ENR &= ~(1U<<7))

/*GPIOx reset*/
#define GPIOA_REG_RESET()     do { (RCC -> AHB1RSTR |= (1U<<0));  (RCC -> AHB1RSTR &= ~(1U<<0)); } while(0)
#define GPIOB_REG_RESET()     do { (RCC -> AHB1RSTR |= (1U<<1));  (RCC -> AHB1RSTR &= ~(1U<<1)); } while(0)
#define GPIOC_REG_RESET()     do { (RCC -> AHB1RSTR |= (1U<<2));  (RCC -> AHB1RSTR &= ~(1U<<2)); } while(0)
#define GPIOD_REG_RESET()     do { (RCC -> AHB1RSTR |= (1U<<3));  (RCC -> AHB1RSTR &= ~(1U<<3)); } while(0)
#define GPIOE_REG_RESET()     do { (RCC -> AHB1RSTR |= (1U<<4));  (RCC -> AHB1RSTR &= ~(1U<<4)); } while(0)
#define GPIOH_REG_RESET()     do { (RCC -> AHB1RSTR |= (1U<<7));  (RCC -> AHB1RSTR &= ~(1U<<7)); } while(0)

#define ENABLE 			1
#define DISABLE 		0
#define GPIO_PIN_SET 	ENABLE
#define GPIO_PIN_RESET  DISABLE
#define FLAG_RESET		DISABLE
#define FLAG_SET		ENABLE

typedef struct {
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSSR;
	__vo uint32_t LCKR;
	__vo uint32_t AF[2];

}GPIO_RegDef_t;

typedef struct{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	uint32_t RESERVED0[2];
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED4[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED6[2];
	__vo uint32_t  BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED7[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;

}RCC_RegDef_t;



#endif /* STM32F4XX_H_ */
