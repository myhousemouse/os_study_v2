# include <stdio.h>
# include <unistd.h>
# include <wait.h>

int main() {
    fork();
    fork();
    fork();
    printf("Hello, World!\n");
    return 0;
}

/*
프로세스 개수: 8개
첫번째 포크 : p0 -> p1
두번째 포크 : p0 -> p2, p1 -> p3
세번째 포크 : p0 -> p4, p1 -> p5, p2 -> p6, p3 -> p7
*/