/*SLIP NO.13
Q.1 Write a C program to implement the shell which displays the command
prompt “myshell$”. It accepts the command, tokenize the command line and
execute it by creating the child process. Also implement the additional
command ‘typeline’ as
typeline -a
filename :- To print all lines in the file*/
#include <stdio.h>
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
        // Child process
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
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

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        int token_count = 0;
        token = strtok(command, " ");

        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the 'typeline' command is used
        if (token_count >= 2 && strcmp(tokens[0], "typeline") == 0) {
            if (strcmp(tokens[1], "-a") == 0 && token_count >= 3) {
                // 'typeline -a filename'
                typeline_command(tokens[2], 1);
            } else {
                // 'typeline filename'
                typeline_command(tokens[1], 0);
            }
        } else {
            // Execute the command
            tokens[token_count] = NULL; // Null-terminate the array
            execute_command(tokens);
        }
    }

    return 0;
}

