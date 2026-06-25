/*
 Simulate a hardware event changing a variable 
 No real interrupt
 
*/
#include <stdio.h>

volatile int sensor_ready = 0;

void wait_for_sensor()
{
    printf("Waiting for sensor...\n");
    if(sensor_ready == 0)
    {
        printf("Sensor not ready\n");
    }
    else
    {
        printf("Sensor ready\n");
    }
}

void sensor_interrupt()
{
    printf("\nInterrupt Received\n");
    sensor_ready = 1;
}

int main()
{
    printf("=== PROGRAM START ===\n\n");
    wait_for_sensor();
    sensor_interrupt();
    printf("\n");
    wait_for_sensor();
    return 0;
}