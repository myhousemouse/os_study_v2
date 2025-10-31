#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS";

    int shm_fd; // 공유 메모리 객체의 파일 디스크립터
    char *ptr;  // 공유 메모리 객체에 매핑된 프로세스의 주소 공간 포인터

    // 공유 메모리 객체 열기
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    // 공유 메모리 객체를 프로세스의 주소 공간에 매핑
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // 공유 메모리에서 데이터 읽기
    printf("%s", ptr);

    // 공유 메모리 객체 닫기 및 해제
    if (shm_unlink(name) == -1) {
        perror("shm_unlink");
        exit(1);
    }

    return 0;
}