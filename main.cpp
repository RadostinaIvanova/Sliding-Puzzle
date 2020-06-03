#include <iostream>
#include "Puzzle-8.h"

int main() {
	unsigned int start_puzzle1[PUZZLE_SIZE][PUZZLE_SIZE] = { { 2, 5, 1 },
															 { 6, 3, 7 },
															 { 4, 0, 8 } };

	unsigned int start_puzzle2[PUZZLE_SIZE][PUZZLE_SIZE] = { { 1, 0, 2 },
															 { 4, 5, 3 },
															 { 7, 8, 6 } };

	unsigned int start_puzzle3[PUZZLE_SIZE][PUZZLE_SIZE] = { { 8, 6, 7 },
															 { 2, 5, 4 },
		                                                     { 3, 0, 1 } };

	unsigned int start_puzzle4[PUZZLE_SIZE][PUZZLE_SIZE] = { { 6, 8, 3 },
															 { 4, 7, 2 },
															 { 5, 1, 0 } };

	unsigned int start_puzzle5[PUZZLE_SIZE][PUZZLE_SIZE] = { { 8, 6, 7 },
															 { 2, 5, 4 },
															 { 3, 0, 1 } };

	unsigned int start_puzzle6[PUZZLE_SIZE][PUZZLE_SIZE] = { { 1,2,3 },
															 { 0,4,6 },
															 { 7,5,8 } };


    Puzzle solvePuzz(start_puzzle2);
	return 0;
}
