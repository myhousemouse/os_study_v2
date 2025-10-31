#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() {
    char write_msg[BUFFER_SIZE] = "Greetings from Parent";
    char read_msg[BUFFER_SIZE];
    int fd[2]; //Read and Write file descriptors 2개
    pid_t pid;

    // 파이프 생성
    pipe(fd);
    pid = fork(); // 프로세스 생성

    if (pid > 0) { // 부모 프로세스
        close(fd[READ_END]); // 읽기 끝 닫기

        // 파이프에 메시지 쓰기
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]); // 쓰기 끝 닫기
    } 
    else { // 자식 프로세스
        close(fd[WRITE_END]); // 쓰기 끝 닫기

        // 파이프에서 메시지 읽기
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Child Process Received: %s\n", read_msg);
        close(fd[READ_END]); // 읽기 끝 닫기
    }

    return 0;
}