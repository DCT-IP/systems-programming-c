/*We trying to simulate a UART peripheral
UART peripheral:
 CTRL Register
 STATUS Register
 DATA Register

UART stands for Universal Asynchronous Receiver/Transmitter and is a hardware communication protocol used for serial data exchange between two devices.  
It operates asynchronously, meaning it does not use a shared clock signal; instead, 
both transmitter and receiver must be configured with the same baud rate (e.g., 9600, 115200) and frame structure to synchronize data sampling
UART boots
↓
CTRL ENABLED
↓
Send Data to DATA
↓
Transmission Starts (Set Busy inside Status)
↓
Transmission completes (Clear BUSY)
*/

#include <stdio.h>
#include <stdint.h>

//our peripherals
typedef struct {
    uint32_t CTRL;
    uint32_t STATUS;
    uint32_t DATA;
} UART_Reg;

//macros for masks
#define UART_ENABLE   (1U << 0)
#define UART_INTERRUPT  (1U << 1)
#define UART_BUSY       (1U << 0)
#define UART_ERROR      (1U << 1)

void print_registers(UART_Reg *uart)
{
    printf("CTRl: 0x%08X\n", uart->CTRL);
    printf("STATUS: 0x%08X\n", uart->STATUS);
    printf("DATA: 0x%08X\n", uart->DATA);
}

int main()
{
    UART_Reg uart = {0};
    printf("====UART BOOT====\n");
    uart.CTRL |= UART_ENABLE;
    print_registers(&uart);

    printf("\nSending A\n");
    uart.DATA = 'A';
    uart.STATUS |= UART_BUSY;
    print_registers(&uart);

    printf("\nTransmission Complete\n");
    uart.STATUS &= ~UART_BUSY;
    print_registers(&uart);

    return 0;
}