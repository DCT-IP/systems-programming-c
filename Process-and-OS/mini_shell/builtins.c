#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtins.h"

int handle_builtin(char *argv[])
{
    // Empty command
    if(argv[0] == NULL)
        return 1;

    // exit
    if(strcmp(argv[0], "exit") == 0)
    {
        printf("Exiting Shell...\n");
        exit(0);
    }

    // help
    if(strcmp(argv[0], "help") == 0)
    {
        printf("\n===== Mini Shell Help =====\n");
        printf("Built-in Commands:\n");
        printf("  help        Show this help menu\n");
        printf("  pwd         Print current directory\n");
        printf("  cd <dir>    Change directory\n");
        printf("  exit        Exit the shell\n");
        printf("===========================\n\n");

        return 1;
    }

    // pwd
    if(strcmp(argv[0], "pwd") == 0)
    {
        char cwd[1024];

        if(getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s\n", cwd);
        else
            perror("pwd");

        return 1;
    }

    // cd
    if(strcmp(argv[0], "cd") == 0)
    {
        if(argv[1] == NULL)
        {
            printf("Usage: cd <directory>\n");
        }
        else
        {
            if(chdir(argv[1]) != 0)
                perror("cd");
        }

        return 1;
    }

    return 0; //did not find any built-ins
}