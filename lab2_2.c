#include<stdio.h>
int main(){
	printf("\nEnter array length: ");
	int l, i;
	int a[100];
	scanf("%d", &l);
	printf("\nEnter array values: ");
	for(i = 0; i < l; i++)
		scanf("%d", &a[i]);
	printf("\nEntered array: ");
	for(i = 0; i < l; i++)
		printf("%d\t", a[i]);
	printf("\nEnter position of value to be deleted: ");
	int pos = 0;
	scanf("%d", &pos);
	for(i = pos - 1; i < l - 1; i++){
		a[i] = a[i + 1];
	}
	printf("\nNew Array: ");
	for(i = 0; i < l - 1; i++)
		printf("\t%d", a[i]);
	printf("\n");
}
