#include "led.h"
#include <stdio.h>


void Led_ctor(LED_Type * const me, LEDColors_Type _color, LEDState_Type _state) {
    me->color = _color; // Initialize the color of the LED
    me->state = _state; // Initialize the state of the LED (ON/OFF)
}

void Led_setState(LED_Type * const me, LEDState_Type _state) {
    me->state = _state; // Set the state of the LED (ON/OFF)
    // printf("The %d Led state is set to %d\n", me->color, me->state);
    switch (me->color)
    {
    case RED:
        printf("Red led is set %d\n",me->state);
        break;
    case GREEN:
        printf("Green led is set %d\n",me->state);
        break;
    case BLUE:
        printf("Blue led is set %d\n",me->state);
        break;
    
    default:
        printf("Invalid LED color\n");
        break;
    }
}

LEDState_Type Led_getState(LED_Type * const me) {
    switch (me->color)
    {
    case RED:
        printf("Red led current state is %d\n", me->state);
        break;
    case GREEN:
        printf("Green led current state is %d\n", me->state);
        break;
    case BLUE:
        printf("Blue led current state is %d\n", me->state);
        break;
    
    default:
        printf("Invalid LED color\n");
        break;
    }
    return me->state; // Return the current state of the LED (ON/OFF)
}