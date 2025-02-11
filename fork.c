#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create child process

    if (pid < 0) {  
        perror("Fork failed");  // Error handling
        exit(1);
    } 
    else if (pid == 0) {  
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } 
    else {  
        // Parent process
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(5);  // Give time to observe parent-child relationship
    }

    return 0;
}
