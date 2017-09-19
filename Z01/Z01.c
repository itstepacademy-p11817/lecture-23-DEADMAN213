#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void initMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		*(val + i) = rand() % 31;
	}
}

void printMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		printf("%3i", *(val + i));
	}
	printf("\n");
}

bool isSimple(uint32_t val) {
	if (val == 0 || val == 1) {
		return false;
	}

	if (val == 2) {
		return true;
	}


	for (uint8_t i = 2; i <= (uint8_t)sqrt(val); i++) {
		if (val%i == 0) {
			return true;
		}
	}

	return false;
}

uint8_t dellMas(uint32_t* mas, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {

		if (isSimple(mas[i])) {
			for (uint8_t j = i; j <= size - 1; j++) {
				mas[j] = mas[j + 1];
			}
			size -= 1;
			i--;
		}

	}

	return size;
}

int main(void) {
	uint32_t mas[100] = { 0 };
	uint8_t size = 0;

	srand((unsigned int)time(NULL));

	printf("Input size: ");
	scanf_s("%hhi", &size);
	initMas(mas, size);

	printf("Mass befor deleeting: ");
	printMas(mas, size);

	size = dellMas(mas, size);

	printf("Mass after deleeting: ");
	printMas(mas, size);

	return 0;
}
