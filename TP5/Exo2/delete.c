#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "../dijkstra/dijkstra.h"

#define CLARA 1
#define MICHJULIETTE 2

int main() {
    int sem_clara;
    sem_clara = semget(CLARA,1,0);

    int sem_mj;
    sem_mj = semget(MICHJULIETTE,1,0);

    sem_delete(sem_clara);
    sem_delete(sem_mj);

    return 0;
}