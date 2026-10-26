#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h>

int suma;
void *mi_hilo(void *valor);

//argc = argument count (cantidad de argumentos) 
//argv = argument vector (vector de argumentos) 

int main(int argc, char *argv[]) 
{ 
    pthread_t tid; //se usa para identificar de forma unica un hilo.
    pthread_attr_t attr;  
    if (argc != 2){ 
        fprintf(stderr, "Uso: ./pthread <entero>\n"); 
        return -1; 
    } 
    
    pthread_attr_init(&attr); //Att predeterminados. 
    
    pthread_create(&tid, &attr, mi_hilo, argv[1]); 
    
    //Crear el nuevo hilo. 
    
    pthread_join(tid, NULL); 
    
    //Esperar finalización. 
    
    printf("Suma total: %d.\n", suma); return 0; } 
    
    void *mi_hilo(void *valor) 
    { 
        int i, ls; 
        ls = atoi(valor); //ascii to integer
        i = 0, suma = 0; 
        
        while(i <= ls) 
        suma += (i++); 
            
        pthread_exit(0); 
    
    }