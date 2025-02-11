#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) 
    {
        printf("Child Process: PID = %d is terminating...\n", getpid());
        exit(0);
    } 
    else 
    {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(10);  
    }

    return 0;
}
