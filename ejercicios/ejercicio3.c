#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main() {
    pid_t pid = fork(); 
    if (pid == 0) { 

        // Código del hijo 
        printf("Hola desde el hijo (PID: %d)\n", getpid()); 

    } else {   
        // Código del padre
        wait(NULL); // Espera a que termine el hijo 
        printf("Hola desde el padre (PID: %d)\n", getpid()); 

    } 
    
    return 0; 

}  

//a) ¿Que hace el Fork-Wait?
// fork() -> clona el proceso que está corriendo, generando un nuevo proceso. Retorna 0 si es el hijo y el padre retorna su PID.
// wait(NULL) -> el padre (que entra al else) espera al hijo (solo a uno, el primero) hasta que se ejecute y luego imprime.
