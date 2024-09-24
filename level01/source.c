#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char a_user_name[256];

int verify_user_name(void) {
	puts("verifying username....\n");
	return strncmp("dat_wil", a_user_name, 7);
}

int verify_user_pass(char* param_1) { return strncmp("admin", param_1, 5); }

int main(void) {
	int ret;
	char input[16];
	int is_ok;

	for (int i = 0; i < 16; i++) {
		input[i] = '\0';
	}
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	is_ok = verify_user_name();
	if (verify_user_name() == 0) {
		puts("Enter Password: ");
		fgets(input, 100, stdin);
		is_ok = verify_user_pass(input);
		if ((is_ok == 0) || (is_ok != 0)) {
			puts("nope, incorrect password...\n");
			ret = 1;
		} else {
			ret = 0;
		}
	} else {
		puts("nope, incorrect username...\n");
		ret = 1;
	}
	return ret;
}