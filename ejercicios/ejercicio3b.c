#include <stdio.h> 
#include <pthread.h>

// Función del hilo 
void* tarea(void* arg) { 
    printf("Hola desde el hilo!\n"); 
    return NULL;
}
    
int main() {
    pthread_t hilo; 

    // Crear el hilo
    pthread_create(&hilo, NULL, tarea, NULL); 
    
    // Esperar a que termine el hilo
    pthread_join(hilo, NULL); 

    printf("Hola desde el main!\n"); 

    return 0; 

}

//b) ¿Qué hace el pthread_create y el pthread_join?

//pthread_create crea un nuevo hilo de ejecución dentro del proceso actual.
//pthread_join espera a que termine el hilo "hilo". NULL indica que no recogemos el valor de retorno del hilo.


//c) ¿Qué diferencias hay entre usar fork y wait y utilizar join e hilos?
// fork y wait:  crea una copia del proceso padre, utilizando cada uno su propio codigo y espacio en memoria.
// wait espera a que termina un proceso hijo, pthread_join() espera a que termine el hilo.
// join e hilos: crea un hilo dentro del mismo proceso, compartiendo su memoria.