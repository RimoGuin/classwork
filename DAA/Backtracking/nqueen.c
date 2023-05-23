// n-queen problem using backtracking
/*function solveNQueens(board, col, n):
    if col >= n:
        print board
        return true
    for row from 0 to n-1:
        if isSafe(board, row, col, n):
            board[row][col] = 1
            if solveNQueens(board, col+1, n):
                return true
            board[row][col] = 0
    return false

function isSafe(board, row, col, n):
    for i from 0 to col-1:
      if board[row][i] == 1:
          return false
    for i,j from row-1, col-1 to 0, 0 by -1:
        if board[i][j] == 1:
            return false
    for i,j from row+1, col-1 to n-1, 0 by 1, -1:
        if board[i][j] == 1:
            return false
    return true

board = empty NxN chessboard
solveNQueens(board, 0, N)
*/

#include<stdio.h>
#include<stdlib.h>

int board[20], count;
void print(int);

int place(int row, int column) {
	int i;
	for(i = 1; i <= row - 1; i++) {
		if(board[i] == column)
			return 0; // Not feasible
		else if(abs(board[i] - column) == abs(i - row))
			return 0; // Not feasible
	}
	return 1; // No conflict
}

void queen(int row, int n) {
	int column;
	for(column = 1; column <= n; column++) {
		if(place(row, column)){
			board[row] = column; // no conflict, so place Queen
			if(row == n) // dead end
				print(n);
			else
				queen(row + 1, n);
		}
	}
}

void print(int n){
	int i, j;
	printf("\n Solution %d: \n", ++count);

	for(i = 1; i <= n; i++) 
		printf("\t%d", i);

	for(i = 1; i <= n; i++) {
		printf("\n%d", i);
		for(j = 1; j <= n; j++){
			if(board[i] == j)
				printf("\tQ");
			else printf("\t-");
		}
	}
}

int main(){
	int n, i, j;
	void queen(int row, int n);

	printf(" - N Queens problem using backtracking -");
	printf("\nEnter number of Queens: ");
	scanf("%d", &n);
	queen(1, n);
	return 0;
}
