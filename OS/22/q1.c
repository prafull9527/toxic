/*Q.1 Write a C program that demonstrates the use of nice() system call. After a
child Process is started using fork (), assign higher priority to the child using
nice () system call.*/


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

        // Increase priority using nice()
        int new_priority = nice(10); // The priority can be adjusted according to the system limits
        if (new_priority == -1) {
            perror("Nice failed");
            exit(EXIT_FAILURE);
        }

        printf("Child Process: Priority increased. New Nice Value = %d\n", new_priority);

        // Child process does some work
        for (int i = 0; i < 1000000; ++i) {
            // Simulating some work
        }

        printf("Child Process: Exiting\n");
    } else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());

        // Wait for the child to finish
        wait(NULL);

        printf("Parent Process: Child completed\n");
    }

    return 0;
}

