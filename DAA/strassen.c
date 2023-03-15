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
	int w = 0;
	for(int i = 0; i < row; i++){
		if(i == 0)
            w = printf("%s =", str);
		else
            printf("%*s", w, "");
		for(int j = 0; j < row; j++)
			printf(" %d", a[i][j]);
		printf("\n");
	}    
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

int **strassen(int **a, int **b, int row, int deallocate){
    int **c = matrix_allocate(row, row);
    if(row == 2){
		c = matrix_multiply(a, b);           
    }
    else{
        int row2 = row / 2;
        int **a11 = matrix_allocate(row2, row2);
        int **a12 = matrix_allocate(row2, row2);
        int **a21 = matrix_allocate(row2, row2);
        int **a22 = matrix_allocate(row2, row2);
        int **b11 = matrix_allocate(row2, row2);
        int **b12 = matrix_allocate(row2, row2);
        int **b21 = matrix_allocate(row2, row2);
        int **b22 = matrix_allocate(row2, row2);
        for(int i = 0; i < row2; i++){
            for(int  j = 0; j < row2; j++){
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + row2];
                a21[i][j] = a[i + row2][j];
                a22[i][j] = a[i + row2][j + row2];
                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + row2];
                b21[i][j] = b[i + row2][j];
                b22[i][j] = b[i + row2][j + row2];
            }       
        }
        int **c11 = matrix_add(strassen(a11, b11, row2, 0), strassen(a12, b21, row2, 0), row2, 1 + 2);
        int **c12 = matrix_add(strassen(a11, b12, row2, 1), strassen(a12, b22, row2, 1), row2, 1 + 2);
        int **c21 = matrix_add(strassen(a21, b11, row2, 2), strassen(a22, b21, row2, 2), row2, 1 + 2);
        int **c22 = matrix_add(strassen(a21, b12, row2, 1+2), strassen(a22, b22, row2, 1+2), row2, 1 + 2);
        for(int i = 0; i < row2; i++){
            for(int j = 0; j < row2; j++){
                c[i][j] = c11[i][j];
                c[i][j + row2] = c12[i][j];
                c[i + row2][j] = c21[i][j];
                c[i + row2][j + row2] = c22[i][j];
            }
        }
        matrix_free(c11, row2);
        matrix_free(c12, row2);
        matrix_free(c21, row2);
        matrix_free(c22, row2);
     }
    if(deallocate & 1) matrix_free(a, row);
    if(deallocate & 2) matrix_free(b, row);
    return c;    
}

int main(){
    printf("Enter matrix size:");
    scanf("%d", &n);
	if((n == 1) || ((n & (n - 1)) != 0)){ //Bitwise operation to check whether the number is a power of 2 or not
		printf("Strassen's method works only of matrices of length power of 2.");
		exit(0);
	}
    int **A = matrix_allocate(n, n);
    int **B = matrix_allocate(n, n);
    
    srand(time(0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand() % 101;
            B[i][j] = rand() % 101;
        }
    }
    matrix_print("A", A, n);
    matrix_print("B", B, n);
    
    clock_t time = -clock();
    int **C = strassen(A, B, n, 0);
    time += clock();
    matrix_print("Product: ", C, n);
    printf("\nTime taken: %lf seconds\n",(double)time/CLOCKS_PER_SEC);
}
