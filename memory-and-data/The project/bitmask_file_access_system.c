/*In a 'BITMASK FLAG SYSTEM' we use one integer to represent many states that are possible
..Usually we use different integers to store different bits
..Here we use one integers and exploit the way we store integers to create a "mask" allowing us to store many states at once
..We will use:- 
                1.setting a state            - via OR gate as it will force the outcome to be positive(1) regardless thus setting the state
                2.clearing a state           - via AND and NOT gate as it will force the outcome to be 0 regardless
                3.checking a state           - via AND and 1 << by k as the outcome will return only for the state of the required bit
                4.toggling a state           - via XOR and 1 << k 
..
..This project will "simulate" a file access system
.. A file can be given the following functions:- 
                1. Read the file               - bit 0
                2. Write into the file         - bit 1
                3. Executable                  - bit 2
                4. Hidden                      - bit 3
                5. Locked                      - bit 4    
..*/

#include <stdio.h>
#include <stdlib.h>
int Check_Ex(int perms){
    int H = 3,L = 4;//changeable later on 
    if(perms& (1<<H)){ //for hidden file they are not writable
        perms &= (~(1<<1));
    }
    if(perms& (1<<L)){//for locked file they are not writeable, readable or executable
        perms &= (~(1<<0));
        perms &= (~(1<<1));
        perms &= (~(1<<2));
    }
    return perms;
}
int main(){
    int perms = 0b0000;          //initally no state is given
    int n;
    char FILE_NAME[50];
    printf("Enter the file name to be edited:- ");//a crude system for now
    scanf("%s",FILE_NAME);
    printf("....\n");
    printf("Enter the permissions to be granted for the FILE\n");
    printf("to be able to read ?(enter 1 for yes 0 for no):- ");scanf("%d",&n);
    if(n == 1){
        perms|= 1<<0;
    }
    printf("to be able to write ?(enter 1 for yes 0 for no):- ");scanf("%d",&n);
    if(n == 1){
        perms|= 1<<1;
    } 
    printf("to be able to execute ?(enter 1 for yes 0 for no):- ");scanf("%d",&n);
    if(n == 1){
        perms|= 1<<2;
    } 
    printf("Will the file be hidden ?(enter 1 for yes 0 for no):- ");scanf("%d",&n);
    if(n == 1){
        perms|= 1<<3;
    }
    printf("Will the file be locked ?(enter 1 for yes 0 for no):- ");scanf("%d",&n);
    if(n == 1){
        perms|= 1<<4;
    }
    perms = Check_Ex(perms);
    //Setting the bit
    //next part is for checking what permission a file has 
    printf("the file %s has following permissions:-\n",FILE_NAME);
    int temp = perms;
    for(int i = 4; i >=0;i--){
        int p = perms & (1<<i);
        if(p!=0){
            switch (i)
            {
            case 4:
                printf("LOCKED\t");
                break;
            
            case 3:
                printf("HIDDEN\t");
                break;
            
            case 2:
                printf("EXECUTABLE\t");
                break;
            
            case 1:
                printf("Can Write\t");
                break;
            
            case 0:
                printf("Can Read\t");
                break;
            
            default:
                printf("ERR");
                break;
            }
        }
    }
}