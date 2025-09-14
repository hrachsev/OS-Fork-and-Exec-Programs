#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
    pid_t pid1, pid2;


    pid1 = fork();
    if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
	exit(1);
    }


    pid2 = fork();
    if (pid2 == 0) {
        execl("/bin/date", "date", NULL);
	exit(1);
    }

	wait(NULL);
	wait(NULL);


    printf("Parent process done (PID = %d)\n", getpid());

    return 0;
}
