#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include "../dijkstra/dijkstra.h"

#define KEY 1
#define SIZE 1


int main() {
    int n;
    n = sem_create(KEY, 0);
    printf("Creation du sémaphore d'identificateur %d\n", n);

    int shmid = shmget(KEY, SIZE * sizeof(int), IPC_CREAT | IPC_EXCL | 0600);
    if (shmid == -1){
        perror("Shmget Memory");
    }

    return 0;
}

