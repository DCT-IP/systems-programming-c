/*
A very minimal Shell in this session
take input -> show input(i.e. affirm it for now) -> exit
thus make a REPL, slowly.
Now we are Adding parsing to this, basically, wtv is read will be sent to a 
parser, that'll read it and send it back for now, next session will see it being 
actually acted on
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
// including  header files necessary 
#define MAX_BUFFER_SIZE 1240
char input[MAX_BUFFER_SIZE]; //input buffer
char *argv[MAX_ARGS];

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
        int argc = parse_input(input, argv);

        printf("\nArguments Parsed\n");
        printf("---------------------\n");
        printf("argc = %d\n\n", argc);

        for(int i = 0; i < argc; i++)
        {
            printf("argv[%d] = %s\n", i, argv[i]);
        }

        printf("\n");
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