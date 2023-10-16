#include <stdio.h>
#include <sys/sem.h>

#define CLE 1234

int main()
{   
    int semid;
    semid = semget((key_t)CLE, 4, IPC_CREAT|IPC_EXCL|0666);
    printf(" le semid de l'ensemble de semaphore est : %d\n",semid) ;
    printf(" cet ensemble est identifie par la cle unique : %d\n" , (key_t)CLE) ;
    return 0;
}

