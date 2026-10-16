/*
 * GPIO.c
 *
 *  Created on: 7 Oct 2026
 *      Author: chandrasekharmoravaneni
 */

#include "GPIO.h"



void GPIO_PCLK_CONTROL(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI){
	if(ENorDI == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}

	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	GPIO_PCLK_CONTROL(pGPIOHandle ->pGPIOx,ENABLE);
	/* MODER*/
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_MODE << 2 * (pGPIOHandle -> GPIO_PinConfig.GPIO_PIN_NUMBER));
	pGPIOHandle -> pGPIOx -> MODER &= ~(0x3U << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PIN_NUMBER));
	pGPIOHandle -> pGPIOx ->MODER |= temp;
	temp = 0;
	/* OTYPER*/
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_OPODType << pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER);
	pGPIOHandle ->pGPIOx ->OTYPER &= ~(0x1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER);
	pGPIOHandle ->pGPIOx ->OTYPER |= temp;
	temp = 0;

	/*OSPEED*/
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_SPEED << 2 * (pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER));
	pGPIOHandle ->pGPIOx ->OSPEEDR &= ~(0x3U << (2 * pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER));
	pGPIOHandle ->pGPIOx ->OSPEEDR |= temp;
	temp = 0;

	/*PUPD*/
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_PUPD << 2 * (pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER));
	pGPIOHandle ->pGPIOx ->PUPDR &= ~(0x3U << (2  * pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER));
	pGPIOHandle ->pGPIOx ->PUPDR |= temp;
	temp = 0;

	/*AF*/

	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_MODE == GPIO_PIN_MODE_AF)
	{
		uint32_t temp1, temp2;
		temp1 = pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER / 8;
		temp2 = pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_NUMBER % 8;
		pGPIOHandle ->pGPIOx->AF[temp1] &= ~(0xFU << (4U * temp2));
		pGPIOHandle ->pGPIOx ->AF[temp1] |= pGPIOHandle ->GPIO_PinConfig.GPIO_PIN_AFMODE << (4U * temp2);
	}


}

void WriteOutputToPin(GPIO_RegDef_t *pGPIOx, uint8_t pin_number, uint8_t Value){
	if(Value == GPIO_PIN_SET){
		pGPIOx ->ODR |= (1U << pin_number);
	}
	else
	{
		pGPIOx ->ODR &= ~(1U << pin_number);
	}
}
void TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t pin_number){
	pGPIOx ->ODR ^= (1 << pin_number);
}

void WriteOutputToPort(GPIO_RegDef_t *pGPIOx, uint8_t Value){
	pGPIOx ->ODR = Value;
}
uint16_t ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pin_number){
	uint16_t value;
	 value = (uint16_t)((pGPIOx ->IDR >> pin_number) & 0x00000001U);
	 return value;
}
uint16_t ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	 value = (uint16_t)(pGPIOx ->IDR);
	 return value;
}


