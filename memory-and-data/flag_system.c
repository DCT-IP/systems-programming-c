// The system has states 
/*
WIFI Connected?
Sensor Active? 
Data Ready?
Error Present?
we'll use uintN_t and bits to represent each state, 
just like our bitmask system

We'll have to show 
set flag, 
clear flag,
toggle flag,
check flag

a sim at end will follow:
System Boot
↓
WiFi Connects
↓
Sensor Turns On
↓
Error Occurs
↓
Error Cleared
↓
Data Ready || Then, we'll(meee:3) print every flag
*/

#include <stdio.h>
#include <stdint.h>

#define WIFI_CONNECTED (1U << 0)
#define SENSOR_ACTIVE  (1U << 1)
#define ERROR_PRESENT  (1U << 2)
#define DATA_READY     (1U << 3)
//1U as we using uint not int ;-;
uint32_t system_flags = 0; // global system flags

void system_status()
{ // prints the system's status
    printf("WIFI CONNECTED: %s\n", (system_flags & WIFI_CONNECTED)? "YES":"NO");
    printf("SENSOR ACTIVE: %s\n", (system_flags & SENSOR_ACTIVE)? "YES":"NO");
    printf("ERROR PRESENT: %s\n", (system_flags & ERROR_PRESENT)? "YES":"NO");
    printf("DATA READY: %s\n", (system_flags & DATA_READY)? "YES":"NO");
    printf("Raw Hex Value: 0x%08X", system_flags);
} //function ends 

/*
for now we are hardcoding, usually it is:
System Boot
↓
system_flags = 0

WiFi Connected
↓
set_flag(WIFI_CONNECTED)

Sensor Activated
↓
set_flag(SENSOR_ACTIVE)

Error Occurs
↓
set_flag(ERROR_PRESENT)

Error Cleared
↓
clear_flag(ERROR_PRESENT)

Data Ready
↓
set_flag(DATA_READY)
*/
void set_flag(uint32_t mask)
{
    system_flags |= mask;
}

void toggle_flag(uint32_t mask)
{
    system_flags ^= (mask);
}

void clear_flag(uint32_t mask)
{
    system_flags &= ~(mask);
}

int check_flag(uint32_t mask)
{
    return (system_flags & mask) != 0;
}

int main(void)
{
    printf("=== SYSTEM BOOT ===\n");
    system_status();

    printf("\n[EVENT] WiFi Connected\n");
    set_flag(WIFI_CONNECTED);
    system_status();

    printf("\n[EVENT] Sensor Activated\n");
    set_flag(SENSOR_ACTIVE);
    system_status();

    printf("\n[EVENT] Error Occurred\n");
    set_flag(ERROR_PRESENT);
    system_status();

    printf("\n[EVENT] Error Cleared\n");
    clear_flag(ERROR_PRESENT);
    system_status();

    printf("\n[EVENT] Data Ready\n");
    set_flag(DATA_READY);
    system_status();

    printf("\n=== FINAL CHECK ===\n");

    printf("WiFi: %s\n",
           check_flag(WIFI_CONNECTED) ? "SET" : "NOT SET");

    printf("Sensor: %s\n",
           check_flag(SENSOR_ACTIVE) ? "SET" : "NOT SET");

    printf("Error: %s\n",
           check_flag(ERROR_PRESENT) ? "SET" : "NOT SET");

    printf("Data Ready: %s\n",
           check_flag(DATA_READY) ? "SET" : "NOT SET");

    return 0;
}