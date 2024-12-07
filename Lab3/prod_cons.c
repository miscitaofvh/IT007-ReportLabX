#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

int main() {
    // Shared memory setup
    int *shared_memory = (int *) mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    *shared_memory = 0;

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        srand(time(NULL));
        while (true) {
            int value = rand() % 11 + 10; 
            while (*shared_memory != 0 && *shared_memory != -1) {
                // Wait if consumer has not consumed the previous value
            }
            if (*shared_memory != -1) {
                *shared_memory = value;
                printf("Producer produced: %d\n", value);
            }
            else {
                //printf("Producer stopped.\n");
                break;
            }
            sleep(1);
        }
        //printf("miscitaofvh\n");
        wait(NULL);
        munmap(shared_memory, 10);
        printf("Producer stopped.\n");
    } else {
        int total = 0;
        while (true) {
            while (*shared_memory == 0) {
                // Wait if there is no new value from producer
            }

            int value = *shared_memory;
               
            printf("Consumer consumed: %d\n", value);
            total += value;
            printf("Consumer total: %d\n", total);
            printf("----------------\n");
            if (total > 100) {
                printf("Consumer total exceeded 100. Stopping.\n");
                *shared_memory = -1;
                break;
            }
            
            *shared_memory = 0;   
        }

        munmap(shared_memory, 10);
        printf("Consumer stopped.\n");
    }

    return 0;
}
