# include <stdio.h>
# include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    printf("Hello, World!\n");

    return 0;
}