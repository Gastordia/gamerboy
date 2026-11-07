#pragma once

#include <common.h>
#include <instruction.h>

typdef struct {
    u8 a;
    u8 f;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 h;
    u8 l;
    u16 sp;
    u16 pc;
} cpu_registers;

typdef struct{
    cpu_registers regs;
    u16 current_fetch;
    u16 mem_dest;
    u8 current_opcode;
    instruction current_instruction;
    bool halted;
    bool stepping;
}cpu_context;

void cpu_init();
bool cpu_step();