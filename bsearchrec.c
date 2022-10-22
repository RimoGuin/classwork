#include<stdio.h>
 
int bsearch(int a[], int x, int low, int high){
	if(low >= high)
		return -1;
	else{
		int mid = (low + high) / 2;
		if(x == a[mid])
			return mid;
		else if(x > a[mid])
			return bsearch(a, x, mid + 1, high);
		else
			return bsearch(a, x, low, mid - 1);
	}
}

int main(){
	int a[100], l, v, i;
	printf("\nEnter array length: ");
	scanf("%d", &l);
	printf("Enter array values: ");
	for(i = 0; i < l; i++)
		scanf("%d", &a[i]);
	printf("\nEnter the value to be searched: ");
	scanf("%d", &v);
	int res = bsearch(a, v, 0, l - 1);
	if(res == -1)
		printf("\nElement is not present in array.\n");
	else
		printf("\nElement is present in array.\n");
	return 0;
}
