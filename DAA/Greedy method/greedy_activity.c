//Activity selection problem
//Using Greedy method

#include<stdio.h>
#include<stdlib.h>

int* activity_sector(int *a, int *s, int *f, int n){
	int* A = malloc(sizeof(int) * n);
	A[0] = 0; //Array will start from index 1
	A[1] = a[1];

	int k = 1, i, iter = 1;

	for(i = 2; i <= n; i++){
		if(s[i] >= f[k]){
			iter++;				//Appending array A
			A[iter] = a[i];		//Appending array A
			k = i;
		}
	}
	A[0] = iter;
	return A;
}

void swap(int *a, int *b){ //Swap function
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *f, int *a, int *s, int n){ //Sorting the activities on basis of finish time
	int i, j;
	for(i = 1; i < n - 1; i++)
		for(j = 1; j < n - 1 - i; j++)
			if(f[j] > f[j + 1]){
				swap(&f[j], &f[j + 1]);
				swap(&a[j], &a[j + 1]);
				swap(&s[j], &s[j + 1]);
			}
}

int main(){
	printf("Enter the number of activities: ");
	int n;
	scanf("%d", &n);
	int a[n + 1], s[n + 1], f[n + 1];
	a[0] = s[0] = f[0] = 0; //Initialising the arrays from index 1;
	printf("Enter activity number, start and finish times:");
	for(int i = 1; i < n + 1; i++)
		scanf("%d %d %d", &a[i], &s[i], &f[i]);
	sort(f, a, s, (n + 1));

	int *p = activity_sector(a, s, f, n);

	int i;
	//p[0] is the length upto which activites are stored
	printf("Activities permissible: \n");
	for(i = 1; i <= p[0]; i++){ 
		printf("%d\n", p[i]);
	}
	
	return 0;
}
