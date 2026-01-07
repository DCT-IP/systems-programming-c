/*Said file with actual program with usage shown
.. basic idea is -
..                help - prints out help
..                echo - prints a sentence
..                sum - takes in two numbers 
..                write - writes a file with some predefined terms
..                read - reads said file.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help(void);
void echo(int argc, char *argv[]);// we taking it this way because C's compilation nature
void sum(char *a, char *b);//same reason as above, will change to int
void write(char *filename, char *text);//could be const
void read(char *filename);

int main(int argc, char *argv[]){
    //due to nature of CLI, argc has to be greater than 1
    if(argc < 2){
        printf("No commands entered!!\n");
        help();
        return 1;
    }
    //usually CLI_refrn cmd_name ifneededotherstuff  etc
    //         argv[0]   argv[1]       argv[2]      argv[2+]
    if(strcmp(argv[1],"help")==0){
        help();
    } else if(strcmp(argv[1],"echo")==0){
        echo(argc,argv);
    } else if(strcmp(argv[1],"sum")==0){
        if(argc!=4){
            printf("ERR: invalid number of arguments \nUsage CLI_refrn sum <a> <b>\n");
            return 1;
        }
        sum(argv[2],argv[3]);
    } else if(strcmp(argv[1],"write")==0){
        if (argc != 4) {
            printf("Usage: write <file> <text>\n");
            return 1;
        }
        write(argv[2],argv[3]);
    }else if (strcmp(argv[1], "read") == 0) {
        if (argc != 3) {
            printf("Usage: read <file>\n");
            return 1;
        }
        read(argv[2]);
    }
    else {
        printf("Unknown command: %s\n", argv[1]);
        help();
        return 1;
    }

    return 0;
}

void help(){
    printf("Case Sensitive programs!!!\n");
    printf("help:-\n\tCLI_refrn help\n\tShows this command");
    printf("echo:-\n\tCLI_refrn echo <text>(s)\n\tPrints a statement\n");
    printf("sum:-\n\tCLI_refrn sum <a> <b>\n\tGives sum of two numbers\n");
    printf("write:-\n\tCLI_refrn write <filename> <text>\n\twrites into a prexistant file or makes a new one to write into\n");
    printf("read:-\n\tCLI_refrn read <file>\n\tReads from a file, if non existant will give error\n");
}

void echo(int argc, char *argv[]){
    int i = 2;
    for(;i<argc;i++){
        printf("%s ",argv[i]);
    }
    printf("\n");
}

void sum(char *a, char *b){
    int y = atoi(a);
    int x = atoi(b);
    printf("sum of %d and %d is %d\n", y, x, (x+y));
}

void write(char *filename, char *text){
    FILE *fp = fopen(filename,"w");
    if(!fp){
        printf("Err: Could not open file for writing\n");
        return;
    }
    fprintf(fp,"%s\n",text);
    fclose(fp);
}

void read(char *filename){
    FILE *fp = fopen(filename,"r");
    char dat[100];
    if(!fp){
        printf("Err: Could not open file for writing\n");
        return;
    }
    while(fgets(dat,sizeof(dat),fp)){
        printf("%s",dat);
    }
    fclose(fp);
}
/*For running 
gcc file.c -o file(only name)
./file [cmd]*/