#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void bye(){
    puts("bye");
    exit(1);
}

int main()
{
    int son = fork();
    if (son)
    {
        struct sigaction act;
	    memset(&act,0,sizeof(act));
	    act.sa_handler = bye;
	    sigaction(SIGTERM,&act,NULL);
        while (1)
        {
            puts("Coucou papa :)");
            sleep(1);
        }
    }
    else{
        for (size_t i = 0; i < 5; i++)
        {
            puts("Bonjour fils !");
            sleep(1);
        }
        kill(son, SIGTERM);
    }
    return 0;
}
