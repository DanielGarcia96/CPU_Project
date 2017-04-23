#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "alu.h"

// U14
void stack_pointer_impl(uint16_t updated_value)
{
}

// U100
uint8_t alu_add_sub(uint8_t reg_a, uint8_t reg_b, uint8_t carry_in, uint8_t *overflow, uint8_t *carry_out)
{
    uint8_t s, a, b, c, c_prev;
    uint16_t sum = 0;
    c = carry_in;
    for (uint8_t i = 0; i < sizeof(uint8_t) * 8; i++)
    {
        a = BIT(reg_a, i);
        b = BIT(reg_b, i);
        s = (a ^ b) ^ c;
        sum |= s << i;
        c_prev = c;
        c = ((a ^ b) & c) | (a & b);
    }
    *carry_out = c;
    *overflow = c ^ c_prev;
    return sum;
}

// U101
uint8_t alu_and(uint8_t a, uint8_t b)
{
    return a & b;
}

// U102
uint8_t alu_or(uint8_t a, uint8_t b)
{
    return a | b;
}

// U103
uint8_t alu_xor(uint8_t a, uint8_t b)
{
    return a ^ b;
}

// U104
uint8_t alu_not(uint8_t a)
{
    return ~a;
}

// U107
// uint16_t stack_addsub(uint16_t *sp, char plusminus, char align)
// {
//     align = 2;
//     return 0;
// }

// U110
uint8_t flags_110(uint8_t sum, uint8_t overflow, uint8_t carry_out)
{
    return (overflow   ? FLAG_OVERFLOW : 0)
         | (carry_out  ? FLAG_CARRY    : 0)
         | (sum == 0   ? FLAG_ZERO     : 0)
         | (sum & 0x80 ? FLAG_NEGATIVE : 0);
}

// U111
uint8_t mux_111(uint8_t regs[8], uint8_t select)
{
    assert(select < 5);
    return mux_8_to_1(regs, select);
}

// U112
uint8_t mux_112(uint8_t regs[4], uint8_t select)
{
    return mux_4_to_1(regs, select);
}

// U113
uint8_t mux_113(uint8_t regs[4], uint8_t select)
{
    return mux_4_to_1(regs, select);
}

// U117
void mux_U117(uint8_t select)
{
    
}

// U118
void mux_U118A(uint8_t select)
{
    
}

// U118
void mux_U118B(uint8_t select)
{
    
}

uint8_t alu(uint8_t select_a, uint8_t select_b, uint8_t select_out, uint8_t carry_in, uint8_t *flags)
{
    uint8_t regs[4] = {r0, r1, r2, r3};
    uint8_t reg_a = mux_112(regs, select_a);
    uint8_t reg_b = mux_113(regs, select_b);
    
    uint8_t overflow, carry_out;
    uint8_t alu_out[8] = { alu_add_sub(reg_a, reg_b, carry_in, &overflow, &carry_out)
                         , alu_and(reg_a, reg_b)
                         , alu_or(reg_a, reg_b)
                         , alu_xor(reg_a, reg_b)
                         , alu_not(reg_a)
                         , 0
                         , 0
                         , 0 };
    *flags = flags_110(alu_out[0], overflow, carry_out);
    
    return mux_111(alu_out, select_out);
}
