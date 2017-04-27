// Written by Lucas Tiedeman

#ifndef CU_H
#define CU_H

#include <stdint.h>
#include "inst.h"

extern reg32_t ri;  // Instruction Register
extern reg16_t ip;  // Instruction Pointer

reg16_t reginstr (reg32_t inst, char clk);

// U105 calculates next instruction based off of current instruction length
reg16_t add_105 (reg32_t inst);
// U106 calculates next instruction based off of relative location
reg16_t add_106 (reg16_6 offset);
// mux115 gets the address of the next instruction
reg16_t mux_115 (reg16_t regs[4], ctl_t select);
// mux_116 carries the memory address
reg16_t mux_116 (reg16_t regs[4], ctl_t select);

//void decoder ();

#endif
