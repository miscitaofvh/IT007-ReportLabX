#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t child_pid;

void handle_sigint(int sig) {
    if (child_pid > 0) {
        kill(child_pid, SIGKILL);
        printf("\ncount.sh has stopped\n");
    }
    exit(0);
}

int main() {
    printf("Welcome to IT007, I am 23520569!\n");

    child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        execl("./count.sh", "./count.sh", "120", NULL);
        perror("execl"); 
        exit(EXIT_FAILURE);
    } else {
        signal(SIGINT, handle_sigint);
        wait(NULL);
    }

    return 0;
}