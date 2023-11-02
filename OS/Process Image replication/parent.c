#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
	printf("I am the parent process\n\n");

	char *arg_Ptr[4];
	arg_Ptr[0] = "child.c";
	arg_Ptr[1] = "Hello from the child process";
	arg_Ptr[2] = "Good-Bye from the child process";
	arg_Ptr[3] = NULL;

	execv("Cexecv", arg_Ptr);
	printf("Error: %i\n", errno);
}
