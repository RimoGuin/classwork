#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max, min, *A;
void maxmin(int i, int j){
	int max1, min1, mid;
	if(i == j)
		max = min = A[i];
	else{
		if(i == j - 1){
			if(A[i] < A[j]){
				max = A[j];
				min = A[i];
			}
			else{
				max = A[i];
				min = A[j];
			}
		}
		else{
			mid = (i + j) / 2;
			maxmin(i, mid);
			max1 = max;
			min1 = min;
			maxmin(mid + 1, j);
			if(max < max1)
				max = max1;
			if(min > min1)
				min = min1;
		}
	}
}

int main(){
	int i, num;
	printf("Enter number of elements: ");
	scanf("%d", &num);
    A = (int*)malloc(num * sizeof(int));
	srand(time(0));
    for(i = 0; i < num; i++){
        A[i] = rand()%(num + 1);
    }

    printf("Numbers generated: ");
    for(i = 0; i < num; i++){
        printf("%d ", A[i]);
    }

    max = min = A[0];

    clock_t time;
    time = -clock();
    maxmin(1, num);
    time += clock();

    printf("\nMinimum element present: %d", min);
    printf("\nMaximum element present: %d", max);
	printf("\nTime taken: %f seconds\n", (double)time/CLOCKS_PER_SEC);
}
