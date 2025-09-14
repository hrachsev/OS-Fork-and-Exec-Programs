#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork(); 

    if (pid == 0) {

        execl("/bin/ls", "ls", NULL); 
	exit(1);

    } else {

	wait(NULL);

        printf("Parent process done\n");
    }

    return 0;
}
