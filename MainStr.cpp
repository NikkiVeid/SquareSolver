#include <stdio.h>

#include "MyStrcpy.h"
#include "MyStrlen.h"

int main
{
    const int N_SYMBOLS = 40;

    char str[N_SYMBOLS] = {};
    char cpy[N_SYMBOLS] = {};

    str = getchar();
    printf("Repeat: %s", MyStrcpy(str[],cpy[]));
    printf("Number of symbols: %d", MyStrlen(str[]));
}
