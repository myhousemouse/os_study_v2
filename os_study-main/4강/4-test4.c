# include <stdio.h>
# include <unistd.h>
# include <wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if(pid == 0){ // 자식 프로세스
        execlp("/bin/ls", "ls", NULL);
        //execlp란? 현재 프로세스를 새로운 프로세스로 대체
        printf("LINE J\n");
        //이 문장은 출력되지 않음 (자식 프로세스가 ls로 대체되었기 때문)
    }
    else if (pid > 0){ // 부모 프로세스
        wait(NULL);
        printf("child complete\n");
    }
    return 0;
    
}
