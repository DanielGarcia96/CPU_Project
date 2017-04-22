#include <limits.h>
#include "alu.h"

// U14
void stack_pointer_impl(short updated_value)
{
    return 0;
}

// U100
short addsub(short *a, short *b, char verbose)
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
short and_impl(short *a, short *b, char verbose)
{
    return a & b;
}

// U102
short or_impl(short *a, short *b, char verbose)
{
    return a | b;
}

// U103
short xor_impl(short *a, short *b, char verbose)
{
    return a ^ b;
}

// U104
short not_impl(short *b, char verbose)
{
    return ~b;
}

// U107
short stack_addsub(short *sp, char plusminus, char align)
{
    align = 2;
    return 0;
}

// U112
void mux_112(char select_a, char select_b, char verbose)
{
    short *register_pointera;
    short *register_pointerb = mux_113(select_b);

    switch(select_a) 
    {
        case 0:
            register_pointera = &r0;
        break;
        case 1:
            register_pointera = &r1;
        break;
        case 2:
            register_pointera = &r2;
        break;
        case 3:
            register_pointera = &r3;
        break;
        default:
            fprintf(stderr, "Incorrect Select Input");
    }

    addsub(*register_pointera, *register_pointerb, verbose);
    addsub(*register_pointera, *register_pointerb, verbose);
    and_impl(*register_pointera, *register_pointerb, verbose);
    or_impl(*register_pointera, *register_pointerb, verbose);
    xor_impl(*register_pointera, *register_pointerb, verbose);
    not_impl(*register_pointera, *register_pointerb, verbose);
}

// U113
short * mux_113(char select)
{
    switch(select) 
    {
        case 0:
            return &r0;
        break;
        case 1:
            return &r1;
        break;
        case 2:
            return &r2;
        break;
        case 3:
            return &r3;
        break;
        default:
            fprintf(stderr, "Incorrect Select Input");
            return NULL;
    }
}

// U117
void mux_U117(char select)
{
    
}

// U118
void mux_U118A(short select)
{
    
}

// U118
void mux_U118B(short select)
{
    
}
