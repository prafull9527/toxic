/*Q.1 Write a C Program to create a child process using fork (), display parent and
child process id. Child process will display the message “I am Child Process”
and the parent process should display “I am Parent Process”*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("I am Child Process. My PID is %d\n", getpid());
    } else {
        // Parent process
        printf("I am Parent Process. My PID is %d\n", getpid());
    }

    return 0;
}

