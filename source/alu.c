#include <limits.h>
#include "alu.h"

int add(int a, int b, char verbose)
{
    int i, int_size = sizeof(int) * CHAR_BIT;
    for(i = 0; i < int_size; i++)
    {
        int c = a & b;
        c <<= 1;
        a ^= b;
        b = c;
    }

    return a;
}

int sub(int a, int b, char verbose)
{
    return add(a, twos_complement(b, verbose), verbose);
}

int twos_complement(int a, char verbose)
{
    a = ~a;
    return add(a, 1, verbose);
}
