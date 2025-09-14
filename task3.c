#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {

        execl("/bin/echo", "echo", "Hello from the child process", NULL);

        exit(1);
    } else {

        wait(NULL);

        printf("Parent process comepleted\n");
    }

    return 0;
}
