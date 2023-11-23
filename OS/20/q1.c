/*SLIP NO.20
.1 Write a C program to implement the shell which displays the command
prompt “myshell$”. It accepts the command, tokenize the command line and
execute it by creating the child process. Also implement the additional
command ‘typeline’ as
typeline -a
filename
:- To print all lines in the file.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100

// Function to tokenize the input command
void tokenizeCommand(char *command, char *tokens[]) {
    int i = 0;
    tokens[i] = strtok(command, " \t\n");

    while (tokens[i] != NULL && i < MAX_TOKENS - 1) {
        i++;
        tokens[i] = strtok(NULL, " \t\n");
    }

    tokens[i] = NULL;
}

// Function to execute the command
void executeCommand(char *tokens[]) {
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
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit normally\n");
        }
    }
}

// Function to implement the 'typeline' command
void typelineCommand(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("fopen");
        return;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];

    while (1) {
        // Display command prompt
        printf("myshell$ ");
        fflush(stdout);

        // Read user input
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        // Remove the newline character from the end of the command
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        tokenizeCommand(command, tokens);

        // Check for the 'typeline' command
        if (tokens[0] != NULL && strcmp(tokens[0], "typeline") == 0) {
            if (tokens[1] != NULL) {
                typelineCommand(tokens[1]);
            } else {
                printf("Usage: typeline filename\n");
            }
        } else if (tokens[0] != NULL) {
            // Execute the command
            executeCommand(tokens);
        }
    }

    return 0;
}

