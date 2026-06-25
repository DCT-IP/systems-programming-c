/*
We know, register = Mem Location
we already have done a simulation of UART, so 
our sim:
 system boot
     ↓
 CLTR = 1
     ↓
 STATUS = 1
     ↓
 DATA = 65('A')
*/

#include <stdio.h>
#include <stdint.h>

typedef struct {
   volatile uint32_t CTRL;
   volatile uint32_t STATUS;
   volatile uint32_t DATA;
} UART_Reg;


//no macros, we'll hardcode this as our main mission is regardin regs

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
    uart.CTRL = 1;
    print_registers(&uart);

    printf("\nSending A\n");
    uart.DATA = 'A';
    uart.STATUS = 1;
    print_registers(&uart);

    printf("\nTransmission Complete\n");
    uart.STATUS = 0;
    print_registers(&uart);

    return 0;
}
