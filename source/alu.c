#include <limits.h>
#include <stdio.h>
#include "alu.h"

// U14
void stack_pointer_impl(reg_t updated_value)
{
    return;
}

// U100
reg_t addsub(reg_t a, reg_t b, char verbose)
{
    reg_t i, reg_t_size = sizeof(reg_t) * CHAR_BIT;
    reg_t add_result, sub_result;

    for(i = 0; i < reg_t_size; i++)
    {
        reg_t c = a & b;
        c <<= 1;
        a ^= b;
        b = c;
    }

    add_result = a;
    b = -b;

    for(i = 0; i < reg_t_size; i++)
    {
        reg_t c = a & b;
        c <<= 1;
        a ^= b;
        b = c;
    }

    sub_result = a;
    return add_result;
}

// U101
reg_t and_impl(reg_t a, reg_t b, char verbose)
{
    return a & b;
}

// U102
reg_t or_impl(reg_t a, reg_t b, char verbose)
{
    return a | b;
}

// U103
reg_t xor_impl(reg_t a, reg_t b, char verbose)
{
    return a ^ b;
}

// U104
reg_t not_impl(reg_t b, char verbose)
{
    return ~b;
}

// U107
reg_t stack_addsub(reg_t *sp, char plusminus, char align)
{
    align = 2;
    return 0;
}

// U112
void mux_112(char select_a, char select_b, char verbose)
{
    reg_t *register_pointera;
    reg_t *register_pointerb = mux_113(select_b);

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
    and_impl(*register_pointera, *register_pointerb, verbose);
    or_impl(*register_pointera, *register_pointerb, verbose);
    xor_impl(*register_pointera, *register_pointerb, verbose);
    not_impl(*register_pointerb, verbose);
}

// U113
reg_t * mux_113(char select)
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
void mux_U118A(reg_t select)
{
    
}

// U118
void mux_U118B(reg_t select)
{
    
}
