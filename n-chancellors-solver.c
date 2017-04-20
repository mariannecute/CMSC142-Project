/**
 * Authors:
 * Name
 * Name
 * Name
 * CMSC 142 C-3L
 *
 * Program Description:
 * ...
 */

#include <stdio.h>
#include <stdlib.h>

//iterative backtracking in getting the number of solutions
int backtracking(int *board, int dimension){
	int start, move;
	int nopts[dimension+2];		//array top of stacks
	int option[dimension+2][dimension+2];	//array stacks of options
	int i, j, candidate, flag, num_of_solutions;

	//init option
	for(i=0; i<dimension+2; i++){
		for(j=0; j<dimension+2; j++){
			option[i][j] = 0;
		}//for
	}//for

	//init nopts to 0
	for(i=0; i<dimension+2; i++){
		nopts[i] = 0;
	}//for

	move = start = 0; 
	nopts[start] = 1;

/*
	while(nopts[start] >0){
		if(nopts[move]>0){

		} else{		//backtrack

		}//else
	}//while
*/

	return num_of_solutions;
}//backtracking

int main(){
	int num_of_puzzles, dimension, i, j, num_of_solutions;

	FILE *fp = fopen("input.in", "r");

	fscanf(fp, "%d", &num_of_puzzles);

	if(fp == NULL){		//detects no file or error file reading
		printf("Error file reading!\n");
	} else{
		while(!feof(fp)){
			fscanf(fp, "%d", &dimension);

			//initializes and allocates board base from the dimension
		    int *board[dimension];
		    for(i=0; i<dimension; i++){
		        board[i] = (int *)malloc(dimension * sizeof(int));
		    }//for

		    //scans puzzle and stores them into board 2d array
		    for(i=0; i<dimension; i++){
		     	for (j=0; j<dimension; j++){
		        	fscanf(fp, "%d ", &board[i][j]);
		     	}//for
		    }//for

		    //prints initial positions of the chancellors
		    for(i=0; i<dimension; i++){
		     	for (j=0; j<dimension; j++){
		        	printf("%d ", board[i][j]);
		     	} printf("\n");
		    }//for

			//prints number of solutions of the corresponding board
		    num_of_solutions = backtracking(*board, dimension);
		    printf("%d solutions\n\n", num_of_solutions);
		}//while
	}//else

	fclose(fp);

	return 0;
}//main