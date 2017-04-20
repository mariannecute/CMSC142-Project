#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


main(){
	int board[4][4], i, j, count = 0, a, b, emp, empty, colCount, rowCount;		//initialize all variables
	int rowCheck = 0, colCheck = 0, knightCheck = 0;
	int row=0, col=0, checker=0;


	// printf("Enter N: ");
	// scanf("%d", &N);

	for(i=0; i<4; i++){					//initialize 4x4 board
		for(j=0; j<4; j++){
			board[i][j] = 0;
		}
	}

	
	while(row < 4){										//traverse board one by one
		board[row][col] = 1;							//initialize one 1 element
		for(i=0; i<4; i++){								//traverse board to add other 1 elements
			for(j=0; j<4; j++){
				if(board[i][j] == 0){					//if element is 0, check if it can be 1 without bumping into other 1s
					for(a=0; a<4; a++){
						if(board[i][a]==1) rowCheck += 1;			//check rook move horizontal
					}
					for(b=0; b<4; b++){
						if(board[b][j]==1) colCheck += 1;			//check rook move vertical
					}

					if((board[i+2][j+1]==1) && (i+2 < 4) && (j+1 < 4)) knightCheck += 1;		//check all possible knight moves
					if((board[i-2][j+1]==1) && (i-2 >= 0) && (j+1 < 4)) knightCheck += 1;
					if((board[i+2][j-1]==1) && (i+2 < 4) && (j-1 >= 0)) knightCheck += 1;
					if((board[i-2][j-1]==1) && (i-2 >= 0) && (j-1 >= 0)) knightCheck += 1;

					if((board[i+1][j+2]==1) && (i+1 < 4) && (j+2 < 4)) knightCheck += 1;
					if((board[i-1][j+2]==1) && (i-1 >= 0) && (j+2 < 4)) knightCheck += 1;
					if((board[i+1][j-2]==1) && (i+1 < 4) && (j-2 >= 0)) knightCheck += 1;
					if((board[i-1][j-2]==1) && (i-1 >= 0) && (j-2 >= 0)) knightCheck += 1;

					if((rowCheck==0) && (colCheck==0) && (knightCheck==0)) board[i][j] = 1;			//check if no 1 conincides, if none turn 0 to 1
					rowCheck = 0;				//reset checkers
					colCheck = 0;
					knightCheck = 0;
				}

			}
		}
		checker = 0;
		for(rowCount=0; rowCount<4; rowCount++){					//check if how many 1 is in the board
			for(colCount=0; colCount<4; colCount++){
				if(board[rowCount][colCount]==1) checker += 1;
			}
		}

		if(checker <= 4) count += 1;				//if there is equal or more than 4 (since N=4) 1 in the board, add it to the no. of solution

		for(emp=0; emp<4; emp++){					//reset all values in the board
			for(empty=0; empty<4; empty++){
				board[emp][empty] = 0;
			}
		}

		if(col < 3) col += 1;			//update which element will be the initialized 1 next iteration
		else{
			row += 1;
			col = 0;
		}
	}

	printf("%d\n", count/2);				//print no. of solution
}

