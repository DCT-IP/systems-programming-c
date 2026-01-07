/* Ts a text based UI for viewing and managing computer files
.. this is done so certain specific inputs are given pre running 
.. only save and compile the program, then open the cmd
..One can:-
            Shutdown the pc
                - sprintf is used, it writes formatted data to a string but instead of printing it gets stored in buffer as a C string
                - sptrinf has 3 parameters :- str - ptr to a buffer where resulting string is stored
                                              format - C string with a format string that follows the same specifications as a format
                                              additional arg - depends on format string
                - shutdown file is at C:\\Windows\\System32\\shutdown
            MyPlayer type program
                tbd
.. 
.. CLArg are used to achieve such effects
.. int main(int argc, char *argv[]){.....}
.. argc - > an integer stores the number of command line arguments passed including the name of the program, needs to be non negative
.. argv -> array of strings, listing all the arguments, arrgv[0] is the program name*/
#include <stdio.h>
int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}
/* will continue this in other file*/