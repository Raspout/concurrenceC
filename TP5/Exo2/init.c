#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "../dijkstra/dijkstra.h"

#define CLARA 1
#define MICHJULIETTE 2

int main() {
    int clara;
    clara = sem_create(CLARA, 0);
    printf("Creation du sémaphore d'identificateur %d\n", clara);

    int michjuliette;
    michjuliette = sem_create(MICHJULIETTE, 0);
    printf("Creation du sémaphore d'identificateur %d\n", michjuliette);

    return 0;
}