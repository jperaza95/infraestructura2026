#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 // cantidad de filosofos

sem_t palitos[N]; // array de semaforos (palitos)
sem_t mesa;

void* filosofo(void *arg){
    int id = *(int*)arg;

    int izq = id;
    int der = (id+1)%N;
    while (1)
    {
        printf("Filosofo %d - Pensando\n", id);
        sleep(2);

        sem_wait(&mesa);
        sem_wait(&palitos[izq]);
        sem_wait(&palitos[der]);

        printf("Filosofo %d - Comiendo\n", id);
        sleep(2);

        sem_post(&palitos[izq]);
        sem_post(&palitos[der]);
        sem_post(&mesa);

    }
    return NULL;
}



int main()
{
    sem_init(&mesa, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        sem_init(&palitos[i], 0, 1);
    }

    pthread_t filosofos[N];
    int ids[N];

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < N; i++)
    {
        ids[i] = i;
        pthread_create(&filosofos[i],
                   &attr, filosofo,
                   &ids[i]);
    }
    

    for (int i = 0; i < N; i++)
    {
        pthread_join(filosofos[i], NULL);
    }

}