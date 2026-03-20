#ifndef __LED_H
#define __LED_H
#include "stm32f4xx.h"
#include "uart.h"

#define LED_PORT GPIOB
#define LED_PORT_CLK_EN (1U << 1) // Enable clock for GPIOB
#define LED_PIN_RED (1U << 14) // Pin 14 for Red LED
#define LED_PIN_GREEN (1U << 12) // Pin 12 for Green LED
#define LED_PIN_BLUE (1U << 13) // Pin 13 for Blue LED

#define LED_RED_MODE_BIT (1U << 28) // Mode bit for Red LED (Pin 14)
#define LED_GREEN_MODE_BIT (1U << 24) // Mode bit for Green LED (Pin 12)
#define LED_BLUE_MODE_BIT (1U << 26) // Mode bit for Blue LED (Pin 13)

typedef enum {
    RED = 0,
    GREEN = 1,
    BLUE = 2
} LEDColors_Type;
typedef enum {
    OFF = 0,
    ON = 1
} LEDState_Type;
/*Attributes of the LED*/
typedef struct
{
    LEDColors_Type color; // Color of the LED
    LEDState_Type state; // State of the LED (ON/OFF)

} LED_Type;

void Led_ctor(LED_Type * const me, LEDColors_Type _color, LEDState_Type _state);

void Led_setState(LED_Type * const me, LEDState_Type _state);
LEDState_Type Led_getState(LED_Type * const me);
#endif //  __LED_H

