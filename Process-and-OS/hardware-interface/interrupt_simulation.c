/*
Here, the opposite of polling happens, the hardware tells cpu,
causing ISR to handle the signal i.e. interrupt
*/

#include <stdio.h>

volatile int interrupt_flag = 0;

void ISR(void)
{
    printf("\n>>> INTERRUPT OCCURRED <<<\n");

    interrupt_flag = 1;
}

int main(void)
{
    printf("=== INTERRUPT SIMULATION ===\n\n");

    for(int i = 1; i <= 5; i++)
    {
        printf("Doing Work %d\n", i);

        if(i == 3)
        {
            ISR();
        }

        if(interrupt_flag)
        {
            printf("Handling interrupt event\n");

            interrupt_flag = 0;
        }
    }

    printf("\nProgram Complete\n");

    return 0;
}