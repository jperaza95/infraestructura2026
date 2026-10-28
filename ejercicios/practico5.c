#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

// Productor, consumidor

sem_t mutex, empty, fill; //mutex, vacio y lleno
int first, last, size;
int buffer[10];

void insert(int *v)
{
    buffer[last] = *v; //Se inserta v en el buffer. Analogo a la clase, last es "proximo a insertar."
    last++; 
    last = last % 10;  // usamos modulo para no salirnos del buffer.
}

int extract()
{
    int x = buffer[first]; // se extrae el elemento en la posicion "first (proximo a extraer)".
    first++;
    first = first % 10;
    return x;
}

void consume(int cons) //extrae "first" e imprime en pantalla.
{
    int e = extract();
    printf("\nConsumer %d consumed %d \n", cons, e); 
}

int *produce(int *prod) // 
{
    int p = rand() % 11;
    printf("Producer %d produced %d \n", *prod, p);
    return &p;  // retorna un int que será el productor.
}

void *consumer(void *arg)
{
    int *consumer = (int *)arg;
    while (1)
    {
        sem_wait(&fill);    //P(lleno), sem_fill empieza en 0. Si esta en cero, esperamos a que el productor produzca algo.
        sem_wait(&mutex);   //P(Mutex)
        consume(*consumer); // consume, (extrae y muestra en pantalla)
        sem_post(&mutex); // V(Mutex)
        sem_post(&empty); // V(vacio). Sumo 1 al semaforo "vacio", que empieza en 10.
        sleep(1 + rand() % 5);
    }
    return NULL;
}

void *producer(void *arg)
{
    while (1)
    {
        int *productor = (int *)arg;
        int *product = produce(*productor);
        sem_wait(&empty); //P(Vacio), sem_empty empieza en 10, le resto uno.
        sem_wait(&mutex);
        insert(product);
        // critical section
        sem_post(&mutex); 
        sem_post(&fill); //V(lleno). Sumo 1 al semaforo "lleno", que empieza en cero.
        sleep(1 + rand() % 3);
    }
    return NULL;
}

int main()
{
    // Buffer length =10
    first= 0;
    last = 0;
    size = 10;
    sem_init(&mutex, 0, 1);
    sem_init(&fill, 0, 0);
    sem_init(&empty, 0, 10);
    pthread_t p1, p2, c1, c2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int np1 = 1;
    int np2 = 2;

    pthread_create(&p1,
                   &attr, producer,
                   &np1);
    pthread_create(&p2,
                   &attr, producer,
                   &np2);
    pthread_create(&c1,
                   &attr,
                   consumer,
                   &np1);
    pthread_create(&c2,
                   &attr,
                   consumer,
                   &np2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
}