#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]);
void typeline_command(char *tokens[]);

int main() 
{
char input[MAX_INPUT_SIZE];
while (1) 
{
printf("myshell$ ");
fgets(input, sizeof(input), stdin);
input[strcspn(input, "\n")] = '\0';

char *tokens[MAX_TOKENS];
char *token = strtok(input, " ");
int i = 0;

while (token != NULL && i < MAX_TOKENS - 1) 
{
tokens[i++] = token;
 token = strtok(NULL, " ");
 }
 tokens[i] = NULL;

 if (i > 0) 
 {
 if (strcmp(tokens[0], "typeline") == 0) 
 {
 typeline_command(tokens);
 } 
 else
 {
 execute_command(tokens);
 }
 }
 }
return 0;
}

void execute_command(char *tokens[]) 
{
pid_t pid = fork();

if (pid == -1) {
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0) 
{

if (execvp(tokens[0], tokens) == -1)
 {
perror("Command execution failed");
exit(EXIT_FAILURE);
}
}
else 
{
waitpid(pid, NULL, 0);
}
}


void typeline_command(char *tokens[]) {
if (tokens[1] == NULL) {
printf("Error: Missing arguments for typeline command\n");
return;
}

if (strcmp(tokens[1], "-a") == 0) {
if (tokens[2] != NULL) {
printf("Error: Too many arguments for typeline -a command\n");
return;
}
FILE *file = fopen(tokens[2], "r");
if (file == NULL) {
perror("File open failed");
return;
}

char line[MAX_INPUT_SIZE];
while (fgets(line, sizeof(line), file) != NULL) 
{
printf("%s", line);
}

fclose(file);
}
else if (tokens[2] != NULL && tokens[3] == NULL && tokens[1][0] == '+') 
{
       
int n = atoi(tokens[1] + 1); 
FILE *file = fopen(tokens[2], "r");

if (file == NULL) {
perror("File open failed");
return;
}

char line[MAX_INPUT_SIZE];
int count = 0;

while (count < n && fgets(line, sizeof(line), file) != NULL) 
{
printf("%s", line);
count++;
}
fclose(file);
} 
else 
{
printf("Error: Invalid typeline command format\n");
}
}

