/**
 * Authors:
 * Jaro, Jeriel
 * Luis, Brent Ian
 * Rivera, Marianne Louise
 * CMSC 142 C-3L
 *
 * Program Description:
 * A program that solves the N-Chancellor Problem and its modification by providing all possible solutions and their count using iterative backtracking algoritm
 */

#include <stdio.h>
#include <stdlib.h>

//iterative backtracking function in getting the number of solutions
int backtracking(int *board, int dimension){
	int num_of_solutions;

	return num_of_solutions;
}//backtracking

int main(){
	int num_of_puzzles, num_of_solutions;
	int dimension, puzzle;
	int i, j;

	FILE *fp_input, *fp_output;

	fp_input = fopen("input.txt", "r");

	fscanf(fp_input, "%d", &num_of_puzzles);

	if(fp_input == NULL){		//detects no file or error file reading
		printf("Error file reading!\n");
	} else{
		for(puzzle=0; puzzle<num_of_puzzles; puzzle++){
			fscanf(fp_input, "%d", &dimension);

			//initializes and allocates the board base from the dimension
		    int *board[dimension];
		    for(i=0; i<dimension; i++){
		        board[i] = (int *)malloc(dimension * sizeof(int));
		    }//for

		    //scans matrix input and stores them into the board 2d array
		    for(i=0; i<dimension; i++){
		     	for (j=0; j<dimension; j++){
		        	fscanf(fp_input, "%d ", &board[i][j]);
		     	}//for
		    }//for

		    /* prints the 2d array of the initial positions of the chancellors
		     * for checking lang kung tama yung na-read sa input
		    for(i=0; i<dimension; i++){
		     	for (j=0; j<dimension; j++){
		        	fprintf(fp_output,"%d ", board[i][j]);
		     	} fprintf(fp_output, "\n");
		    }//for
		    */

		    //outputs the number of solutions to text file
		    fp_output = fopen("output.txt", "a");
		    fprintf(fp_output, "Puzzle %d: %d solutions\n", puzzle+1, num_of_solutions);
		    fclose(fp_output);
		}//while
	}//else

	fclose(fp_input);

	return 0;
}//main