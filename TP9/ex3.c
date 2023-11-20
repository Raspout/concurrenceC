#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int fin = 0;

void bernadette(){
    fin = 1;
}

int main()
{
    
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = bernadette;
    sigaction(SIGINT,&act,NULL);

    while(! fin){
        puts("boucle infini");
        sleep(1);
    }
    return 0;
}

