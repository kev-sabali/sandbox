#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    int value;
    value = increment();
    value = increment();
    value = increment();

    printf("%d\n", value);
    return 0;
}
