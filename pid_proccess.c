#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int num_children;
    printf("Enter the number of children to fork: ");
    scanf("%d", &num_children);
    printf("Usage: %d \n", num_children);

    if (num_children <= 0) {
        fprintf(stderr, "Error: Number of children must be a positive integer.\n");
        return 1;
    }

    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();

        if (pid < 0) { // Jika terjadi error
            perror("fork failed");
            exit(1);
        } else if (pid == 0) { // Proses anak
            printf("Child process %d: PID = %d, Parent PID = %d\n", i + 1, getpid(), getppid());
            exit(0); // Keluar dari proses anak
        }
    }

    // Tunggu semua proses anak selesai
    for (int i = 0; i < num_children; i++) {
        wait(NULL);
    }

    printf("All child processes have completed.\n");
    return 0;
}
