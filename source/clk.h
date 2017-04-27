#ifndef CLK_H
#define CLK_H

#include "alu.h"

// Written by Daniel Garcia
static void clk(ctl_t selects[], bit_t carry_in, ctl_t *flags,)
{
    reg0(0, 1);
    reg1(0, 1);
    reg2(0, 1);
    reg3(0, 1);
    stack_pointer_impl(0, 1);
    alu_output = alu(selects[0], selects[1], selects[2], carry_in, flags);
    print_regs();
}

#endif
