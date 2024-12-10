#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t sem_v, sem_y, sem_z, sem_ans;

int w, v, y, z, ans;
int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5, x6 = 6;

void *calculate_w(void *arg) {
    w = x1 * x2;
    sem_post(&sem_v);  // Cho phép tính v
    return NULL;
}

void *calculate_v(void *arg) {
    sem_wait(&sem_v);
    v = x3 * x4;
    sem_post(&sem_y);  // Cho phép tính y
    sem_post(&sem_z);  // Cho phép tính z
    return NULL;
}

void *calculate_y(void *arg) {
    sem_wait(&sem_y);
    y = v * x5;
    sem_post(&sem_ans);  // Cho phép tính ans
    return NULL;
}

void *calculate_z(void *arg) {
    sem_wait(&sem_z);
    z = v * x6;
    sem_post(&sem_ans);  // Cho phép tính ans
    return NULL;
}

void *calculate_ans(void *arg) {
    sem_wait(&sem_ans);
    sem_wait(&sem_ans);
    ans = y + z;
    printf("Final result: %d\n", ans);
    return NULL;
}

int main() {
    pthread_t t_w, t_v, t_y, t_z, t_ans;

    sem_init(&sem_v, 0, 0);
    sem_init(&sem_y, 0, 0);
    sem_init(&sem_z, 0, 0);
    sem_init(&sem_ans, 0, 0);

    pthread_create(&t_w, NULL, calculate_w, NULL);
    pthread_create(&t_v, NULL, calculate_v, NULL);
    pthread_create(&t_y, NULL, calculate_y, NULL);
    pthread_create(&t_z, NULL, calculate_z, NULL);
    pthread_create(&t_ans, NULL, calculate_ans, NULL);

    pthread_join(t_w, NULL);
    pthread_join(t_v, NULL);
    pthread_join(t_y, NULL);
    pthread_join(t_z, NULL);
    pthread_join(t_ans, NULL);

    sem_destroy(&sem_v);
    sem_destroy(&sem_y);
    sem_destroy(&sem_z);
    sem_destroy(&sem_ans);

    return 0;
}
