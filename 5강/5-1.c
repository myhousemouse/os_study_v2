# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/shm.h>
# include <sys/stat.h>
# include <sys/mman.h>
//메모리 매핑함수 mmap

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    //공유 메모리에 저장할 두 문자열
    const char *message0 = "Hello, ";
    const char *message1 = "Shared Memory!";

    int shm_fd; // 공유 메모리 객체의 파일 디스크립터
    char *ptr; // 공유 메모리 객체에 매핑된 프로세스의 주소 공간 포인터

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); // 공유 메모리 객체 생성 혹은 열기
    //name : 공유 메모리 객체의 이름
    //O_CREAT : 공유 메모리 객체가 존재하지 않을 경우 생성
    //O_RDWR : 읽기 및 쓰기 권한으로 열기
    //0666 : 파일 권한 설정(읽기 및 쓰기 권한 부여
    ftruncate(shm_fd, SIZE); // 공유 메모리 객체의 크기 설정
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); // 공유 메모리 객체를 프로세스의 주소 공간에 매핑
    //0 : 매핑할 시작주소 운영체제가 자동으로 선택
    //SIZE : 매핑할 메모리 크기
    //PROT_READ | PROT_WRITE : 읽기 및 쓰기 권한 설정
    //MAP_SHARED : 여러 프로세스가 공유할 수 있도록 설정
    //shm_fd : 매핑할 공유 메모리 객체의 파일 디스크립터
    //0 : 파일의 시작부터 매핑
    sprintf(ptr, "%s", message0);

    ptr += strlen(message0);
    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);
    return 0;
}