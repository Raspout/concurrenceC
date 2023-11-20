#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "../dijkstra/dijkstra.h"

#define CLARA 1
#define MICHJULIETTE 2
#define ROMUALD 3

int main() {
    int sem_clara;
    sem_clara = semget(CLARA,1,0);

    int sem_mj;
    sem_mj = semget(MICHJULIETTE,1,0);

    int sem_romu;
    sem_romu = semget(ROMUALD,1,0);

    sem_delete(sem_clara);
    sem_delete(sem_mj);
    sem_delete(sem_romu);


    return 0;
}