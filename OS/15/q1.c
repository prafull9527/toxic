SLIP NO.15
/*Q.1 Write a C program to implement the shell. It should display the command
prompt “myshell$”. Tokenize the command line and execute the given
command by creating the child process. Additionally it should interpret the
following ‘list’ commands as
myshell$ list f dirname
:- To print names of all the files in current directory.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

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

void list_files(char *dirname) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
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

        // Check if the 'list' command is used
        if (token_count >= 3 && strcmp(tokens[0], "list") == 0 && strcmp(tokens[1], "f") == 0) {
            // 'list f dirname'
            list_files(tokens[2]);
        } else {
            // Execute the command
            tokens[token_count] = NULL; // Null-terminate the array
            execute_command(tokens);
        }
    }

    return 0;
}

