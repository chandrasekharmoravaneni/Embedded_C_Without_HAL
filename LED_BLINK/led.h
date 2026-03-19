#ifndef __LED_H
#define __LED_H
#include "stm32f4xx.h"
#include "uart.h"

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

