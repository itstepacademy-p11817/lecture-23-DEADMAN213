#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void printDigits(uint8_t val) {
	uint8_t mask = 128;

	for (uint8_t i = 0; i < 8; i++) {
		if (mask&val) {
			printf("1");
		}
		else {
			printf("0");
		}
		mask >>= 1;
	}
	printf("\n");
}

int8_t typeEncoding(uint8_t val) {
	int8_t rez = 0;
	uint8_t mask = 1;

	while (val > 0) {
		if (val % 2 == 1) {
			rez |= mask;
		}
		val /= 2;
		mask <<= 1;
	}

	return rez;
}

int32_t main(void) {
	int8_t val = 0;
	int8_t num = 0;
	printf("Input value (from -127 to -1): ");
	scanf("%hhi", &val);

	printf("Digits of inputed vslue: ");
	printDigits(val);

	if ((num = typeEncoding(128 - val)) == val) {
		printf("Value in Signed magnitude representation: ");
	}
	if ((num = typeEncoding(128 + val)) == val) {
		printf("Value in Offset binary: ");
	}
	if ((num = typeEncoding(256 + val)) == val) {
		printf("Value in Two's complement: ");
	}
	
	printDigits(num);

	return 0;
}