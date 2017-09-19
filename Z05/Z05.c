#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int32_t main(void) {
	int64_t val = 1;
	
	*(uint8_t*)&val == 0 ? printf("Big-endian.\n") : printf("Little-endian.\n");

	return 0;
}