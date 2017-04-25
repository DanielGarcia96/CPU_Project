#ifndef MUX_H
#define MUX_H

#include <stdint.h>
#include <stdlib.h>

// 16-bit Register Value Type
typedef uint16_t reg16_t;
// 8-bit Register Value Type
typedef uint8_t reg8_t;
// Single Bit Type
typedef uint8_t bit_t;
// (Multiple Bit) Control Line Type
typedef uint8_t ctl_t;

static reg8_t mux_4_to_1(reg8_t input[4], reg8_t select)
{
    if (select >= 4)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    return input[select];
}

static reg8_t mux_8_to_1(reg8_t input[8], reg8_t select)
{
    if (select >= 8)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    return input[select];
}

// The variable "registers" is an array of function pointers to the register functions
// Simply call this function as so: demux_2_to_4({&reg0, &reg1, &reg2, &reg3},
//                                               input_a, select_a, enable_a)
//                                               input_b, select_b, enable_b);
static void demux_2_to_4(reg8_t (*registers[4])(reg8_t, ctl_t),
                            reg8_t input_a, reg8_t select_a, ctl_t enable_a, 
                            reg8_t input_b, reg8_t select_b, ctl_t enable_b)
{
    if (select_a >= 4 | select_b >= 4)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    reg8_t (*reg_function)(reg8_t, ctl_t);

    if(enable_a)
    {
        reg_function = registers[select_a];
        reg_function(input_a, 0);
    }
    if(enable_b)
    {
        reg_function = registers[select_b];
        reg_function(input_b, 0);
    }
}

#endif
