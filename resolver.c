#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


 bool resolve(int row, int col, int board[9][9]);
 bool check(int row, int col, int n, int board[9][9]);
 void printBoard(int board[9][9]);

int main()
{
    int board[9][9] = {0};
    for (int i = 0; i < 9; i++) {
        char line[10];
        scanf("%[^\n]", line); fgetc(stdin);

        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    resolve(0,0,board);
    printBoard(board);

    return 0;
}

bool check(int row, int col, int n, int board[9][9]){

    for(int i = 0; i < 9; i++) {
        //check if the number already exists on the row
        if(board[row][i] == n) {
            return false;
        }

        //check if the number already exists on the column
        if(board[i][col] == n) {
            return false;
        }
    }

    //check if number already exists on the inner square 3x3 
    int r = row - row % 3;
    int c = col - col % 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[r + i][c + j] == n)
            {
                return false;
            }
        }
    }


    return true;
}

bool resolve(int row, int col, int board[9][9]) {
    
    //check if board is completed
    if(col == 9 && row == 8) return true;

    //change for the next row
    if(col == 9) {
        row += 1;
        col = 0;
    }

    //if current cell already has a solution, go to the next cell
    if(board[row][col] != 0) return resolve(row, col + 1, board);

    //trying every possible number for current cell
    for( int n = 1; n <= 9; n++) {
        if(check(row, col, n, board)) {
            board[row][col] = n;

            //check recursively if current number solves the puzzle
            if (resolve(row, col + 1, board)) return true;

            board[row][col] = 0;
        }
    }

    return false;

}

//print the board
void printBoard(int board[9][9]){
    printf("\n\n************ SOLUTION ************\n\n");
    for(int i = 0; i < 9; i++){

        if(i > 0 && i % 3 == 0) printf("---------------------\n");

        for(int j = 0; j < 9; j++) {
            if(j > 0 && j % 3 == 0) printf("| ");

            printf("%d ", board[i][j]);
        }
        
        printf("\n");
    }

    printf("\n\n");
}