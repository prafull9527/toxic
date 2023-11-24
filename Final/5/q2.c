#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
char comm[100],*ptr;
char *args[10];
int tot_arg;
int search(char option, char *pattern, char *fname)
{
char buff[100],*ptr;
int cnt;
FILE *fp;
int i;
fp= fopen(fname,"r");
if( fp == NULL )
{
printf("\nUnable to open file");
exit(0);
}
switch(option)
{
case 'a' :
while ( !feof (fp))
{
buff[0] = '\0';
fgets(buff,80,fp);
ptr = strstr(buff,pattern);
if( ptr != NULL )
printf("%s",buff);
}
fclose(fp);
break;
case 'c' : 
cnt=0;
while ( !feof (fp))
{
buff[0] = '\0';
fgets(buff,80,fp);
ptr = strstr(buff,pattern);
while(ptr != NULL )
{
cnt++;
ptr = ptr + strlen(pattern);
ptr = strstr(ptr,pattern);
} 
}
fclose(fp);
printf("\nThe serach string %s occurs %d times",pattern,cnt);
break;

case 'f' : 
while ( !feof (fp))
{
buff[0] = '\0';
fgets(buff,80,fp);
ptr = strstr(buff,pattern);
if( ptr != NULL )
{
printf("%s",buff);
break;
}
}
fclose(fp);
break;
} 
return;
}


main()
{
do
{
printf("myshell $ ");
getcomm();
sep_arg();
take_action();
}
while(1);
}


sep_arg()
{
int i,j;
i = j = tot_arg = 0;

args[tot_arg] = (char*)malloc(sizeof(char) * 20);
for(i=0; comm[i] !='\0' ; i++)
{
if( comm[i] == ' ')
{
args[tot_arg][j] = '\0';
tot_arg++;
args[tot_arg] = (char*)malloc(sizeof(char) * 20);	
j=0;
}
else
{
args[tot_arg][j] =comm[i];
j++;
}
}
	
args[tot_arg][j] = '\0'; 
return;
}
getcomm()
{
int len;
ptr = fgets(comm,80,stdin);
len = strlen(comm);
comm[len-1] = '\0';
return;
}


take_action()
{
char str[100];
pid_t   pid;
int status;

if(strcmp(args[0],"search") == 0 )
search(*args[1],args[2],args[3]);
else
if(strcmp(args[0],"quit") == 0 )
exit(0);				
}



/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]);
void search_command(char *tokens[]);

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("myshell$ ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        // Tokenize the input
        char *tokens[MAX_TOKENS];
        char *token = strtok(input, " ");
        int i = 0;

        while (token != NULL && i < MAX_TOKENS - 1) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        tokens[i] = NULL;

        if (i > 0) {
            if (strcmp(tokens[0], "search") == 0) {
                search_command(tokens);
            } else {
                execute_command(tokens);
            }
        }
    }

    return 0;
}

void execute_command(char *tokens[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

void search_command(char *tokens[]) {
    if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL) {
        printf("Error: Invalid arguments for search command\n");
        return;
    }

    FILE *file = fopen(tokens[3], "r");

    if (file == NULL) {
        perror("File open failed");
        return;
    }

    char line[MAX_INPUT_SIZE];
    int count = 0;

    if (tokens[2][0] == 'a') {
        // Search and print all occurrences of the pattern in the file
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strstr(line, tokens[4]) != NULL) {
                printf("%s", line);
            }
        }
    } else if (tokens[2][0] == 'c') {
        // Count and print the number of occurrences of the pattern in the file
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strstr(line, tokens[4]) != NULL) {
                count++;
            }
        }
        printf("Number of occurrences: %d\n", count);
    } else {
        printf("Error: Invalid search command format\n");
    }

    fclose(file);
}
*/

