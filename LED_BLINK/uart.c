#include "uart.h"
void USART2_Init(void) {
    // Enable the clock access to the USART peripheral
    RCC->APB1ENR |= 0x20000; // Enable USART2 clock (bit 17)
    
    // Enable clock access to port A
    RCC->AHB1ENR |= 0x01; // Enable GPIOA clock (bit 0)
    
    // Enable pins for alternate function (AF7) for USART2, which is PA2 (TX) and PA3 (RX)
    GPIOA->MODER &= ~0x00F0; // Clear mode bits
    GPIOA->MODER |= 0x00A0; // Set to alternate function mode
    
    // Configure the alternate function for the pins to AF7 (USART2)
    GPIOA->AFR[0] &= ~0xFF00; // Clear AF bits
    GPIOA->AFR[0] |= 0x7700; // Set AF7 for PA2 and PA3
    
    // Configure UART parameters
    USART2->BRR = 0x0683; // Set baud rate to 9600 assuming 16 MHz clock
    USART2->CR1 = 0x000C; // Enable transmitter and receiver
    USART2->CR2 |= 0x0000;
    USART2->CR3 |= 0x0000;
    USART2->CR1 |= 0x2000; // Enable USART2
}   

int USART2_Write(int data) {
    while (!(USART2->SR & 0x0080)); // Wait until transmit data register is empty
    USART2->DR = (data & 0xFF); // Send the data
    return data;
}

int USART2_Read(void) {
    while (!(USART2->SR & 0x0020)); // Wait until data is received
    return USART2->DR; // Return the received data
}

struct __FILE {int handle; };
FILE __stdin{0};  // Standard input
FILE __stdout{1}; // Standard output
FILE __stderr{2}; // Standard error

int fgetc(FILE *f) {
    int c;
    c = USART2_Read(); // Read a character from USART2
    if(c == '\r') { // Convert carriage return to newline
        c = '\n';
    }   
    USART2_Write(c); // Echo the character back
    return c;
}
int fputc(int c, FILE *f) {
    return USART2_Write(c); // Write a character to USART2
}

void test_setup(void) {
    printf("please enter a number: ");
    scanf("%d", &n); // Read a number from the user
    printf("you entered: %d\n", n); // Print the entered number
    printf("please type a string: ");
    gets(str); // Read a string from the user
    printf("you entered: %s\n", str); // Print the entered string
    puts(str); // Echo the string back
    printf("returning from test_setup\n");
}
