/*
A very minimal Shell in this session
take input -> show input(i.e. affirm it for now) -> exit
thus make a REPL, slowly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// including  header files necessary 
#define MAX_BUFFER_SIZE 1240
char input[MAX_BUFFER_SIZE]; //input buffer

void exit_shell();
void input_loop();

int main(){
    printf("Starting The Shell\n.\n..\n...\n");
    input_loop();
}
void input_loop(){
    printf("\n==============WELCOME TO SHELL V0.1b===============\n");
    while (1)
    {
    //Extra Stuff will be added later
    printf("usr> ");fgets(input, MAX_BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    if(!strcmp(input,""))
    {
        continue;
    } else if(!strcmp(input, "exit") || !strcmp(input,"exit()"))
    {
        exit_shell();
    }
    printf("%s\n", input);
    }
}

void exit_shell(){
    printf("exiting...");
    printf("\n=======================================================\n");
    exit(0);
    //barebones for now, will add stuff
}



/*
Since this is in active development, many old functions may sieze to exist
*/