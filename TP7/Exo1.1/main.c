#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void *task(void* arg)
{
    sem_t* sem = arg;
    puts("Bonjour, j'attends");
    sem_wait(sem);

    return NULL;
}


int main(int argc, char const *argv[]) {

    int N = atoi(argv[1]);

    sem_t sem;
    sem_init(&sem,0,0);

    pthread_t thread[N];
    for (int i=1; i <= N-1; i++) {
        pthread_create(&thread[i],NULL,task,&sem);
    }

    sleep(5);
    puts("Wesh la zone !");
    for (int i=0; i < N-1; i++) {
        sem_post(&sem);
    }
    
    for (int i=1; i <= N-1; i++) {
        pthread_join(thread[i],NULL);
    }
    sem_destroy(&sem);

    return 0;
}