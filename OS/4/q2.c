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

