#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

int auth(char *username, unsigned int serial)
{
    size_t len;
    unsigned int hash;

    len = strcspn(username, "\n");
    username[len] = '\0';
    len = strnlen(username, 32);
    if (len < 6)
        return 1;

    if (ptrace(PTRACE_TRACEME) == -1)
    {
        puts("\x1b[32m.---------------------------.");
        puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
        puts("\x1b[32m\'---------------------------\'");
        return 1;
    }

    hash = (username[3] ^ 0x1337) + 0x5eeded;
    for (int i = 0; i < len; i++)
    {
        if (username[i] < ' ')
            return 1;
        hash += (username[i] ^ hash) % 0x539;
    }

    return serial != hash;
}

int main(void)
{
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
    if (auth(username, serial) == 0)
    {
        puts("Authenticated!");
        system("/bin/sh");
        return 0;
    }
    return 1;
}