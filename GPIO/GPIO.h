/*
 * GPIO.h
 *
 *  Created on: 7 Oct 2026
 *      Author: chandrasekharmoravaneni
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "stm32f4xx.h"


/* Possible GPIO pin modes*/

typedef struct{
	uint8_t GPIO_PIN_NUMBER;
	uint8_t GPIO_PIN_MODE;
	uint8_t GPIO_PIN_SPEED;
	uint8_t GPIO_PIN_PUPD;
	uint8_t GPIO_PIN_OPODType;
	uint8_t GPIO_PIN_AFMODE;

}GPIO_PinConfig_t;

/* Pointer to hold the base address of the GPIOx Peripheral*/

typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;

/* GPIO Pin number*/

#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7
#define GPIO_PIN_8		8
#define GPIO_PIN_9		9
#define GPIO_PIN_10		10
#define GPIO_PIN_11		11
#define GPIO_PIN_12		12
#define GPIO_PIN_13		13
#define GPIO_PIN_14		14
#define GPIO_PIN_15		15

/* GPIO possible modes*/
#define GPIO_PIN_MODE_IN		0
#define GPIO_PIN_MODE_OUT		1
#define GPIO_PIN_MODE_AF		2
#define GPIO_PIN_MODE_ANALOG	3

/* GPIO possible OP type*/
#define GPIO_OP_TYPE_OP      0
#define GPIO_OP_TYPE_OD      1

/* GPIO possible output speed register*/
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/*GPIO pull-up/pull-down register*/
#define GPIO_NO_PUPD		0
#define GPIO_PU				1
#define GPIO_PD				2

// Enable the Clock
void GPIO_PCLK_CONTROL(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
uint16_t ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pin_number);
uint16_t ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void WriteOutputToPin(GPIO_RegDef_t *pGPIOx, uint8_t pin_number, uint8_t Value);
void WriteOutputToPort(GPIO_RegDef_t *pGPIOx, uint8_t Value);
void TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t pin_number);

#endif /* GPIO_GPIO_H_ */
