/*
GPIO = General-Purpose Input Output
has states 
HIGH, 
LOW
in our sim:-
 we'll have a single pin here
 set high and set low functions will be used 
 a read function to read the pin

This is quite and easy job
*/
#include <stdio.h>

int gpio_pin = 0;

void set_high(){
    gpio_pin = 1;
}

void set_low(){
    gpio_pin = 0;
}

int read_pin(){
    return gpio_pin;
}

void print_state()
{
    printf("GPIO PIN STATUS: %d\n", read_pin());

    if(read_pin())
        printf("LED: ON\n");
    else
        printf("LED: OFF\n");
}

int main(void)
{
    printf("=== GPIO SIMULATION ===\n");

    printf("\nSystem Boot\n");
    print_state();

    printf("\nTurning LED ON\n");
    set_high();
    print_state();

    printf("\nReading Pin...\n");
    printf("Pin Value: %d\n", read_pin());

    printf("\nTurning LED OFF\n");
    set_low();
    print_state();

    printf("\nReading Pin...\n");
    printf("Pin Value: %d\n", read_pin());

    return 0;
}