#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void printDigits(uint64_t val) {
	uint8_t* pval = (uint8_t*)&val;

	for (uint64_t i = 0; i < sizeof(val); i++) {
		uint8_t mask = 128;
		for (uint8_t j = 0; j < 8; j++) {
			if (*(pval + i) & mask) {
				printf("1");
			}
			else {
				printf("0");
			}
			mask >>= 1;
		}
		printf(" ");
	}
	printf("\n");
}

uint64_t littleEndian(uint64_t val) {
	uint64_t rez = 0;
	uint8_t* prez = (uint8_t*)&rez;

	for (uint8_t i = 0; i < sizeof(val), val > 0; i++) {
		uint8_t mask = 1;

		for (uint8_t j = 0; j < 8; j++) {
			if (val % 2 == 1) {
				*(prez + i) |= mask;
			}
			mask <<= 1;
			val /= 2;
		}
	}

	return rez;
}

uint64_t bigEndian(uint64_t val) {
	uint64_t rez = 0;
	uint8_t* prez = (uint8_t*)&rez + sizeof(val) - 1;

	for (uint8_t i = 0; i < sizeof(val), val > 0; i++) {
		uint8_t mask = 1;
		for (uint8_t j = 0; j < 8; j++) {
			if (val % 2 == 1) {
				*(prez - i) |= mask;
			}
			mask <<= 1;
			val /= 2;
		}
	}

	return rez;
}

int32_t main(void) {
	uint64_t val = 0;
	uint64_t num = 0;
	printf("Input positive value: ");
	scanf("%llu", &val);

	printf("Digits of entered value: \n");
	printDigits(val);

	if ((num = littleEndian(val)) == val) {
		printf("Is little-endian: \n");
	}
	else if ((num = bigEndian(val)) == val) {
		printf("Is big-endian: \n");
	}
	printDigits(num);

	return 0;
}