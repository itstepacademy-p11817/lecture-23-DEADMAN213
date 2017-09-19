#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 9
#define COLLS 12

void initBoard(uint8_t board[ROWS][COLLS]) {
	srand((unsigned int)time(NULL));
	for (uint8_t i = 0; i < ROWS; i++) {
		for (uint8_t j = 0; j < COLLS; j++) {
			board[i][j] = rand() % 2;
		}
	}
}

void printBoard(uint8_t board[ROWS][COLLS], uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	for (uint8_t i = 0; i < ROWS; i++) {
		for (uint8_t j = 0; j < COLLS; j++) {
			if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
				printf("%3c", 'C');
			}
			else if (board[i][j] == 1) {
				printf("%3hhi", board[i][j]);
			}
			else {
				printf("%3hhi", 0);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void weightCells(uint8_t board[ROWS][COLLS]) {
	for (uint8_t i = 0; i < ROWS; i++) {
		for (int8_t j = COLLS - 1; j >= 0; j--) {
			int8_t ind = j;
			if (board[i][j] == 0) {
				uint8_t num = 2;
				while (board[i][ind] == 0 && ind >= 0) {
					board[i][ind--] = num++;
				}
				j = ind;
			}
		}
	}
}

uint8_t rectFind(uint8_t board[ROWS][COLLS], uint8_t* x1, uint8_t* x2, uint8_t* y1, uint8_t* y2) {
	uint8_t square = 0;
	for (uint8_t i = 0; i < ROWS; i++) {
		for (uint8_t j = 0; j < COLLS; j++) {
			if (board[i][j] > 1) {
				int8_t indi = i;
				uint8_t rows = board[indi][j] - 1;
				
				while (indi <= ROWS - 1 && board[indi][j] > 1) {
					indi++;
					uint8_t curSquare = (indi - i)*rows;
					if ((indi > ROWS - 1 || board[indi][j] - 1 < rows) && curSquare > square) {
						*x1 = i;
						*y1 = j;
						*x2 = indi - 1;
						*y2 = j + rows - 1;
						square = curSquare;
					}

					if (board[indi][j] - 1 < rows && indi <= ROWS - 1) {
						rows = board[indi][j] - 1;
					}
				}

			}
		}
	}

	return square;
}

int main() {
	uint8_t x1 = 0;
	uint8_t x2 = 0;
	uint8_t y1 = 0;
	uint8_t y2 = 0;
	uint8_t s = 0;
	uint8_t board[ROWS][COLLS] = { 0 };
	
	initBoard(board);
	printBoard(board, ROWS, COLLS, ROWS, COLLS);

	weightCells(board);
	s = rectFind(board, &x1, &x2, &y1, &y2);
	printf("  [%d, %d] - [%d, %d]: %d.\n\n", x1, y1, x2, y2, s);
	printBoard(board, x1, y1, x2, y2);

	return 0;
}