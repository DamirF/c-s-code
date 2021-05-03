#pragma (disable:4339)
#include <stdio.h>
#include <string.h>

#define N 80

int main()
{
    char* smb, code[N], encode[2 * N] = "", str[N];
    int cnt = 1;

    fgets(code, 80, stdin);
    smb = code;

    for (int i = 1; i < strlen(code); i++, smb++, cnt++) if (code[i] != *smb)
    {
        sprintf(encode + strlen(encode), "%d%c", cnt, *smb);
        cnt = 0;
    }

    printf("%s\n", encode);
    return 0;
}