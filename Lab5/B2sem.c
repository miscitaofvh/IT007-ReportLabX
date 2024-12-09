#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

int n = 0;
int a[141];

sem_t sem1, sem2;
pthread_mutex_t pt;

void* generate(void* arg)
{
    while (1)
    {
        sem_wait(&sem2);
        pthread_mutex_lock(&pt);
        a[n++] = rand() % 100;
        printf("Generated -> Array size: %d\n", n);
        pthread_mutex_unlock(&pt);
        sem_post(&sem1);
    }
}

void *erase(void *arg) {
    while (1)
    {
        sem_wait(&sem1);
        pthread_mutex_lock(&pt);
        if (n == 0)
        {
            printf("hihi");
            exit(0);
        }
        int index = rand() % n;
        for (int i = index; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        --n;

        if (n == 0)
            printf("Nothing in array a \n");
        else 
            printf("Erased -> Array size: %d\n", n);
        pthread_mutex_unlock(&pt);
        sem_post(&sem2);
    }
}

int main()
{
    srand(time(NULL));
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 141); // Array size: 141

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, generate, NULL);
    pthread_create(&tid2, NULL, erase, NULL);

    pthread_exit(NULL);
}