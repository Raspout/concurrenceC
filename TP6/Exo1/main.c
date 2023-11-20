#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "../dijkstra/dijkstra.h"

#define KEY 1
#define SIZE 1

int main(int argc, char const *argv[])
{

    if (argc != 2) {
        exit(-1);
    }

    int N = atoi(argv[1]);

    int sem_N;
    sem_N = semget(KEY,1,0);
    int shmid = shmget(KEY, SIZE * sizeof(int), 0);

    if (shmid == -1){
        perror("Shmget Memory");
        exit(-1); 
    }

    int* mem = shmat(shmid, NULL, 0);
    if ((int64_t)mem == -1){
        perror("Shmat Memory");
        exit(-1);
    }

    // printf("read: %d\n", mem[0]);
    
    if(mem[0]+1 == N){
        for (int i = 1; i <= N; i++)
        {
            V(sem_N);
        }
        
    }

    printf("loading\n");
    mem[0] = mem[0] + 1;

    P(sem_N);
    printf("JE SUIS LIIIIIIIIIBREEEEEEEEEUH");
    
    return 0;
}
