#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    if (fork() == 0){
        execlp("du", "du", "-sh", "/usr/share", NULL);
    }
    wait(NULL);

    if (fork() == 0){
        execlp("ls", "ls", "-l", NULL);
    }
    wait(NULL);
    execlp("ps", "ps", NULL);
}
