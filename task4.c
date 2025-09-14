#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {

        execl("/bin/grep", "grep", "name", "test.txt", NULL);

        exit(1);
    } else {

        wait(NULL);

        printf("Parent process completed\n");
    }

    return 0;
}
