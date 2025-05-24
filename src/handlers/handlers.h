#pragma once
#ifndef HANDLERS_H
#define HANDLERS_H

#include "../hardware/hardware.h"
#include "../assembly/instruction_code.h"

void handle_HLT(CPU *cpu);
void handle_NOP(CPU *cpu);
void handle_ADD(CPU *cpu);
void handle_SUB(CPU *cpu);
void handle_MUL(CPU *cpu);
void handle_DIV(CPU *cpu);
void handle_CMP(CPU *cpu);
void handle_MOVR(CPU *cpu);
void handle_AND(CPU *cpu);
void handle_OR(CPU *cpu);
void handle_XOR(CPU *cpu);
void handle_NOT(CPU *cpu);
void handle_JE(CPU *cpu);
void handle_JNE(CPU *cpu);
void handle_JL(CPU *cpu);
void handle_JLE(CPU *cpu);
void handle_JG(CPU *cpu);
void handle_JGE(CPU *cpu);
void handle_JMP(CPU *cpu);
void handle_LD(CPU *cpu);
void handle_ST(CPU *cpu);
void handle_LDR(CPU *cpu);
void handle_STR(CPU *cpu);
void handle_MOVI(CPU *cpu);
void handle_ADDI(CPU *cpu);
void handle_SUBI(CPU *cpu);
void handle_MULI(CPU *cpu);
void handle_DIVI(CPU *cpu);
void handle_LSH(CPU *cpu);
void handle_RSH(CPU *cpu);
#endif
