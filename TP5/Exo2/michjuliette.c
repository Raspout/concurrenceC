#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../dijkstra/dijkstra.h"
#define CLARA 1
#define MICHJULIETTE 2

int main() {

    int sem_clara;
    sem_clara = semget(CLARA,1,0);

    int sem_mj;
    sem_mj = semget(MICHJULIETTE,1,0);

    V(sem_mj);
    printf("MJ - J'attends elClara\n");

    printf("MJ - Je suis làààààààààà\n");
    P(sem_clara);

    printf("MJ - COUCOU\n");

    return 0;
}