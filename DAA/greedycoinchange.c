#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define COINS 8
#define MAX 100
int coins[COINS] = {1000, 500, 100, 50, 20, 5, 2, 1};

void findmin(int cost){
	int list[MAX] = {0};
	int i, k = 0;

	for(i = 0; i <= COINS - 1; i++){
		while(cost >= coins[i]){
			cost -= coins[i];
			list[k++] = coins[i];
		}
	}
	for(i = 0; i < k ;i++)
		printf(" %d", list[i]);
}

int main(){
	printf("Enter cost: ");
	int n;
	scanf("%d", &n);
	printf("Changes: ");
	findmin(n);
	return 0;
}
