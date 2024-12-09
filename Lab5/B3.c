#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int x;

pthread_mutex_t pt;

void* processA()
{
    while (1)
    {
        pthread_mutex_lock(&pt);
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("A = %d\n", x);
        pthread_mutex_unlock(&pt);
    }
}

void *processB()
{
    while (1)
    {
        pthread_mutex_lock(&pt);
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("B = %d\n", x);
        pthread_mutex_unlock(&pt);
    }
}

int main()
{
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, processA, NULL);
    pthread_create(&tid2, NULL, processB, NULL);

    pthread_exit(NULL);
}