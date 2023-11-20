#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "../dijkstra/dijkstra.h"

#define CLARA 1
#define MICHJULIETTE 2
#define ROMUALD 3

int main() {
    int clara;
    clara = sem_create(CLARA, 0);
    printf("Creation du sémaphore d'identificateur %d\n", clara);

    int michjuliette;
    michjuliette = sem_create(MICHJULIETTE, 0);
    printf("Creation du sémaphore d'identificateur %d\n", michjuliette);

    int romuald;
    romuald = sem_create(ROMUALD, 0);
    printf("Creation du sémaphore d'identificateur %d\n", romuald);

    return 0;
}