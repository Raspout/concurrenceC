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

    V(sem_romu);
    V(sem_romu);
    printf("Romu - Coucou les fiiiiilles\n");

    printf("Romu - Je suis làààààààààà\n");
    P(sem_mj);
    P(sem_clara);

    printf("Romu - Alors on va dans mon appart ?\n");

    return 0;
}