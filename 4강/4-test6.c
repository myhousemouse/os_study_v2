# include <stdio.h>
# include <unistd.h>
# define SIZE 5
int nums[SIZE] = {1,2,3,4,5};
# include <wait.h>

int main() {
    pid_t pid,pid1;
    int i;
    pid = fork();

    if(pid == 0){ // 자식 프로세스
        for(i=0; i<SIZE; i++){
            nums[i] *= i;
        printf("Child Process: nums[%d] = %d\n", i, nums[i]); //LINE X
        }
    }
    
    else if (pid > 0){ // 부모 프로세스
        wait(NULL);
        for(i=0; i<SIZE; i++){
            printf("Parent Process: nums[%d] = %d\n", i, nums[i]); //LINE Y
        }
    }
    return 0;
    
}
