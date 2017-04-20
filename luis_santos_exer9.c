// SANTOS, VAN ELIOT G.
// LUIS, BRENT IAN
// CMSC 142 EXER 9

#include <stdio.h>
#include <stdlib.h>
#define N 3

int main(){
	int start, move;
	int nopts[N+2]; //array top of stacks
	int option[N+2][N+2]; //array stacks of options
	int i, j, candidate, flag;

	// init option
	for(i=0; i<N+2; i++) {
		for(j=0; j<N+2; j++) {
			option[i][j] = 0;
		}	
	}

	// init nopts to 0
	for(i=0; i<N+2; i++) {
		nopts[i] = 0;
	}

	move = start = 0; 
	nopts[start]= 1;
	
	while (nopts[start] >0) {
		if(nopts[move]>0) {
			printf("move++\n");
			move++;
			nopts[move]=0; //initialize new move

			if(move == 1) {
				for(candidate = 1; candidate <= N-move+1; candidate++) {
					nopts[move]++;
					option[move][nopts[move]] = candidate;
				}
			} else {//populate; find candidates
				for(candidate = 1; candidate <= N-move+1; candidate++) {
					printf("nopts[%i] > nopts[%i]+1\n", move-1, move);
					printf("%i > %i\n", nopts[move-1], nopts[move]+1);

					// increment only if nopts[move]+1 > nopts[move] (to the left) 
					if(nopts[move-1] > nopts[move]+1) {
						printf("true, nopts[move]++\n");

						nopts[move]++;
						option[move][nopts[move]] = candidate;
					} else {
						printf("false\n");
					}
				}
			}
			printf("\n");
			for(i=0; i<N+2; i++) {
				for(j=0; j<N+2; j++) {
					printf("%i ", option[i][j]);
				}				
				printf("\n");	
			}
			printf("\n");
			printf("move: %i\n", move);
			printf("nopts[] ");
			for(i=0; i<N+2; i++) {
				printf("%i ", nopts[i]);
			}
			printf("\n\n-----------------\n\n");
		} else {
			//backtrack
			printf("backtrack\n");
			//print - solution found!
			//print before decrementing move
			printf("\t\t\t\t\t\t");
			for(i=1;i<move;i++)
				printf("%3i",option[i][nopts[i]]);
			printf("\n");
			
			printf("move--\n");
			move--;
			nopts[move]--;

			printf("move: %i\n", move);
			printf("nopts[] ");
			for(i=0; i<N+2; i++) {
				printf("%i ", nopts[i]);
			}
			printf("\n\n-----------------\n\n");

		}
	}
}
