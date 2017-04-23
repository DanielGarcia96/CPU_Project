#if defined(__solaris__)
#include <inttypes.h>
#else
#include <stdint.h>
#endif

typedef uint8_t reg_t;
extern reg_t sp;
extern reg_t r0;
extern reg_t r1;
extern reg_t r2;
extern reg_t r3;

// U14
void stack_pointer_impl(reg_t updated_value);
// U100
reg_t addsub(reg_t a, reg_t b, char verbose);
// U101
reg_t and_impl(reg_t a, reg_t b, char verbose);
// U102
reg_t or_impl(reg_t a, reg_t b, char verbose);
// U103
reg_t xor_impl(reg_t a, reg_t b, char verbose);
// U104
reg_t not_impl(reg_t b, char verbose);
// U107
reg_t stack_addsub(reg_t *sp, char plusminus, char align);
// U112
void mux_112(char select_a, char select_b, char verbose);
// U113
reg_t * mux_113(char select);
// U117
void mux_U117(char select);
// U118
void mux_U118A(reg_t select);
// U118
void mux_U118B(reg_t select);
