
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


        int new_priority = nice(10); 
        if (new_priority == -1) {
            perror("Nice failed");
            exit(EXIT_FAILURE);
        }

        printf("Child Process: Priority increased. New Nice Value = %d\n", new_priority);

        
        for (int i = 0; i < 1000000; ++i) {
          
        }

        printf("Child Process: Exiting\n");
    } else {
       
        printf("Parent Process: PID = %d\n", getpid());

     
        wait(NULL);

        printf("Parent Process: Child completed\n");
    }

    return 0;
}

