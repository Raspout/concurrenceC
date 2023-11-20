#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "dijkstra.c"

#define RECEPTEUR 23015
#define EMETTEUR1 23021
#define EMETTEUR2 23028

int main() {

    int sem_emetteur1;
    sem_emetteur1 = semget(EMETTEUR1,1,0);

    int sem_emetteur2;
    sem_emetteur2 = semget(EMETTEUR2,1,0);

    int sem_recepteur;
    sem_recepteur = semget(RECEPTEUR,1,0);

    V(sem_clara);
    V(sem_clara);
    printf("Clara - J'attends MJ\n");

    printf("Clara - Je suis làààààààààà\n");
    P(sem_mj);
    P(sem_romu);

    printf("Clara - COUCOU\n");

    return 0;
}