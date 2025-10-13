# include <stdio.h>
# include <unistd.h>

int main() {
    int i;
    pid_t pid;

    for(i=0; i<4; i++) {
        pid = fork(); //4번 포크
        // 각 프로세스에서 "Hello, World!" 출력
        printf("Hello, World!%d\n", pid);
    }
    return 0;
    
}

/*
프로세스 개수: 16개
첫번째 포크 : p0 -> p1
두번째 포크 : p0 -> p2, p1 -> p3
세번째 포크 : p0 -> p4, p1 -> p5, p2 -> p6, p3 -> p7
네번째 포크 : p0 -> p8, p1 -> p9, p2 -> p10, p3 -> p11, p4 -> p12, p5 -> p13, p6 -> p14, p7 -> p15
*/