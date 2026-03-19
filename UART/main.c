#include "uart.h"

int main() {
    USART2_Init(); // Initialize USART2 for communication
    test_setup(); // Run the test setup to interact with the user
    while (1) {
        
    }
    return 0; 
}