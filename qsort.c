#include<stdio.h>

void swap(int* a, int*b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int h){
	int x, i, temp;
	x = a[h];
	i = l - 1;
	for(int j = l; j <= h - 1; j++){
		if(a[j] <= x){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[h]);
	return (i + 1);
}

void Quicksort(int a[], int l, int h){
	int q;
	if(l < h){
		q = partition(a, l, h);
		Quicksort(a, l, q - 1);
		Quicksort(a, q + 1, h);
	}
}

int main(){
	printf("Enter array length: ");
	int len, i;
	scanf("%d", &len);
	int a[50];
	printf("Enter array elements: ");
	for(i = 0; i < len; i++)
		scanf("%d", &a[i]);
	printf("\nEntered array: ");
	for(i = 0; i < len; i++)
		printf("%d\t", a[i]);
	printf("\n");
	printf("Array after sorting: ");
	Quicksort(a, 0, len - 1);
	for(i = 0; i < len; i++)
		printf("%d\t", a[i]);
	return 0;
}
