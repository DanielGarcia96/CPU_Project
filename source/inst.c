#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "inst.h"

/*** UNTIL MEMORY IS ADDED, MEMORY INSTRUCTIONS ARE COMMENTED OUT ***/

void add10 (reg8_t a, reg8_t b) {
    
}
void add11 (reg8_t a, uint_8 b) {}
//void add12 (reg8_t a, reg16_t b);
//void add13 (reg16_t a, reg8_t b);

void sub20 (reg8_t a, reg8_t b) {}
void sub21 (reg8_t a, uint_8 b) {}
//void sub22 (reg8_t a, reg16_t b);
//void sub23 (reg16_t a, reg8_t b);

void cmp30 (reg8_t a, reg8_t b) {}
void cmp31 (reg8_t a, uint_8 b) {}
//void cmp32 (reg8_t a, reg16_t b);
//void cmp33 (reg16_t a, reg8_t b);

void not40 (reg8_t a) {}

void and50 (reg8_t a, reg8_t b) {}
void and51 (reg8_t a, uint_8 b) {}
//void and52 (reg8_t a, reg16_t b);
//void and53 (reg16_t a, reg8_t b);

void or60 (reg8_t a, reg8_t b) {}
void or61 (reg8_t a, uint_8 b) {}
//void or62 (reg8_t a, reg16_t b);
//void or63 (reg16_t a, reg8_t b);

void xor70 (reg8_t a, reg8_t b) {}
void xor71 (reg8_t a, uint_8 b) {}
//void xor72 (reg8_t a, reg16_t b);
//void xor73 (reg16_t a, reg8_t b);

void mov80 (reg8_t a, reg8_t b) {}
void mov81 (reg8_t a, uint_8 b) {}
//void mov82 (reg8_t a, reg16_t b);
//void mov83 (reg16_t a, reg8_t b);

void jmpB8 (reg16_t a) {}
//void jmpB9 (reg16_t a);

void jloD6 (bit_t c) {}
void jhsD7 (bit_t c) {}
void jeqD8 (bit_t z) {}
void jneD9 (bit_t z) {}
void jmiDA (bit_t s) {}
void jplDB (bit_t s) {}

void nopE0 () {}
