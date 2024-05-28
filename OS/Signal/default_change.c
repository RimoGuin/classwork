// Commented line is when needed to restore for default function

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void oh(int sig) {
	printf("I get signal %d \n", sig);
	signal(SIGINT, oh);
	//signal(SIGINT, SIG_DFL);
}

int main() {
	signal(SIGINT, oh);
	while(1) {
		printf("Hello world!\n");
		sleep(1);
	}
}
