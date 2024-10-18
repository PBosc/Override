#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    int input;
    scanf("%d", &input);

    input = 322424845 - input;

    char start[17] = "Q}|u`sfg~sf{}|a3";
    for (int i = 0; start[i]; i++)
        start[i] ^= input;
    
    if (strcmp("Congratulations!", start))
        return puts("\nInvalid Password");
    return system("/bin/sh");
}