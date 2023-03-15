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
	printf("\nEnter new value to be entered: ");
	int val = 0, pos = 0;
	scanf("%d", &val);
	printf("\nEnter position to be inserted: ");
	scanf("%d", &pos);
	l++;
	for(i = l; i > pos; i--){
		a[i] = a[i - 1];
	}
	a[pos] = a[pos - 1];
	a[pos - 1] = val;
	printf("\nNew Array: ");
	for(i = 0; i < l; i++)
		printf("\t%d", a[i]);
	printf("\n");
}
