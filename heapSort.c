#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Heapifying an array
void heapify(int arr[], int N, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < N && arr[left] > arr[largest])//If left child is larger than root
        largest = left;
    if(right < N && arr[right] > arr[largest])//If right child is larger than root
        largest = right;
    
    if(largest != i){ //if largest != root, swap and continue heapifying
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);//Recursively heapify the affected sub-tree
    }
}

void heapSort(int arr[], int N){
    for(int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);
    }
    for(int i = N - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N){
    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n;
    printf("\nEnter the length of the array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
}