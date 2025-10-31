# include <stdio.h>
# include <unistd.h>
# include <wait.h>

int main() {
    pid_t pid,pid1;
    pid = fork();

    if(pid == 0){ // 자식 프로세스
        pid1 = getpid();
        printf("Child Process pid: %d\n", pid);
        printf("Child Process pid1: %d\n", pid1);

    }
    else if (pid > 0){ // 부모 프로세스
        pid1 = getpid();
        printf("Parent Process pid: %d\n", pid);
        printf("Parent Process pid1: %d\n", pid1);
        wait(NULL);
    }
    return 0;
    
}
