/*
Polling, a method used by cpu to check status of hardware.
cpu basically check status at an interval
*/
#include <stdio.h>

int sensor_ready = 0;

int main(void)
{
    printf("=== POLLING SIMULATION ===\n\n");
    int checks = 0;
    while(sensor_ready == 0)
    {
        printf("Checking sensor...\n");
        checks++;
        if(checks == 5)
        {
            printf("Sensor has finished work.\n");
            sensor_ready = 1;
        }
    }
    printf("\nSensor Ready!\n");
    return 0;
}
/*
This obv is not prefered now as it consumes a lot of cpu power
*/