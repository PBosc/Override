#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

int auth(char* username, uint serial) {
	size_t len;
	int ret;
	uint hash;

	len = strcspn(username, "\n");
	username[len] = '\0';
	len = strnlen(username, 32);
	if (len < 6) {
		ret = 1;
	} else {
		if (ptrace(PTRACE_TRACEME) == -1) {
			puts("\x1b[32m.---------------------------.");
			puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
			puts("\x1b[32m\'---------------------------\'");
			ret = 1;
		} else {
			hash = (username[3] ^ 0x1337) + 0x5eeded;
			for (int i = 0; i < len; i++) {
				if (username[i] < ' ') return 1;
				hash += (username[i] ^ hash) % 0x539;
			}
			if (serial == hash) {
				ret = 0;
			} else {
				ret = 1;
			}
		}
	}
	return ret;
}

int main(void) {
	char username[32];
	int serial;

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(username, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%d", &serial);
	if (auth(username, serial) == 0) {
		puts("Authenticated!");
		system("/bin/sh");
		return 0;
	}
	return 1;
}