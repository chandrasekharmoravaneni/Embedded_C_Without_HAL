#include"led.h"

LED_Type led1;
LED_Type led2;
LED_Type led3;

int main(void)
{
    USART2_Init(); // Initialize USART2 for communication
    Led_ctor(&led1, RED, OFF); // Initialize the LED with color RED and state OFF
    Led_ctor(&led2, GREEN, OFF); // Initialize the LED with color GREEN and state OFF
    Led_ctor(&led3, BLUE, OFF); // Initialize the LED with color BLUE and state OFF
    while (1)
    {
        Led_setState(&led1, ON); // Set the LED state to ON
        Led_setState(&led2, ON); // Set the LED state to ON
        Led_setState(&led3, ON); // Set the LED state to ON
        Led_getState(&led1); // Get the current state of the LED
        Led_getState(&led2); // Get the current state of the LED
        Led_getState(&led3); // Get the current state of the LED
        for (int i = 0; i < 1000000; i++); // Delay loop

        Led_setState(&led1, OFF); // Set the LED state to OFF
        Led_setState(&led2, OFF); // Set the LED state to OFF
        Led_setState(&led3, OFF); // Set the LED state to OFF
        Led_getState(&led1); // Get the current state of the LED
        Led_getState(&led2); // Get the current state of the LED
        Led_getState(&led3); // Get the current state of the LED
        for (int i = 0; i < 1000000; i++); // Delay loop
    }
    
    return 0;
}