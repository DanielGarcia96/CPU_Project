#include <limits.h>
#include "alu.h"

// U100
short addsub(short a, short b, char verbose)
{
    short i, short_size = sizeof(short) * CHAR_BIT;
    short add_result, sub_result;

    for(i = 0; i < short_size; i++)
    {
        short c = a & b;
        c <<= 1;
        a ^= b;
        b = c;
    }

    add_result = a;
    b = -b;

    for(i = 0; i < short_size; i++)
    {
        short c = a & b;
        c <<= 1;
        a ^= b;
        b = c;
    }

    sub_result = a;
    return add_result;
}

// U101
short and_impl(short a, short b, char verbose)
{
    return a & b;
}

// U102
short or_impl(short a, short b, char verbose)
{
    return a | b;
}

// U103
short xor_impl(short a, short b, char verbose)
{
    return a ^ b;
}

// U104
short not_impl(short b, char verbose)
{
    return ~b;
}
