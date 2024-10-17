#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char a_user_name[256];

int verify_user_name(void)
{
    puts("verifying username....\n");
    return strncmp("dat_wil", a_user_name, 7);
}

int verify_user_pass(char *input) { return strncmp("admin", input, 5); }

int main(void)
{
    char input[16];
    int is_ok;

    for (int i = 0; i < 16; i++)
        input[i] = '\0';
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(a_user_name, 256, stdin);
    is_ok = verify_user_name();
    if (verify_user_name())
    {
        puts("nope, incorrect username...\n");
        return 1;
    }
    puts("Enter Password: ");
    fgets(input, 100, stdin);
    is_ok = verify_user_pass(input);
    if ((is_ok == 0) || (is_ok != 0))
    {
        puts("nope, incorrect password...\n");
        return 1;
    }
    return 0;
}