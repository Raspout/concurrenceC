#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// Define a global semaphore
sem_t semaphore;

void* func(void* arg) {
    int i = *(int*)arg;
    printf("création du thread %d\n", i);
    sem_wait(&semaphore);
    sleep(i * 1);

    printf("fin de la tache %d\n", i);

    // Release the semaphore

    sem_post(&semaphore);
    return NULL;
}

int main(int argc, char const *argv[]) {
    if (argc == 2) {
        int rep = atoi(argv[1]);
        int* thread_ids[rep];
        pthread_t thread[rep];

        // Initialize the semaphore
        sem_init(&semaphore, 0, 0);

        for (int i = 0; i < rep; i++) {
            thread_ids[i] = (int*)malloc(sizeof(int));
            *thread_ids[i] = i;
            pthread_create(&thread[i], NULL, func, thread_ids[i]);
        }


        for (int i = 0; i < rep; i++) {
            pthread_join(thread[i], NULL);
            printf("fin du thread %d\n", i);
        } 

        // Destroy the semaphore when done
        sem_destroy(&semaphore);
    } else {
        puts("usage : ./ex1 numberOfThreads ");
    }

    return 0;
}