#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void initMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		*(val + i) = rand() % 11;

		if (rand() % 2 == 1) {
			*(val + i) = -*(val + i);
		}
	}
}

void printMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		printf("%4i", *(val + i));
	}
	printf("\n");
}

bool compMas(int32_t* masA, int32_t* masB, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		if (abs(masA[i]) != abs(masB[i])) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int32_t masA[100] = { 0 };
	int32_t masB[100] = { 0 };
	uint8_t size = 0;

	srand((unsigned int)time(NULL));

	printf("Input size of mas: ");
	scanf_s("%hhi", &size);
	initMas(masA, size);
	initMas(masB, size);

	printf("Mass A: ");
	printMas(masA, size);

	printf("Mass B: ");
	printMas(masB, size);

	compMas(masA, masB, size) ? printf("Masses is equal.\n") : printf("Masses not equal.\n");

	return 0;
}
