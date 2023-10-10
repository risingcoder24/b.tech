#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int num_processes = 10;
    
    for (int i = 0; i < num_processes; i++) {
        pid_t pid = fork(); // Create a new child process
        
        if (pid == 0) { // Child process
            printf("Hello, World! (Process %d)\n", i);
            exit(0); // Exit the child process
        } else if (pid < 0) {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        }
    }
    
    // Parent process waits for all child processes to finish
    int status;
    pid_t child_pid;
    while ((child_pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("Child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }
    }
    
    return 0;
}
