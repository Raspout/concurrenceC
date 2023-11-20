#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../dijkstra/dijkstra.h"
#define CLE 1

int main() {

    int semid;
    semid = semget(CLE,1,0);

    srand(getpid()); 
    int random = rand() % 3 + 3;

    printf("first - Je vais attendre %d secondes\n", random);
    sleep(random);

    printf("first - Process fini\n");
    V(semid);

    return 0;
}