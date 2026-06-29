#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_input(char *input, char *argv[])
{
    int argc = 0;
    char *token = strtok(input, " ");
    while(token != NULL && argc < MAX_ARGS - 1)
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    return argc;
}