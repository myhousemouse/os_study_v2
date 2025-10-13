# include <stdio.h>
# include <unistd.h>
# include <wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid > 0) { // 부모 프로세스
        wait(NULL);
    }
    printf("Hello, World!%d\n", pid);

}