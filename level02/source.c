#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	size_t sVar2;
	long lVar3;
	char* puVar4;
	char local_118[14];
	char local_a8[6];
	char local_78[12];
	int local_14;
	FILE* local_10;

	puVar4 = local_78;
	for (lVar3 = 12; lVar3 != 0; lVar3--) {
		*puVar4 = 0;
		puVar4++;
	}
	puVar4 = local_a8;
	for (lVar3 = 5; lVar3 != 0; lVar3--) {
		*puVar4 = 0;
		puVar4++;
	}
	puVar4 = local_118;
	for (lVar3 = 12; lVar3 != 0; lVar3--) {
		*puVar4 = 0;
		puVar4++;
	}
	local_14 = 0;
	local_10 = fopen("/home/users/level03/.pass", "r");
	if (local_10 == (FILE*)0x0) {
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	sVar2 = fread(local_a8, 1, 41, local_10);
	local_14 = (int)sVar2;
	sVar2 = strcspn((char*)local_a8, "\n");
	*(undefined*)((long)local_a8 + sVar2) = 0;
	if (local_14 != 41) {
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(local_10);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets((char*)local_78, 100, stdin);
	sVar2 = strcspn((char*)local_78, "\n");
	*(undefined*)((long)local_78 + sVar2) = 0;
	printf("--[ Password: ");
	fgets((char*)local_118, 100, stdin);
	sVar2 = strcspn((char*)local_118, "\n");
	*(undefined*)((long)local_118 + sVar2) = 0;
	puts("*****************************************");
	if (strncmp((char*)local_a8, (char*)local_118, 41) == 0) {
		printf("Greetings, %s!\n", local_78);
		system("/bin/sh");
		return 0;
	}
	printf((char*)local_78); // \xe0\x11\x60
	puts(" does not have access!");
	exit(1);
}
