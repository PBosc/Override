#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void clear_stdin(void) {
	int iVar1;

	do {
		iVar1 = getchar();
		if ((char)iVar1 == '\n') {
			return;
		}
	} while ((char)iVar1 != -1);
}

// TODO Recook
unsigned int get_unum(void) {
	unsigned int input[3];

	input[0] = 0;
	fflush(stdout);
	scanf("%d", input);
	clear_stdin();
	return input[0];
}

int store_number(int* storage) {
	unsigned int data;
	unsigned int idx;
	int ret;

	printf(" Number: ");
	data = get_unum();
	printf(" Index: ");
	idx = get_unum();
	if (idx % 3 == 0 || (data >> 24 == 183)) {
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		ret = 1;
	} else {
		storage[idx] = data;
		ret = 0;
	}
	return ret;
}

int read_number(int* storage) {
	printf(" Index: ");
	unsigned int idx = get_unum();
	printf(" Number at data[%u] is %u\n", idx, storage[idx]);
	return 0;
}

int main(int argc, char** args, char** envp) {
	char c;
	int iVar2;
	uint uVar3;
	char* tmp;
	char* pcVar5;
	byte* pbVar6;
	int in_GS_OFFSET;
	bool bVar7;
	bool bVar8;
	bool bVar9;
	char** local_1c8;
	char** local_1c4;
	int storage[100];
	int ret;
	char command[20];

	int local_14;

	local_1c4 = args;
	local_1c8 = envp;
	local_14 = *(int*)(in_GS_OFFSET + 0x14);
	ret = 0;
	for (int i = 0; i < 100; i++)
		storage[i] = 0;
	for (; *local_1c4 != (char*)0x0; local_1c4++) {
		uVar3 = 0xffffffff;
		pcVar5 = *local_1c4;
		do {
			if (uVar3 == 0) break;
			uVar3--;
			c = *pcVar5;
			pcVar5++;
		} while (c != '\0');
		memset(*local_1c4, 0, ~uVar3 - 1);
	}
	for (; *local_1c8 != (char*)0x0; local_1c8++) {
		uVar3 = 0xffffffff;
		pcVar5 = *local_1c8;
		do {
			if (uVar3 == 0) break;
			uVar3--;
			c = *pcVar5;
			pcVar5++;
		} while (c != '\0');
		memset(*local_1c8, 0, ~uVar3 - 1);
	}
	puts("----------------------------------------------------\n  Welcome to wil\'s crappy number "
		 "storage service!   \n----------------------------------------------------\n Commands:    "
		 "                                      \n    store - store a number into the data storage "
		 "   \n    read  - read a number from the data storage     \n    quit  - exit the program  "
		 "                      \n----------------------------------------------------\n   wil has "
		 "reserved some storage :>                 "
		 "\n----------------------------------------------------\n");
	do {
		for (int i = 0; i < 20; i++)
			command[i] = '\0';
		printf("Input command: ");
		ret = 1;
		fgets((char*)&command, 20, stdin);
		uVar3 = 0xffffffff;
		tmp = &command;
		do {
			if (uVar3 == 0) break;
			uVar3--;
			c = *(char*)tmp;
			tmp++;
		} while (c != '\0');
		uVar3 = ~uVar3;
		bVar7 = uVar3 == 1;
		bVar9 = uVar3 == 2;
		*(undefined*)((int)&ret + uVar3 + 2) = 0;
		if (strncmp(command, "store", 5)) {
			ret = store_number(storage);
		} else {
			if (strncmp(command, "read", 4)) {
				ret = read_number(storage);
			} else if (strncmp(command, "quit", 4)) {
				return 0;
			}
		}
		if (ret == 0) {
			printf(" Completed %s command successfully\n", command);
		} else {
			printf(" Failed to do %s command\n", command);
		}
	} while (true);
}
