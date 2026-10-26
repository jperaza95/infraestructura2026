#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1

int flag[2] = {FALSE, FALSE}; // Flags de cada hilo
int turn = 0;                 // Variable de turno compartida

void *process_0(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        flag[0] = TRUE;
        turn = 1;
        while (flag[1] == TRUE && turn == 1)
            ; // Espera activa

        // Sección crítica
        printf("Proceso 0 en sección crítica\n");
        sleep(1);
        printf("Proceso 0 sale de la sección crítica\n");

        flag[0] = FALSE; // Salir de la sección crítica
        sleep(1);
    }

    return NULL;
}

void *process_1(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        flag[1] = TRUE;
        turn = 0;
        while (flag[0] == TRUE && turn == 0)
            ; // Espera activa

        // Sección crítica
        printf("Proceso 1 en sección crítica\n");
        sleep(1);
        printf("Proceso 1 sale de la sección crítica\n");

        flag[1] = FALSE; // Salir de la sección crítica
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t t0, t1;
    pthread_create(&t0, NULL, process_0, NULL);
    pthread_create(&t1, NULL, process_1, NULL);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    return 0;
}
