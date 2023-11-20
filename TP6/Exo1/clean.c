#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "../dijkstra/dijkstra.h"

#define KEY 1
#define SIZE 1

int main(void)
{
    int shmid = shmget(KEY, SIZE * sizeof(int), 0); 
    int res = shmctl(shmid, IPC_RMID, NULL);
    if(res == -1){
        perror("Delete Shm");
    }

    int mutexID = sem_create(KEY, 1); 
    sem_delete(mutexID); 

    return 0;
}

