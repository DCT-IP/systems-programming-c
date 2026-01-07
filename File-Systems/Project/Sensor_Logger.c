#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Sensor_Dat
{
    int id;
    float value; //arbitrary name can be anything we want it to be
    time_t timestamp;
} Sensor;

void log_Dat(Sensor r){
    FILE *fp = fopen("Sensor_Logs.bin","ab");
    if(fp==NULL){
        printf("There was some error opening the file!!!\n");
        exit(1);
    }
    fwrite(&r,sizeof(struct Sensor_Dat),1,fp);
    printf("Log entered!\n");
    fclose(fp);
}//logger function

void read(){
    FILE *fp = fopen("Sensor_Logs.bin","rb");
    if(fp==NULL){
        printf("There was some error opening the file!!!\n");
        exit(1);
    }
    Sensor r;
    while (fread(&r, sizeof(struct Sensor_Dat), 1, fp)) {
        printf("Sensor %d | Value %.2f | Time %ld\n",r.id, r.value, r.timestamp);
    }
    fclose(fp);
}//reader function

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage(Extremely Case Sensitive):- \n");
        printf("To log :   ./Sensor_Logger log <id> <val>");
        printf("\nTo read : ./Sensor_Logger read ");
        return 1;
    }

    if(strcmp(argv[1],"log")==0){
        Sensor r;
        r.id = atoi(argv[2]);
        r.value = atoi(argv[3]);
        r.timestamp = time(NULL);
        log_Dat(r);
    printf("Logged at %d",r.timestamp);
    }
    else if(strcmp(argv[1],"read")==0){
        read();
    } else {
        printf("Err: Invalid Usage");
        printf("Usage(Extremely Case Sensitive):- \n");
        printf("To log :   ./Sensor_Logger log <id> <val>");
        printf("\nTo read : ./Sensor_Logger read <file>");
        return 1;
    }
}