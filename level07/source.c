#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void clear_stdin(void)
{
    int chr;
    do
    {
        chr = getchar();
        if (chr == '\n')
            return;
    } while (chr != -1);
}

// TODO Recook
unsigned int get_unum(void)
{
    unsigned int input[3];

    input[0] = 0;
    fflush(stdout);
    scanf("%u", input);
    clear_stdin();
    return input[0];
}

int store_number(int *storage)
{
    unsigned int data;
    unsigned int idx;

    printf(" Number: ");
    data = get_unum();
    printf(" Index: ");
    idx = get_unum();
    if (idx % 3 == 0 || (data >> 24 == 183))
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }
    storage[idx] = data;
    return 0;
}

int read_number(int *storage)
{
    printf(" Index: ");
    unsigned int idx = get_unum();
    printf(" Number at data[%u] is %u\n", idx, storage[idx]);
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    char c;
    int in_GS_OFFSET;
    int storage[100];
    int ret = 0;
    char command[20];
    int local_14;

    local_14 = *(int *)(in_GS_OFFSET + 0x14);
    for (int i = 0; i < 100; i++)
        storage[i] = 0;
    for (int i = 0; argv[i]; i++)
        memset(argv[i], 0, strlen(argv[i]));
    for (int i = 0; envp[i]; i++)
        memset(envp[i], 0, strlen(envp[i]));

    puts("----------------------------------------------------\n  Welcome to wil\'s crappy number "
         "storage service!   \n----------------------------------------------------\n Commands:    "
         "                                      \n    store - store a number into the data storage "
         "   \n    read  - read a number from the data storage     \n    quit  - exit the program  "
         "                      \n----------------------------------------------------\n   wil has "
         "reserved some storage :>                 "
         "\n----------------------------------------------------\n");
    do
    {
        for (int i = 0; i < 20; i++)
            command[i] = '\0';
        printf("Input command: ");
        ret = 1;
        fgets(&command, 20, stdin);
        if (strncmp(command, "store", 5))
        {
            ret = store_number(storage);
        }
        else
        {
            if (strncmp(command, "read", 4))
                ret = read_number(storage);
            else if (strncmp(command, "quit", 4))
                return 0;
        }
        if (ret == 0)
            printf(" Completed %s command successfully\n", command);
        else
            printf(" Failed to do %s command\n", command);
    } while (true);
}
