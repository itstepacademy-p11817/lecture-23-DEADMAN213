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

void sortMas(int32_t* mas, uint8_t size) {
	for (uint8_t i = 0; i < size - 1; i++) {
		for (uint8_t j = i + 1; j < size; j++) {
			if (mas[j] < mas[i]) {
				uint32_t box = mas[i];
				mas[i] = mas[j];
				mas[j] = box;
			}
		}
	}
}

int main(void) {
	int32_t mas[100] = { 0 };
	uint8_t size = 0;

	srand((unsigned int)time(NULL));

	printf("Input size: ");
	scanf_s("%hhi", &size);
	initMas(mas, size);

	printf("Mass befor sort: ");
	printMas(mas, size);

	sortMas(mas, size);

	printf("Mass after sort: ");
	printMas(mas, size);


	return 0;
}
