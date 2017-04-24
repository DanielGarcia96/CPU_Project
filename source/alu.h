#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include "mux.h"

#define BIT(x, i) (((x) & (1 << (i))) >> (i))

#define FLAG_OVERFLOW (1<<0)
#define FLAG_CARRY    (1<<1)
#define FLAG_ZERO     (1<<2)
#define FLAG_NEGATIVE (1<<3)

// 16-bit Register Value Type
typedef uint16_t reg16_t;
// 8-bit Register Value Type
typedef uint8_t reg8_t;
// Single Bit Type
typedef uint8_t bit_t;
// (Multiple Bit) Control Line Type
typedef uint8_t ctl_t;

// NOTE: "Register Value Types" can represent intermediate states, not just
// values stored in actual registers.

extern reg16_t sp;
extern reg8_t r0;
extern reg8_t r1;
extern reg8_t r2;
extern reg8_t r3;

// U14
void stack_pointer_impl(reg16_t updated_value);
// U100
reg8_t alu_add_sub(reg8_t reg_a, reg8_t reg_b, bit_t carry_in, bit_t *overflow, bit_t *carry_out);
// U101
reg8_t alu_and(reg8_t a, reg8_t b);
// U102
reg8_t alu_or(reg8_t a, reg8_t b);
// U103
reg8_t alu_xor(reg8_t a, reg8_t b);
// U104
reg8_t alu_not(reg8_t b);
// U107
// uint8_t stack_addsub(uint8_t *sp, char plusminus, char align);
// U111
reg8_t mux_111(reg8_t regs[8], ctl_t select);
// U112
reg8_t mux_112(reg8_t regs[4], ctl_t select);
// U113
reg8_t mux_113(reg8_t regs[4], ctl_t select);
// U117
void mux_U117(ctl_t select);
// U118
void mux_U118A(ctl_t select);
// U118
void mux_U118B(ctl_t select);

reg8_t alu(ctl_t select_a, ctl_t select_b, ctl_t select_out, bit_t carry_in, ctl_t *flags);

#endif
