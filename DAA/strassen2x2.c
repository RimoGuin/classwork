#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int m1, m2, m3, m4, m5, m6, m7;
int n;//Matrix specs. of n*n

int **matrix_allocate(int row, int column){ //Creating a new matrix
    int **matrix = malloc(row * sizeof(*matrix));
    for(int i = 0; i < row; i++){
        matrix[i] = calloc(column, sizeof(*matrix[i]));
    }
    return matrix;
}

void matrix_free(int **matrix, int row){
    for(int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);    
}

void matrix_print(const char *str, int **a, int row){
    int min, max, w = 0, n1, n2, nw;
    min = max = a[0][0];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            if(min > a[i][j])
                min = a[i][j];
            if(max < a[i][j])
                max = a[i][j];            
        }
    }
    n1 = snprintf(NULL, 0, "%d ", min);
    n2 = snprintf(NULL, 0, "%d ", max);
    nw = n1 > n2 ? n1 : n2;

    for(int i = 0; i < row; i++){
        if(i == 0)
            w = printf("%s = ", str);
        else
            printf("%*s ", w, "");
        for(int j = 0; j < row; j++){
            printf("%*d ", nw, a[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
}

int **matrix_add(int **a, int **b, int row, int deallocate){
    int **c = matrix_allocate(row, row);
    for(int i = 0; i < row; i++){
        for(int  j = 0; j < row; j++)  
            c[i][j] = a[i][j] + b[i][j];
    }
    if(deallocate & 1) matrix_free(a, row);
    if(deallocate & 2) matrix_free(b, row);
    
    return c;
}


int **matrix_multiply(int **a, int **b){
    int **c = matrix_allocate(2,2);
    m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1]) * b[0][0];
    m3 = a[0][0] * (b[0][1] + b[1][0]);
    m4 = a[1][1] * (b[1][0] - b[0][0]);
    m5 = (a[0][0] + a[0][1]) * b[1][1];
    m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;
    return c;
}

int main(){
	int **A = matrix_allocate(2, 2);
    int **B = matrix_allocate(2, 2);
    
    clock_t time;
	//srand(time(0));
	
	printf("Enter matrix1 values: ");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter matrix2 values: ");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &B[i][j]);
        }
    }
    
    time = -clock();
    int **res = matrix_multiply(A, B);
    time += clock();
    
    matrix_print("A: ", A, 2);
    matrix_print("B: ", B, 2);
    matrix_print("Result: ", res, 2);
    printf("Time taken: %f seconds\n", (double)time/CLOCKS_PER_SEC);
}
