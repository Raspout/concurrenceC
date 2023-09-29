//cut -f 1 -d : /etc/passwd | tr a-z A-Z
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){    
    int pip[2];
    pipe(pip);
    int pip2[2];
    pipe(pip2);

    if (fork() == 0){
        close(pip[1]);
        execlp("cut", "cut", "-f", "1", "-d", ":", "/etc/passwd", NULL);
    }
    else{
        close(pip[0]);
    }
}
