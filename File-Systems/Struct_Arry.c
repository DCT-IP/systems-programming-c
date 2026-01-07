/*Struct in C and arrays of Struct
.. these are user defined data types that is inbuilt of many different data types
.. in C these are used everywhere in non linear DS and some (complicated???) Linear DS
.. since it is a data type, we can make pointers to it and arrays of it.
.. Contigous block of bytes*/
#include <stdio.h>
#include <stdlib.h>
typedef struct SensorDat{ //assuming we r intaking some sensor's data
    int time;
    float temp;
} SenD;
//typedef is used to rename a data type to something else 
//here now instead of writing struct SensorDat we can just type SenD so it is used
int main(){
    SenD *ptr = (SenD*)malloc(3*sizeof(struct SensorDat));//throwback to pointers' folder 3 *.. as we storing 3 separte times
    if (!ptr) {
        printf("Memory allocation failed\n");
        return 1;
    } //basic checks
    /* since we r using pointers here we would have to use -> instead of . operator, . operator is used when declaring in the following way
    .. SenD name[size]; name[i].time = dat and so on 
    .. there is also the concept of nested structs which is basically 
    .. struct A{
    ..   //some data
        struct B{
            //some more data
        };
    .. };
    .. to get from such u need to A'svar.B'svar.datainsideB this will obv be unique to every variable of A
    .. user input is possible but for ease I am hard coding data for user input just 
    .. scanf("%d",(ptr+i)->time) and so on*/
    (ptr+0)->time = 2300;(ptr+0)->temp=16.08;
    (ptr+1)->time= 2400;(ptr+1)->temp = 16.05;
    (ptr+2)->time= 600;(ptr+2)->temp = 12.10;
    //and so on
    printf("Time \t|\ttemperature\n");
    for(int i = 0;i<3;i++){
        printf("%d\t|\t%f\n",(ptr+i)->time,(ptr+i)->temp);
    }
}