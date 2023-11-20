#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int user(int signo){
    if (signo == SIGUSR1){
        puts("Coucou papa :)");
    }
    if (signo == SIGUSR2){
        puts("bye");
        exit(1);
    }
    

}


int main()
{
    int son = fork();
    if (son)
    {
        struct sigaction act;
	    memset(&act,0,sizeof(act));
	    act.sa_handler = user;
        sigaction(SIGUSR1,&act,NULL);
        sigaction(SIGUSR2,&act,NULL);

    }
    else{
        int i = 0;
        while (i == 5)
        {
            i += 1;
            puts("Bonjour fils !");
            if (i == 3)
            {
                kill(son, SIGUSR1);
            }
            if (i == 5)
            {
                kill(son, SIGUSR2);
            }
            sleep(1);
        }
        
    }
    return 0;
}
