//s12 q1
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100
void execute_command(char *tokens[]) {
pid_t pid = fork();
if (pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
execvp(tokens[0], tokens);
perror("execvp");
exit(EXIT_FAILURE);
} else {
waitpid(pid, NULL, 0);
}
}
void typeline_command(char *filename, int append) {
FILE *file;
char line[MAX_COMMAND_LENGTH];
if (append) {
file = fopen(filename, "a");
} else {
file = fopen(filename, "r");
}
if (file == NULL) {
perror("fopen");
return;
}
while (fgets(line, sizeof(line), file) != NULL) {
printf("%s", line);
}
fclose(file);
}
int main() {
char command[MAX_COMMAND_LENGTH];
char *tokens[MAX_TOKENS];
char *token;
while (1) {
printf("myshell$ ");
fgets(command, sizeof(command), stdin);
command[strcspn(command, "\n")] = '\0';
int token_count = 0;
token = strtok(command, " ");
while (token != NULL) {
tokens[token_count++] = token;
token = strtok(NULL, " ");
}
if (token_count >= 2 && strcmp(tokens[0], "typeline") == 0) {
if (strcmp(tokens[1], "-a") == 0 && token_count >= 3) {
typeline_command(tokens[2], 1);
} else {
typeline_command(tokens[1], 0);
}
} else {
tokens[token_count] = NULL; 
execute_command(tokens);
}
}
return 0;
}