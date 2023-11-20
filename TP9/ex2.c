#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    sigaction(SIGINT,&act,NULL);
    while(1){
        puts("boucle infini");
        sleep(1);
    }
    return 0;
}
