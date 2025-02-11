#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(5);  // Sleep to keep running after parent exits
        printf("Child Process: New Parent PID = %d\n", getppid());
    } 
    else {
        // Parent process exits immediately
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        exit(0);
    }

    return 0;
}
