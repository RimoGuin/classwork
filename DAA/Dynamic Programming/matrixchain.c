//Matrix chain multiplication program 
//using Dynamic Programming

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void MATRIX_CHAIN_ORDER(int *p, int n, int **m, int**s){
    int i;
    int row = n + 1;
    for(i = 1; i <= n; i++) //Chain length l
        *((int*) m + row * i + i) = 0;
    
    for(int l = 2; l <= n; l++){                //l is the chain length
       for(i = 1; i <= (n - l + 1); i++){       //chain begins at Ai 
            int j = i + l - 1;                  //chain ends at Aj
            *((int*) m + row * i + j) = -1;         
            
            for(int k = i; k <= j - 1; k++){
                
                int tmp1 = *((int*) m + row * i + k);
                int tmp2 = *((int*) m + row * (k + 1) + j);
                int q = tmp1 + tmp2 + p[i - 1] * p[k] * p[j];

                int old = *((int*) m + row * i + j);
                
                if(q < old || old == -1){
                    *((int*) m + row * i + j) = q;
                    *((int*) s + row * i + j) = k;
                }
            }
        } 
    }
}

void PRINT_OPTIMAL_PARENTS(int **s, int i, int j, int row){
    if(i == j)
        printf("A%d", i);
    else{
        printf("(");
        PRINT_OPTIMAL_PARENTS(s, i, *((int*) s + row * i + j), row);
        PRINT_OPTIMAL_PARENTS(s, *((int*) s + row * i + j) + 1, j, row);
        printf(")");
    }
}

int main(){
    printf("Enter the number of matrices:");
    int n;
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions: ");
    for(int i = 0; i < n + 1; i++)
        scanf("%d", &p[i]);

    int m[n + 1][n + 1], s[n + 1][n + 1];

    MATRIX_CHAIN_ORDER(p, n, (int**)m, (int**)s);
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    PRINT_OPTIMAL_PARENTS((int**) s, 1, n, n + 1);
    return 0;
}
