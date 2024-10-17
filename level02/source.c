#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    size_t tmp;
    char input_password[14];
    char password[6];
    char username[12];
    FILE *password_file;

    for (int i = 0; i < 12; i++)
        username[i] = '\0';
    for (int i = 0; i < 5; i++)
        password[i] = '\0';
    for (int i = 0; i < 12; i++)
        input_password[i] = '\0';

    password_file = fopen("/home/users/level03/.pass", "r");
    if (password_file == NULL)
    {
        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
    }
    tmp = fread(password, 1, 41, password_file);
    if (tmp != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
    }
    tmp = strcspn(password, "\n");
    password[tmp] = '\0';
    fclose(password_file);

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets(username, 100, stdin);
    tmp = strcspn(username, "\n");
    username[tmp] = '\0';
    printf("--[ Password: ");
    fgets(input_password, 100, stdin);
    tmp = strcspn(input_password, "\n");
    input_password[tmp] = '\0';
    puts("*****************************************");
    if (strncmp(password, input_password, 41) == 0)
    {
        printf("Greetings, %s!\n", username);
        system("/bin/sh");
        return 0;
    }
    printf(username);
    puts(" does not have access!");
    exit(1);
}
