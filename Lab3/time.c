#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct timeval start, end;
    pid_t pid;

    // Lấy thời gian trước khi thực thi
    gettimeofday(&start, NULL);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Tiến trình con: thực thi lệnh shell
        execlp(argv[1], argv[1], (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);

        gettimeofday(&end, NULL);

        // Tính thời gian thực thi
        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

        printf("Thời gian thực thi: %.6f giây\n", elapsed_time);
    }

    return 0;
}