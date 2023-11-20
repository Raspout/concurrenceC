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


int main(void) {

    
    return 0;
}