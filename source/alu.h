#include <stdint.h>

#define BIT(x, i) (((x) & (1 << (i))) >> (i))

#define FLAG_OVERFLOW (1<<0)
#define FLAG_CARRY    (1<<1)
#define FLAG_ZERO     (1<<2)
#define FLAG_NEGATIVE (1<<3)

extern uint16_t sp;
extern uint8_t r0;
extern uint8_t r1;
extern uint8_t r2;
extern uint8_t r3;

static uint8_t mux_4_to_1(uint8_t input[4], uint8_t select)
{
    if (select >= 4)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    return input[select];
}

static uint8_t mux_8_to_1(uint8_t input[8], uint8_t select)
{
    if (select >= 8)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    return input[select];
}

// U14
void stack_pointer_impl(uint16_t updated_value);
// U100
uint8_t alu_add_sub(uint8_t reg_a, uint8_t reg_b, uint8_t carry_in, uint8_t *overflow, uint8_t *carry_out);
// U101
uint8_t alu_and(uint8_t a, uint8_t b);
// U102
uint8_t alu_or(uint8_t a, uint8_t b);
// U103
uint8_t alu_xor(uint8_t a, uint8_t b);
// U104
uint8_t alu_not(uint8_t b);
// U107
// uint8_t stack_addsub(uint8_t *sp, char plusminus, char align);
// U111
uint8_t mux_111(uint8_t regs[8], uint8_t select);
// U112
uint8_t mux_112(uint8_t regs[4], uint8_t select);
// U113
uint8_t mux_113(uint8_t regs[4], uint8_t select);
// U117
void mux_U117(uint8_t select);
// U118
void mux_U118A(uint8_t select);
// U118
void mux_U118B(uint8_t select);

uint8_t alu(uint8_t select_a, uint8_t select_b, uint8_t select_out, uint8_t carry_in, uint8_t *flags);
