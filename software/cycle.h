#pragma once
#ifndef FETCH_H
#define FETCH_H

#include "../assembly/assembly.h"
#include "../hardware/hardware.h"


static inline void fetch(CPU *cpu){
    cpu->reg.MAR = cpu->reg.PC;
    cpu->reg.MBR = 0x0;

    uint8_t opcode = (cpu->memory.memory[cpu->reg.MAR] >> 3) & 0x1F;
    uint8_t size = get_instruction_size((OPCODE)opcode);

    for(uint8_t i = 0; i < size; i ++)
        cpu->reg.MBR = ((cpu->reg.MBR<<8 ) | cpu->memory.memory[cpu->reg.MAR++]);

    // The last eight bits are not used.
    cpu->reg.MBR = cpu->reg.MBR & 0xFFFFFF00;
    cpu->reg.PC += size;
    return;
}

static inline void decode(CPU *cpu){
    // OpCode instruction
    cpu->reg.IR = OPCODE5(cpu->reg.MBR);
    switch(cpu->reg.IR){
    L_hlt:
    L_nop:
        break;
    L_add:
    L_ldr:
    L_str:
    L_sub:
    L_mul:
    L_div:
    L_cmp:
    L_movr:
    L_and:
    L_or:
    L_xor:
        // 0 - 4 (OPCODE), 4 - 6 (Reg0), 6 - 8 (Reg1) (The bits were numbered left to right)
        // The buffer has 32 bits, but just 24 bits is used.
        cpu->reg.RO0 = (cpu->reg.MBR >> 25) & 0x03;
        cpu->reg.RO1 = (cpu->reg.MBR >> 23) & 0x03;
        break;
    L_not:
        cpu->reg.RO0 = (cpu->reg.MBR >> 26 ) & 0x03;
        break;
    L_je:
    L_jne:
    L_jl:
    L_jle:
    L_jg:
    L_jge:
    L_jmp:
        cpu->reg.PC = (cpu->reg.MBR >> 9) & 0xFFFF; // Maybe this is wrong
        break;
    L_ld:
    L_st:
        cpu->reg.MAR = (cpu->reg.MBR >> 9) & 0xFFFF;
        cpu->reg.RO0 = (cpu->reg.MBR >> 26) & 0x03;
        break;
    L_movi:
    L_addi:
    L_subi:
    L_muli:
    L_divi:
    L_lsh:
    L_rsh:
        cpu->reg.IMM = (cpu->reg.MBR >> 9) & 0xFFFF;
        cpu->reg.RO0 = (cpu->reg.MBR >> 26) & 0x03;
        break;
    default: // The "default" should never be reached
        break;
    }
}






#endif
