#pragma once
#include "timer.h"
#ifndef FETCH_H
#define FETCH_H

#include "../assembly/assembly.h"
#include "../hardware/hardware.h"


static inline void fetch(CPU *cpu){
    cpu->reg.MAR = cpu->reg.PC;
    cpu->reg.MBR = 0x0;
    for(int i = 0; i < 3; i ++){
        delay(cpu->memory.freq,cpu->clock);
        cpu->reg.MBR = ((cpu->reg.MBR<<8 ) | cpu->memory.memory[cpu->reg.MAR++]);
    }
    // The last eight bits are not used.
    cpu->reg.MBR = cpu->reg.MBR & 0xFFFFFF00;
    cpu->reg.PC += 3;
    return;
}

static inline void decode(CPU *cpu){
    // OpCode instruction
    cpu->reg.IR = OPCODE5(cpu->reg.MBR);


    INSTRUCTION instruction = instr_table[cpu->reg.IR];
    void *jump_table[] = {
        &&L_hlt, // 0x00 HLT
        &&L_nop, // 0x01 NOP

        &&L_add,  // 0x02 ADD
        &&L_sub,  // 0x03 SUB
        &&L_mul,  // 0x04 MUL
        &&L_div,  // 0x05 DIV
        &&L_cmp,  // 0x06 CMP
        &&L_movr, // 0x07 MOVR

        &&L_and, // 0x08 AND
        &&L_or,  // 0x09 OR
        &&L_xor, // 0x0A XOR
        &&L_not, // 0x0B NOT

        &&L_je,  // 0x0C JE
        &&L_jne, // 0x0D JNE
        &&L_jl,  // 0x0E JL
        &&L_jle, // 0x0F JLE
        &&L_jg,  // 0x10 JG
        &&L_jge, // 0x11 JGE
        &&L_jmp, // 0x12 JMP

        &&L_ld, // 0x13 LD
        &&L_st, // 0x14 ST

        &&L_ldr, // 0x15 LDR
        &&L_str, // 0x16 STR

        &&L_movi, // 0x17 MOVI
        &&L_addi, // 0x18 ADDI
        &&L_subi, // 0x19 SUBI
        &&L_muli, // 0x1A MULI
        &&L_divi, // 0x1B DIVI

        &&L_lsh, // 0x1C LSH
        &&L_rsh  // 0x1D RSH
    };


    goto jump_table[cpu->reg.IR];

    L_hlt:
    L_nop:
        goto L_continue;
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
        goto L_continue;
    L_not:
      // Implement NOT operation here
      goto L_continue;

    L_je:
      // Implement JE operation here
      goto L_continue;

    L_jne:
      // Implement JNE operation here
      goto L_continue;

    L_jl:
      // Implement JL operation here
      goto L_continue;

    L_jle:
      // Implement JLE operation here
      goto L_continue;

    L_jg:
      // Implement JG operation here
      goto L_continue;

    L_jge:
      // Implement JGE operation here
      goto L_continue;

    L_jmp:
      // Implement JMP operation here
      goto L_continue;

    L_ld:
      // Implement LD operation here
      goto L_continue;

    L_st:
      // Implement ST operation here
      goto L_continue;


    L_movi:
      // Implement MOVI operation here
      goto L_continue;

    L_addi:
      // Implement ADDI operation here
      goto L_continue;

    L_subi:
      // Implement SUBI operation here
      goto L_continue;

    L_muli:
      // Implement MULI operation here
      goto L_continue;

    L_divi:
      // Implement DIVI operation here
      goto L_continue;

    L_lsh:
      // Implement LSH operation here
      goto L_continue;

    L_rsh:
      // Implement RSH operation here


    L_continue:
        // I think that the MAR is not used here.
        cpu->reg.MAR = cpu->reg.PC;
}






#endif
