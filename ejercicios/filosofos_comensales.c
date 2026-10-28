#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 // cantidad de filosofos

sem_t palitos[N]; // array de semaforos (palitos)
sem_t mesa;

void* filosofo0(void *arg){
    int izq = (N+1)%N;
    int der = N;
    while (1)
    {
        sem_wait(&mesa);
        sem_wait(&palitos[izq]);
        sem_wait(&palitos[der]);
        printf("Filosofo 0 - Comiendo");
        sem_post(&palitos[izq]);
        sem_post(&palitos[der]);
        sem_post(&mesa);

    }
}

void* filosofo1(void *arg){
    int izq = (N+1)%N;
    int der = N;
    while (1)
    {
        sem_wait(&mesa);
        sem_wait(&palitos[izq]);
        sem_wait(&palitos[der]);
        printf("Filosofo 1 - Comiendo \n");
        sem_post(&palitos[izq]);
        sem_post(&palitos[der]);
        sem_post(&mesa);

    }
}

void* filosofo2(void *arg){
    int izq = (N+1)%N;
    int der = N;
    while (1)
    {
        sem_wait(&mesa);
        sem_wait(&palitos[izq]);
        sem_wait(&palitos[der]);
        printf("Filosofo 2 - Comiendo \n");
        sem_post(&palitos[izq]);
        sem_post(&palitos[der]);
        sem_post(&mesa);

    }
}

void* filosofo3(void *arg){
    int izq = (N+1)%N;
    int der = N;
    while (1)
    {
        sem_wait(&mesa);
        sem_wait(&palitos[izq]);
        sem_wait(&palitos[der]);
        printf("Filosofo 3 - Comiendo \n");
        sem_post(&palitos[izq]);
        sem_post(&palitos[der]);
        sem_post(&mesa);

    }
}

void* filosofo4(void *arg){
    int izq = (N+1)%N;
    int der = N;
    while (1)
    {
        sem_wait(&mesa);
        sem_wait(&palitos[izq]);
        sem_wait(&palitos[der]);
        printf("Filosofo 4 - Comiendo \n");
        sem_post(&palitos[izq]);
        sem_post(&palitos[der]);
        sem_post(&mesa);

    }
}


int main()
{
    sem_init(&mesa, 0, N - 1);

    for (int i = 0; i < N - 1; i++)
    {
        sem_init(&palitos[i], 0, 1);
    }

    pthread_t f0, f1, f2, f3, f4;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int id0 = 0;
    int id1 = 1;
    int id2 = 2;
    int id3 = 3;
    int id4 = 4;


    pthread_create(&f0,
                   &attr, filosofo0,
                   &id0);

    pthread_create(&f1,
                   &attr, filosofo1,
                   &id1);

    pthread_create(&f2,
                   &attr, filosofo2,
                   &id2);
            
    pthread_create(&f3,
                   &attr, filosofo3,
                   &id3);   

    pthread_create(&f4,
                &attr, filosofo4,
                &id4);                      

    pthread_join(f0, NULL);
    pthread_join(f1, NULL);
    pthread_join(f2, NULL);
    pthread_join(f3, NULL);
    pthread_join(f4, NULL);
}