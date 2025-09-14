#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Starting program (PID = %d)\n", getpid());

    pid = fork();
    if (pid == 0) {
        printf("Child 1 (PID = %d, Parent PID = %d)\n", getpid(), getppid());
    } else {
        printf("Parent after first fork (PID = %d, Child PID = %d)\n", getpid(), pid);
    }

    pid = fork();
    if (pid == 0) {
        printf("Child 2 (PID = %d, Parent PID = %d)\n", getpid(), getppid());
    } else {
        printf("Parent after second fork (PID = %d, Child PID = %d)\n", getpid(), pid);
    }

    pid = fork();
    if (pid == 0) {
        printf("Child 3 (PID = %d, Parent PID = %d)\n", getpid(), getppid());
    } else {
        printf("Parent after third fork (PID = %d, Child PID = %d)\n", getpid(), pid);
    }

    // Keep processes alive for a while to check the process tree
    sleep(10);

    return 0;
}
