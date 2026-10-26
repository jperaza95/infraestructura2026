#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 


// Función que ejecutará el hilo 
void* hola(void* arg) {
     printf("Hola desde el hilo!\n"); 
     return NULL; 

}

int main() { 
    pthread_t hilo; //inicializa el hilo
    // Crear el hilo 
    pthread_create(&hilo, NULL, hola, NULL);  //referencia al hilo, no pasa parametro (NULL), hola:funcion a ejecutar
    sleep(2);
    // El hilo principal también imprime algo 
    printf("Hola desde main!\n"); 
    // Darle tiempo al hilo para que ejecute antes de que main termine 
    pthread_exit(NULL); 
    
    return 0; 

}