/*this program will consist of mainly utilizing inbuilt C functions for file handling
..fopen, fclose, text files and its modes.
..fopen opens a file with a filename or file path along with access modes ....fptr = fopen("FILENAME.TXT","r")
..fclose will close any opened file, it is necessary to do this operation ......fclose(fptr)
..the said modes being 
..                      r - read 
                        w - write, will destroy the original content if the file is already present
                        a - append to eof
                        */
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    fptr = fopen("SOMETEXT.txt","w"); //this will open a file even if it is non existant 
    char dat[50];                     //some data to be inserted string as .txt file
    printf("Enter the data you need inserted in the file(50 words or less):- \n");
    fgets(dat, sizeof(dat), stdin);
    if(fptr==NULL){                  //very basic error handling 
        printf("ERR:File could not be opened.\n");
        exit(-1);                    // to exit as the file could not be opened.
    } else {
        printf("The file is opened.\n"); 
        fputs(dat,fptr);            //writes the whole string in the file, returns 1 if operation is successful, it however will put only one single line
        //the alt for puts can be putc if only to input one single character
        //putw is for numbers
        //fwrite is used to write specific number of bytes in a binary file.
        fputs("\n", fptr);
        fclose(fptr);
        printf("Data successfully written!!!\n");
    }
    
    //ONTO reading
    /*fscanf ->wherever the file pointer points, it will go thru there instead of the screen
    ..fgets ->input as string, safer than gets, for a full line (with whitespace)  , sim we have fgetc
    ..fgetw ->reads a number from file
    ..fread -> specified bytes of data from a .bin*/
    fptr = fopen("SOMETEXT.txt","r");
    char ans[55];
    if(fptr==NULL){                   
        printf("ERR:File could not be opened.\n");
        exit(-1);                    
    } else {
        printf("The file is opened.\n"); 
        while(fgets(ans,55,fptr)){
            printf("%s", ans);
        }
        fclose(fptr);
    }
    
    //apart from this we can also move the file pointer
    fptr = fopen("SOMETEXT.txt","w"); 
    char wat[50];                     
    printf("Enter the data you need inserted in the file(50 words or less):- \n");
    fgets(dat, sizeof(dat), stdin);
    if(fptr==NULL){                  
        printf("ERR:File could not be opened.\n");
        exit(-1);                    
    } else {
        printf("The file is opened.\n"); 
        fputs(wat,fptr);            
        fputs("\n", fptr);
        fseek(fptr, -6, SEEK_END); //SEEK_END will force to search from the end, that is why -6 was used as from the end it will go till -6 bytes
        fputs("EDIT", fptr);
        fclose(fptr);
        printf("Data successfully written!!!\n");
    }
    // to reset one can utilize rewind() feature or just make a new pointer for reading
    //a's showcase was not shown, a will find eof then print the statement that was asked to be appened
    return 0;
}
