/*Q.2 Write a program to implement the shell. It should display the command
prompt “myshell$”. Tokenize the command line and execute the given
command by creating the child process. Additionally it should interpret the
following ‘list’ commands as
myshell$ list f dirname
:- To print names of all the files in current
directory.
myshell$ list n dirname :- To print the number of all entries in the current
directoryQ.1)myshell*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

void count(char *cm,char *file){
    char cd;
    int fn =open(file,O_RDONLY);
    int lineCount=0,wordCount=0,charCount=0;

    while(read(fn,&cd,1)>0){
        if(cd=='\n')
        lineCount++;
       else if(cd==' ')
        wordCount++;
        else
        charCount++;        
    }
    if(strcmp(cm,"c")==0){
        printf("The number of characters in the file are %d\n",charCount);
    }
    if(strcmp(cm,"w")==0){
        printf("The number of words in the file are %d\t",wordCount);
    }
    if(strcmp(cm,"l")==0){
        printf("The number of lines in the file are %d\n",lineCount);
    }
}

int main(void)
{
    char cmd[80],op1[20],op2[20],op3[30];
    while(1){
        printf("\n MyShell $ ");
        scanf("%c",cmd);
        int pid=fork();
        if(pid==-1){
            printf("Error\n");
        }
        else if(pid > 1){
            wait(NULL);
        }
        else{

        int n=sscanf(cmd,"%s %s %s",op1,op2,op3);
        if(strcmp(op1,"count")==0){
            count(op2,op3);
            exit(0);
        }

        }
    }
}

