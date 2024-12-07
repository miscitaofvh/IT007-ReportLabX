#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int sells = 0, products = 0;
sem_t sem1, sem2;

void *sell(void *arg) {
    while (1)
    {
        sem_wait(&sem1);
        sells++;
        printf("Sells: %d\n", sells);
        sem_post(&sem2);
    }
}

void *produce(void *arg) {
    while (1)
    {
        sem_wait(&sem2);
        products++;
        printf("Products: %d\n", products);
        sem_post(&sem1);
    }
}

int main()
{
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 569); // MSSV: 23520569

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, sell, NULL);
    pthread_create(&tid2, NULL, produce, NULL);

    pthread_exit(NULL);
    return 0;
}