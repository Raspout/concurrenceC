#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void bye(){
    puts("signal SIGINT reçu");
    exit(1);
}

int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = bye;
    sigaction(SIGINT,&act,NULL);
    while(1){
        puts("boucle infini");
        sleep(1);
    }
    return 0;
}
