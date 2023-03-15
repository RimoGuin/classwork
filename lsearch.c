#include<stdio.h>
int main(){
	int a[100], l, i, val, pos, flag = 0;
	printf("\nEnter array length: ");
	scanf("%d", &l);
	printf("\nEnter array elements: ");
	for(i = 0; i < l; i++)
		scanf("%d", &a[i]);
	printf("\nEnter value to be searched: ");
	scanf("%d", &val);
	pos = 1;
	for(i = 0; i < l; i++){
		if(a[i] == val){
			printf("\nValue present in position %d", pos);
			flag = 1;
		}
		pos++;
	}
	if(flag == 0)
		printf("\nValue not found.\n");
}
