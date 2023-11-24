
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

        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());


        printf("Child Process: Doing some work...\n");
        sleep(2);
        printf("Child Process: Work completed\n");
    } else {

        printf("Parent Process: PID = %d\n", getpid());


        printf("Parent Process: Terminating\n");
    }

    return 0;
}

