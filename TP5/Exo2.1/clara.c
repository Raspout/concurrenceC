#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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

    V(sem_clara);
    V(sem_clara);
    printf("Clara - J'attends MJ\n");

    printf("Clara - Je suis làààààààààà\n");
    P(sem_mj);
    P(sem_romu);

    printf("Clara - COUCOU\n");

    return 0;
}