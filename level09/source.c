#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct message_s {
    char message[140];
    char username[40];
    int len;
} message_t;

void secret_backdoor(void)
{
    char input[128];

    fgets(input, 128, stdin);
    system(input);
    return;
}

void set_msg(char *param_1)
{
    char input[1024];

    for (int i = 0; i < 1024; i++)
    {
        input[i] = '\0';
    }
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(input, 1024, stdin);
    strncpy(param_1, input, (long)*(int *)(param_1 + 180));
    return;
}

void set_username(char *param_1)
{
    char input[140];

    for (int i = 0; i < 128; i++)
        input[i] = '\0';
    puts(">: Enter your username");
    printf(">>: ");
    fgets(input, 128, stdin);
    for (int i = 0; i < 41 && input[i] != '\0'; i++)
        param_1[i + 140] = input[i];
    printf(">: Welcome, %s", param_1 + 140);
    return;
}

void handle_msg(void)
{
    message_t message;

    memset(message.username, 0, 40);
    message.len = 140;
    set_username(message.message);
    set_msg(message.message);
    puts(">: Msg sent!");
    return;
}

int main(void)
{
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return 0;
}