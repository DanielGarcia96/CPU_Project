#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "alu.h"

// U10
reg8_t reg0(reg8_t updated_value, ctl_t clk)
{
    static reg8_t waiting_val = 0;
    // On rising edge of clock, update value of register
    if(clk)
    {
        r0 = waiting_val;
    }
    // Otherwise, change the value of what's waiting to enter register
    else
    {
       waiting_val = updated_value;
    }
        
    return r0; }


// U11
reg8_t reg1(reg8_t updated_value, ctl_t clk)
{
    static reg8_t waiting_val = 0;
    if(clk)
    {
        r1 = waiting_val;
    }
    else
    {
       waiting_val = updated_value;
    }
        
    return r1;
}


// U12
reg8_t reg2(reg8_t updated_value, ctl_t clk)
{
    static reg8_t waiting_val = 0;
    if(clk)
    {
        r2 = waiting_val;
    }
    else
    {
       waiting_val = updated_value;
    }
        
    return r2;
}


// U13
reg8_t reg3(reg8_t updated_value, ctl_t clk)
{
    static reg8_t waiting_val = 0;
    if(clk)
    {
        r3 = waiting_val;
    }
    else
    {
       waiting_val = updated_value;
    }
        
    return r3;
}


// U14
reg16_t stack_pointer_impl(reg16_t updated_value, ctl_t clk)
{
    static reg16_t waiting_val = 0;
    if(clk)
    {
        sp = waiting_val;
    }
    else
    {
       waiting_val = updated_value;
    }
        
    return sp;
}

// U100
reg8_t alu_add_sub(reg8_t reg_a, reg8_t reg_b, bit_t carry_in, bit_t *overflow, bit_t *carry_out)
{
    reg8_t sum, s, a, b, c, c_prev;
    c = carry_in;
    sum = 0;
    for (reg8_t i = 0; i < 8; i++)
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
reg8_t alu_and(reg8_t a, reg8_t b)
{
    return a & b;
}

// U102
reg8_t alu_or(reg8_t a, reg8_t b)
{
    return a | b;
}

// U103
reg8_t alu_xor(reg8_t a, reg8_t b)
{
    return a ^ b;
}

// U104
reg8_t alu_not(reg8_t a)
{
    return ~a;
}

// U107
reg16_t stack_add_sub(ctl_t plusminus)
{
    char align = 2;
    if(plusminus)
        return sp + 2;
    return sp - 2;
}

// U110
ctl_t flags_110(bit_t sum, bit_t overflow, bit_t carry_out)
{
    return (overflow   ? FLAG_OVERFLOW : 0)
         | (carry_out  ? FLAG_CARRY    : 0)
         | (sum == 0   ? FLAG_ZERO     : 0)
         | (sum & 0x80 ? FLAG_NEGATIVE : 0);
}

// U111
reg8_t mux_111(reg8_t regs[8], ctl_t select)
{
    assert(select < 5);
    return mux_8_to_1(regs, select);
}

// U112
reg8_t mux_112(reg8_t regs[4], ctl_t select)
{
    return mux_4_to_1(regs, select);
}

// U113
reg8_t mux_113(reg8_t regs[4], ctl_t select)
{
    return mux_4_to_1(regs, select);
}

// U117
void mux_U117(ctl_t select, ctl_t stack_add_sub_select)
{
    reg16_t inputs[] = {(reg16_t) r0, stack_add_sub(2)};
    stack_pointer_impl(mux_2_to_1(inputs, select), 0);
}

// U118A & U118B
void mux_U118AB(ctl_t select_a, ctl_t enable_a, ctl_t select_b, ctl_t enable_b)
{
    reg8_t input_a = 0;
    reg8_t input_b = 0;

    if(enable_a)
    {
        switch(select_a)
        {
            case 3:
                input_a = alu_output;
                break;
            default:
                fprintf(stderr, "'select_a' control signal is unusable.\n");
                exit(1);
        }
    }

    if(enable_b)
    {
        switch(select_b)
        {
            case 3:
                input_b = alu_output;
                break;
            default:
                fprintf(stderr, "'select_b' control signal is unusable.\n");
                exit(1);
        }
    }

    reg8_t (*registers[4])(reg8_t, ctl_t) = {&reg0, &reg1, &reg2, &reg3};
    demux_2_to_4(registers,
                 input_a, select_a, enable_a,
                 input_b, select_b, enable_b);
}


void print_regs()
{
    printf("r0: %u, r1: %u, r2: %u, r3: %u, sp: %u,\n",
           r0, r1, r2, r3, sp);
}

reg8_t alu(ctl_t select_a, ctl_t select_b, ctl_t select_out, bit_t carry_in, ctl_t *flags)
{
    reg8_t regs[4] = {r0, r1, r2, r3};
    reg8_t reg_a = mux_112(regs, select_a);
    reg8_t reg_b = mux_113(regs, select_b);
    
    bit_t overflow, carry_out;
    reg8_t alu_out[8] = { alu_add_sub(reg_a, reg_b, carry_in, &overflow, &carry_out)
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
