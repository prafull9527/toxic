/*Q.1 Write a C program to illustrate the concept of orphan process. Parent process
creates a child and terminates before child has finished its task. So child
process becomes orphan process. (Use fork(), sleep(), getpid(), getppid()).*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Simulate some work in the child process
        printf("Child Process: Doing some work...\n");
        sleep(2);
        printf("Child Process: Work completed\n");
    } else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());

        // Parent process terminates before the child finishes its task
        printf("Parent Process: Terminating\n");
    }

    return 0;
}

