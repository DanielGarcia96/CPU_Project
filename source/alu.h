extern short sp;
extern short r0;
extern short r1;
extern short r2;
extern short r3;

// U14
void stack_pointer_impl(short updated_value);
// U100
short addsub(short a, short b, char verbose);
// U101
short and_impl(short a, short b, char verbose);
// U102
short or_impl(short a, short b, char verbose);
// U103
short xor_impl(short a, short b, char verbose);
// U104
short not_impl(short b, char verbose);
// U107
short stack_addsub(short *sp, char plusminus, char align);
// U112
void mux_112(char select_a, char select_b, char verbose);
// U113
short * mux_113(char select);
// U117
void mux_U117(char select);
// U118
void mux_U118A(short select);
// U118
void mux_U118B(short select);
