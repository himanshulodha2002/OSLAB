#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Child process with PID %d\n", getpid());
        
        // Using execlp to replace the child process image with ls command
        execlp("ls", "ls", "-l", NULL); // Executing ls -l command
        
        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        printf("Parent process with PID %d\n", getpid());

        int status;
        wait(&status);
        printf("Child process reaped\n");
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return 0;
}
