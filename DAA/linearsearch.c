#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    clock_t start_t, end_t;
    double total_t;
    int* a;
    int n, val, flag = 0;
    printf("Enter array size: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    srand(time(0));
    for(int i = 0; i < n; i++)
        a[i] = rand() % 1000;
    printf("Array: ");
    for(int i = 0; i < n; i++){
        printf(" %d", a[i]);
    }
    val = rand()%1000;
    printf("\nElement to be searched: %d", val);
    start_t = clock();
    for(int i = 0; i < n; i++){
        if(a[i] == val)
        flag = 1;
    }
    if(flag == 1)
        printf("\n Search successful");
    else
        printf("\n Search unsuccessful");
    end_t = clock();
    total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
    printf("\nTotal time= %ld secs.", total_t);
}
