#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../dijkstra/dijkstra.h"
#define CLE 1

int main() {

    int semid;
    semid = semget(CLE,1,0);

    printf("second - J'attends que first ait fini\n");
    P(semid);

    srand(getpid()); 
    int random = rand() % 4 + 1;

    printf("second - Je vais attendre %d secondes\n", random);
    sleep(random);

    printf("second - Process fini\n");
    sem_delete(semid);

    return 0;
}