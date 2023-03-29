#include<stdio.h>
#include<stdlib.h>

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
	if(n == 0)
		return;
	TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
	TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(){
	printf("Enter number of disks: ");
	int n;
	scanf("%d", &n);
	TowerOfHanoi(n, 'A', 'C', 'B');

	return 0;
}
