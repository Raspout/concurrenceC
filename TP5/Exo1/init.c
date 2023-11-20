#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "../dijkstra/dijkstra.h"

#define CLE 1

int main() {
    int sem;
    sem = sem_create(CLE, 0);
    printf("Creation du sémaphore d'identificateur %d\n", sem);

    return 0;
}