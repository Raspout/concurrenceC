//cut -f 1,3 -d : < /etc/passwd | sed 's+^\(.*\):\(.*\)+\2:\1+' | sort -n > users
//not working :(
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int tube[2];
    pipe(tube);
    int tube2[2];
    pipe(tube2);


    if (fork() == 0) {
        if (fork() == 0)
        {
            int dest = open("users", O_CREAT|O_WRONLY, 0666);
            close(tube2[1]);
            dup2(tube2[0],0);
            close(tube2[0]);
            dup2(1, dest);
            close(dest);

            execlp("sort","sort","-n",NULL);

        }else{
            close(tube[1]);
            dup2(tube[0],0);
            close(tube[0]);
            
            close(tube2[0]);
            dup2(tube2[1],1);
            close(tube2[1]);
            
            execlp("sed","sed","s+^\\(.*\\):\\(.*\\)+\\2:\\1+",NULL);
            }
    } else {
        int file = open("/etc/passwd", O_RDONLY);
        dup2(file, 0);
        close(file);

        close(tube[0]);
        dup2(1,tube[1]);
        close(tube[1]);
        execlp("cut", "cut", "-f", "1,3", "-d", ":", NULL);
    }
    return 0;
}
