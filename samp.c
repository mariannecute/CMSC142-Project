#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 4

main(){
	int board[N][N], i, j, count = 0, a, b, emp, empty, colCount, rowCount;		//initialize all variables
	int rowCheck = 0, colCheck = 0, knightCheck = 0;
	int row=0, col=0, checker=0;


	// printf("Enter N: ");
	// scanf("%d", &N);

	for(i=0; i<N; i++){					//initialize 4x4 board
		for(j=0; j<N; j++){
			board[i][j] = 0;
		}
	}

	
	while(row < N){										//traverse board one by one
		board[row][col] = 1;							//initialize one 1 element
		for(i=0; i<N; i++){								//traverse board to add other 1 elements
			for(j=0; j<N; j++){
				if(board[i][j] == 0){					//if element is 0, check if it can be 1 without bumping into other 1s
					for(a=0; a<N; a++){
						if(board[i][a]==1) rowCheck += 1;			//check rook move horizontal
					}
					for(b=0; b<N; b++){
						if(board[b][j]==1) colCheck += 1;			//check rook move vertical
					}

					if((board[i+2][j+1]==1) && (i+2 < N) && (j+1 < N)) knightCheck += 1;		//check all possible knight moves
					if((board[i-2][j+1]==1) && (i-2 >= 0) && (j+1 < N)) knightCheck += 1;
					if((board[i+2][j-1]==1) && (i+2 < N) && (j-1 >= 0)) knightCheck += 1;
					if((board[i-2][j-1]==1) && (i-2 >= 0) && (j-1 >= 0)) knightCheck += 1;

					if((board[i+1][j+2]==1) && (i+1 < N) && (j+2 < N)) knightCheck += 1;
					if((board[i-1][j+2]==1) && (i-1 >= 0) && (j+2 < N)) knightCheck += 1;
					if((board[i+1][j-2]==1) && (i+1 < N) && (j-2 >= 0)) knightCheck += 1;
					if((board[i-1][j-2]==1) && (i-1 >= 0) && (j-2 >= 0)) knightCheck += 1;

					if((rowCheck==0) && (colCheck==0) && (knightCheck==0)) board[i][j] = 1;			//check if no 1 coincides, if none turn 0 to 1
					rowCheck = 0;				//reset rook horizontal checker
					colCheck = 0;				//reset rook vertical checker
					knightCheck = 0;			//reset knight moves checker
				}

			}
		}
	
		for(rowCount=0; rowCount<N; rowCount++){					//check if how many 1 is in the board
			for(colCount=0; colCount<N; colCount++){
				if(board[rowCount][colCount]==1) checker += 1;
			}
		}

		if(checker <= N) count += 1;				//if there is equal or more than 4 (since N=4) 1 in the board, add it to the no. of solution
		checker = 0;								//reset checker

		for(emp=0; emp<N; emp++){					//reset all values in the board
			for(empty=0; empty<N; empty++){
				board[emp][empty] = 0;
			}
		}

		if(col < N-1) col += 1;			//update which element will be the initialized 1 next iteration
		else{
			row += 1;
			col = 0;
		}
	}

	printf("%d\n", count/2);				//print no. of solution
}

