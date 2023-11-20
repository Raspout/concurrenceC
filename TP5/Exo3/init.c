#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "dijkstra.c"

#define RECEPTEUR 23015
#define EMETTEUR1 23021
#define EMETTEUR2 23028

int main() {
    int recepteur;
    recepteur = sem_create(RECEPTEUR, 0);
    printf("Creation du sémaphore de l'emmetteur %d\n", recepteur);

    int emmeteur1;
    emmeteur1 = sem_create(EMETTEUR1, 0);
    printf("Creation du sémaphore recepteur1 %d\n", emmeteur1);

    int emmeteur2;
    emmeteur2 = sem_create(EMETTEUR2, 0);
    printf("Creation du sémaphore recepteur2 %d\n", emmeteur2);

    return 0;
}