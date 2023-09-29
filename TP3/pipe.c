//cut -f 1 -d : /etc/passwd | tr a-z A-Z
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
    int tube[2];
    pipe(tube);

    if (fork() == 0) {
        close(tube[1]);
        dup2(tube[0],0);
        close(tube[0]);
        execlp("tr","tr","a-z", "A-Z",NULL);
    } else {
        close(tube[0]);
        dup2(tube[1],1);
        close(tube[1]);
        execlp("cut", "cut", "-f", "1", "-d", ":", "/etc/passwd", NULL);
    }
    return 0;
}
