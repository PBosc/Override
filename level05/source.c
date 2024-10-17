#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char input[100];

    fgets(input, 100, stdin);
    for (int i = 0; input[i]; i++)
    {
        if (('@' < input[i]) && (input[i] < '['))
            input[i] ^= 32;
    }
    printf(input);
    exit(0);
}