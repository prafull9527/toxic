#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        
        printf("I am Child Process. My PID is %d\n", getpid());
    } else {
      
        printf("I am Parent Process. My PID is %d\n", getpid());
    }

    return 0;
}

