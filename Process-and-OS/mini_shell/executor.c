#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "executor.h"

void execute_command(char *argv[])
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return;
    }
    else if(pid == 0)
    {
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}