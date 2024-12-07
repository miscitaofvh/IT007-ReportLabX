#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int *shared_memory = (int *) mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    *(shared_memory) = atoi(argv[1]);
    *(shared_memory + 1) = 1;

    if (*(shared_memory) < 1) {
        fprintf(stderr, "Number must be greater than 0\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        while (true) {
            while (*(shared_memory + 1) != 1)
            {
                // Wait if child has not calculated the next value
            }
            
            *(shared_memory + 1) = 0;
            if (*(shared_memory) != 1) {
                printf("%d%c%c", *(shared_memory), ',', ' ');
            }
            else {
                printf("%d\n", *(shared_memory));
                break;
            }
        }

        wait(NULL);
        munmap(shared_memory, 10);
    } else {
        while (true) {
            while (*(shared_memory + 1) != 0)
            {
                // Wait if parent has not printed the current value
            }
            int n = *(shared_memory);
            if (n & 1) {
                *(shared_memory) = 3 * n + 1;
            }
            else {
                *(shared_memory) = n / 2;
            }
            *(shared_memory + 1) = 1;
            if (n == 1 || n == 2) {
                break;
            }
        }
        munmap(shared_memory, 10);
    }

    return 0;
}