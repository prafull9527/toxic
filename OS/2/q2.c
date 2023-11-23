#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]);
void list_command(char *tokens[]);

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
            if (strcmp(tokens[0], "list") == 0) {
                list_command(tokens);
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

void list_command(char *tokens[]) {
    if (tokens[1] == NULL || tokens[2] == NULL) {
        printf("Error: Invalid arguments for list command\n");
        return;
    }

    if (strcmp(tokens[1], "f") == 0) {
        // List names of all files in the current directory
        DIR *dir;
        struct dirent *entry;

        if ((dir = opendir(tokens[2])) != NULL) {
            while ((entry = readdir(dir)) != NULL) {
                if (entry->d_type == DT_REG) {
                    printf("%s\n", entry->d_name);
                }
            }
            closedir(dir);
        } else {
            perror("Directory open failed");
        }
    } else if (strcmp(tokens[1], "n") == 0) {
        // List the number of all entries in the current directory
        DIR *dir;
        struct dirent *entry;
        int count = 0;

        if ((dir = opendir(tokens[2])) != NULL) {
            while ((entry = readdir(dir)) != NULL) {
                count++;
            }
            closedir(dir);
            printf("Number of entries: %d\n", count);
        } else {
            perror("Directory open failed");
        }
    } else {
        printf("Error: Invalid list command format\n");
    }
}

