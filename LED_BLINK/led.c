#include "led.h"
#include <stdio.h>


void Led_ctor(LED_Type * const me, LEDColors_Type _color, LEDState_Type _state) {
    me->color = _color; // Initialize the color of the LED
    me->state = _state; // Initialize the state of the LED (ON/OFF)

    /*Hardware Initialization*/
    RCC ->AHB1ENR |= LED_PORT_CLK_EN; // Enable clock for GPIOB

    switch(_color) {
        case RED:
            LED_PORT->MODER &= ~LED_RED_MODE_BIT; // Clear mode bits for Red LED
            if(me->state == ON) {
                LED_PORT->ODR |= LED_PIN_RED; // Set the Red LED pin to turn it ON
                printf("Red led is set ON\n");
            } else {
                LED_PORT->ODR &= ~LED_PIN_RED; // Clear the Red LED pin to turn it OFF
                printf("Red led is set OFF\n");
            }
            break;
        case GREEN:
            LED_PORT->MODER &= ~LED_GREEN_MODE_BIT; // Clear mode bits for Green LED
            if(me->state == ON) {
                LED_PORT->ODR |= LED_PIN_GREEN; // Set the Green LED pin to turn it ON
                printf("Green led is set ON\n");
            } else {
                LED_PORT->ODR &= ~LED_PIN_GREEN; // Clear the Green LED pin to turn it OFF
                printf("Green led is set OFF\n");
            }
            break;
        case BLUE:
            LED_PORT->MODER &= ~LED_BLUE_MODE_BIT; // Clear mode bits for Blue LED
            if(me->state == ON) {
                LED_PORT->ODR |= LED_PIN_BLUE; // Set the Blue LED pin to turn it ON
                printf("Blue led is set ON\n");
            } else {
                LED_PORT->ODR &= ~LED_PIN_BLUE; // Clear the Blue LED pin to turn it OFF
                printf("Blue led is set OFF\n");
            }
            break;
        default:
            printf("Invalid LED color\n");
            break;
    }
}

void Led_setState(LED_Type * const me, LEDState_Type _state) {
    me->state = _state; // Set the state of the LED (ON/OFF)

    

    switch(me->color) {
        case RED:
            LED_PORT->MODER &= ~LED_RED_MODE_BIT; // Clear mode bits for Red LED
            if(me->state == ON) {
                LED_PORT->ODR |= LED_PIN_RED; // Set the Red LED pin to turn it ON
                printf("Red led is set ON\n");
            } else {
                LED_PORT->ODR &= ~LED_PIN_RED; // Clear the Red LED pin to turn it OFF
                printf("Red led is set OFF\n");
            }
            break;
        case GREEN:
            LED_PORT->MODER &= ~LED_GREEN_MODE_BIT; // Clear mode bits for Green LED
            if(me->state == ON) {
                LED_PORT->ODR |= LED_PIN_GREEN; // Set the Green LED pin to turn it ON
                printf("Green led is set ON\n");
            } else {
                LED_PORT->ODR &= ~LED_PIN_GREEN; // Clear the Green LED pin to turn it OFF
                printf("Green led is set OFF\n");
            }
            break;
        case BLUE:
            LED_PORT->MODER &= ~LED_BLUE_MODE_BIT; // Clear mode bits for Blue LED
            if(me->state == ON) {
                LED_PORT->ODR |= LED_PIN_BLUE; // Set the Blue LED pin to turn it ON
                printf("Blue led is set ON\n");
            } else {
                LED_PORT->ODR &= ~LED_PIN_BLUE; // Clear the Blue LED pin to turn it OFF
                printf("Blue led is set OFF\n");
            }
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