/*
We will be simulating a peripheral status register 
so, a single int(uint32_t) will store the status of the whole hardware

We will create masks and use helper functions
READY 
BUSY 
ERROR
DATA_AVAILABLE
*/
#include <stdio.h>
#include <stdint.h>

#define READY (1U << 0)
#define BUSY (1U << 1)
#define ERROR (1U << 2)
#define DATA_AVAILABLE (1U << 3)

//global var for storing status 
uint32_t STATUS = 0; //indicates nothing 
void print_status(void)
{
    printf("READY: %s\n",
           check_status(READY) ? "YES" : "NO");

    printf("BUSY: %s\n",
           check_status(BUSY) ? "YES" : "NO");

    printf("ERROR: %s\n",
           check_status(ERROR) ? "YES" : "NO");

    printf("DATA_AVAILABLE: %s\n",
           check_status(DATA_AVAILABLE) ? "YES" : "NO");

    printf("RAW STATUS: 0x%08X\n", STATUS);
}

void set_flag(uint32_t Mask){
    STATUS |= Mask;
}

void toggle_flag(uint32_t status_change){
    STATUS ^= status_change;
}

void clear_flag(uint32_t mask){
    STATUS &= ~mask; //lmao
}

int check_status(uint32_t mask){
    return (STATUS&mask) != 0;
}
int main(void)
{
    printf("=== DEVICE BOOT ===\n");
    print_status();

    printf("\n[EVENT] Device Ready\n");
    set_flag(READY);
    print_status();

    printf("\n[EVENT] Processing Started\n");
    set_flag(BUSY);
    print_status();

    printf("\n[EVENT] Error Occurred\n");
    set_flag(ERROR);
    print_status();

    printf("\n[EVENT] Error Cleared\n");
    clear_flag(ERROR);
    print_status();

    printf("\n[EVENT] Data Available\n");
    set_flag(DATA_AVAILABLE);
    print_status();

    printf("\n=== FINAL STATUS CHECK ===\n");

    printf("READY: %s\n",
           check_status(READY) ? "SET" : "NOT SET");

    printf("BUSY: %s\n",
           check_status(BUSY) ? "SET" : "NOT SET");

    printf("ERROR: %s\n",
           check_status(ERROR) ? "SET" : "NOT SET");

    printf("DATA_AVAILABLE: %s\n",
           check_status(DATA_AVAILABLE) ? "SET" : "NOT SET");

    return 0;
}