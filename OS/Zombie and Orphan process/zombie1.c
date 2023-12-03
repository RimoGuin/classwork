#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <sys/types.h>  
#include <sys/wait.h>  

int main() {  
    pid_t pid = fork();  

    if (pid == -1) {  
        printf("error\n");  
    }  
    else if (pid == 0) {  
        printf("Child %d\n", getpid());  
        printf("Parents %d\n", getppid());  
        printf("Waiting for my Child to complete\n");  
        exit(0);  
    }  
    else {  
        sleep(5);  
        printf("Parent %d\n",getpid());  
    }  

    return 0;  
}  
