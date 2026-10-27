#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t a, b, c;

void* imprimirA (void * x){
    printf("--- A ---");
}

void* imprimirB (void * x){
    printf("--- B ---");
}

void* imprimirC (void * x){
    printf("--- C ---");
}

void* imprimirD (void * x){
    printf("--- D ---");
}


int main(){
    sem_init(&a,0,0);
    sem_init(&b,0,0);
    sem_init(&c,0,0);

    pthread_t _a,_b,_c,_d;

    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&_a, &&attr, NULL);
    

}
