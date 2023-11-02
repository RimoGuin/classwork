// Write a program to implement and create a zombie process.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
	int p = fork();
	if(p == 0) {
		printf("Inside child process.\n");
		printf("PID = %d \n", getpid());
		printf("PPID = %d \n", getppid());
	}

	else if(p > 0) {
		sleep(10);
		printf("Parent process");
		printf("PID = %d \n", getpid());
		printf("PPID = %d \n", getppid());
		printf("Zombie process. \n");
	}
	while(1) { printf("Valid"); }
}
