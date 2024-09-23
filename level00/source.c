#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input[4];

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", input);
	if (input[0] == 5276) {
		puts("\nAuthenticated!");
		system("/bin/sh");
	} else {
		puts("\nInvalid Password!");
	}
	return input[0] != 5276;
}