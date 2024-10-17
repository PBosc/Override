#include <stdio.h>
#include <stdbool.h>

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

void prog_timeout(void)
{
    void (*pcVar1)();

    pcVar1 = (void (*)())swi(0x80);
    (*pcVar1)();
    return;
}

int decrypt(EVP_PKEY_CTX *ctx, uchar *out, size_t *outlen, uchar *in, size_t inlen)
{
    char cVar1;
    unsigned int uVar2;
    int iVar3;
    undefined4 *puVar4;
    char *pbVar5;
    int in_GS_OFFSET;
    bool bVar6;
    bool bVar7;
    unsigned int local_2c;
    undefined4 local_21;
    undefined4 local_1d;
    undefined4 local_19;
    undefined4 local_15;
    undefined local_11;
    int local_10;

    local_10 = *(int *)(in_GS_OFFSET + 20);
    local_21 = 0x757c7d51;
    local_1d = 0x67667360;
    local_19 = 0x7b66737e;
    local_15 = 0x33617c7d;
    local_11 = 0;
    uVar2 = 0xffffffff;
    puVar4 = &local_21;
    do
    {
        if (uVar2 == 0)
            break;
        uVar2--;
        cVar1 = *(char *)puVar4;
        puVar4++;
    } while (cVar1 != '\0');
    local_2c = 0;
    while (true)
    {
        bVar6 = local_2c < ~uVar2 - 1;
        bVar7 = local_2c == ~uVar2 - 1;
        if (!bVar6)
            break;
        *(byte *)((int)&local_21 + local_2c) = (byte)ctx ^ *(byte *)((int)&local_21 + local_2c);
        local_2c++;
    }
    iVar3 = 17;
    puVar4 = &local_21;
    pbVar5 = "Congratulations!";
    do
    {
        if (iVar3 == 0)
            break;
        iVar3--;
        bVar6 = *(byte *)puVar4 < *pbVar5;
        bVar7 = *(byte *)puVar4 == *pbVar5;
        puVar4++;
        pbVar5++;
    } while (bVar7);
    if ((!bVar6 && !bVar7) == bVar6)
        iVar3 = system("/bin/sh");
    else
        iVar3 = puts("\nInvalid Password");
    if (local_10 == *(int *)(in_GS_OFFSET + 20))
        return iVar3;
    __stack_chk_fail();
}

void test(int param_1, int param_2)
{
    EVP_PKEY_CTX *pEVar1;
    uchar *in_stack_ffffffd8;
    size_t *in_stack_ffffffdc;
    uchar *in_stack_ffffffe0;
    size_t in_stack_ffffffe4;

    pEVar1 = (EVP_PKEY_CTX *)(param_2 - param_1);
    switch (pEVar1)
    {
    default:
        pEVar1 = (EVP_PKEY_CTX *)rand();
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x1:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x2:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x3:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x4:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x5:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x6:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x7:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x8:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x9:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x10:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x11:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x12:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x13:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x14:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
        break;
    case (EVP_PKEY_CTX *)0x15:
        decrypt(pEVar1, in_stack_ffffffd8, in_stack_ffffffdc, in_stack_ffffffe0, in_stack_ffffffe4);
    }
    return;
}

// TODO mieux
int main(void)
{
    srand(time(NULL));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf();
    test();
    return 0;
}