#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

int n = 0;
int a[141];

void *generate(void *arg) {
    while (1)
    {
        a[n++] = rand() % 100;
        printf("Generated -> Array size: %d\n", n);
    }
}

void *erase(void *arg) {
    while (1)
    {
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
    }
}

int main()
{
    srand(time(NULL));
    pthread_t tid1, tid2;
    
    pthread_create(&tid1, NULL, generate, NULL);
    pthread_create(&tid2, NULL, erase, NULL);
    pthread_exit(NULL);
}