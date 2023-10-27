#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("boucle %d : pid=%d, ppid=%d, fork()=%d\n", i+1, getpid(), getppid(), fork());
    }
    return 0;
}
