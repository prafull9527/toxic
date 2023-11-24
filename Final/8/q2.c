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

void search_first_occurrence(char *filename, char *pattern);
void search_count_occurrences(char *filename, char *pattern);

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];
    char *token;
    char *prompt = "myshell$ ";

    while (1) {
        printf("%s", prompt);
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }

        // Tokenize the input
        int token_count = 0;
        token = strtok(input, " \t\n");
        while (token != NULL && token_count < MAX_TOKENS - 1) {
            tokens[token_count++] = token;
            token = strtok(NULL, " \t\n");
        }
        tokens[token_count] = NULL;

        // Check for the exit command
        if (token_count > 0 && strcmp(tokens[0], "exit") == 0) {
            break;
        }

        // Check for the search command
        if (token_count > 2 && strcmp(tokens[0], "search") == 0) {
            char *filename = tokens[2];
            char *pattern = tokens[3];

            if (token_count > 4 && strcmp(tokens[1], "f") == 0) {
                search_first_occurrence(filename, pattern);
            } else if (token_count > 4 && strcmp(tokens[1], "c") == 0) {
                search_count_occurrences(filename, pattern);
            } else {
                printf("Invalid search command.\n");
            }
        } else {
            // Fork a child process
            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                // Child process
                if (execvp(tokens[0], tokens) == -1) {
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
            } else {
                // Parent process
                wait(NULL);
            }
        }
    }

    printf("Exiting shell.\n");
    return 0;
}

void search_first_occurrence(char *filename, char *pattern) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_INPUT_SIZE];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            found = 1;
            printf("First occurrence of '%s' in file '%s':\n%s", pattern, filename, line);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Pattern '%s' not found in file '%s'\n", pattern, filename);
    }
}

void search_count_occurrences(char *filename, char *pattern) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_INPUT_SIZE];
    int occurrences = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *pos = line;
        while ((pos = strstr(pos, pattern)) != NULL) {
            occurrences++;
            pos += strlen(pattern);
        }
    }

    fclose(file);

    printf("Occurrences of '%s' in file '%s': %d\n", pattern, filename, occurrences);
}
*/
