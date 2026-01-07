/*
.. Structs and File Input/Output
.. as said for RAM it is just bytes laid out,
.. this allows us to copy them from files directly - usecase of fwrite.
.. usecase - fwrite(address to data, size of datastruct used,number of elements used,ptr to file)    -memcpy from RAM to disk
.. usecase - fread(datatobereadinto, size of data struct, number of elements, ptr to file)         -memcpy from disk to RAM
.. this however will restrict us from changing struct order as*
.. struct A{                                             struct B{
..             
..    int a; char c;                                          char c;int a;
.. }                                                     }
.. will be stored as 
.. |a||c||padding|                                         |c| |padding(s)||a|
.. said padding might also get written.
.. multiple structs together are like fixed size record, utilizing append mode will help in writing data efficiently
..
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Snsnr_logger{
    int hrs;
    float temp;
} Snsr;

//we will be using a mode so that the data is appeneded
int main(){
    Snsr d1 = {1300,16.09};
    Snsr d2 = {1400,16.10};
    Snsr d3 = {1500,16.10};
    Snsr ds[]  =  {d1,d2,d3};
    int l = 3;//size of ds
    FILE *fptr = fopen("log_unreal.txt","a");
    if(fptr==NULL){
        printf("Err: Unable to open the file!!!\n");
        return 1;
    }
    for(int i = 0;i < 3;i++){
        fwrite(&ds[i],sizeof(Snsr),1,fptr);
    }
    fclose(fptr);
    printf("Writing of data done!!\n");
    //writing of data done

    FILE *fpr = fopen("log_unreal.txt","r");
    if(fptr==NULL){
        printf("Err: Unable to open the file!!!\n");
        return 1;
    }
    Snsr d;
    while (fread(&d, sizeof(Snsr), 1, fpr) == 1) {
        printf("%d %.2f\n", d.hrs, d.temp);
    }
    fclose(fpr);
}