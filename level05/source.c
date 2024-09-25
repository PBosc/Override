#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char input[100]; // 0xffffd6c8

	fgets(input, 100, stdin);
	for (int i = 0; input[i]; i++) {
		// to_lower
		if (('@' < input[i]) && (input[i] < '[')) {
			input[i] ^= 32;
		}
	}
	printf(input);
	exit(0);
}