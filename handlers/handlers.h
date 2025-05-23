#pragma once
#ifndef HANDLERS_H
#define HANDLERS_H

#include "../hardware/hardware.h"

extern void handle_HLT(CPU *); // HALT
extern void handle_NOP(CPU *); // NO OPERATION

extern void handle_ADD(CPU *);  // ADD REGISTER
extern void handle_SUB(CPU *);  // SUBTRACT REGISTER
extern void handle_MUL(CPU *);  // MULTIPLY REGISTER
extern void handle_DIV(CPU *);  // DIVIDE REGISTER
extern void handle_CMP(CPU *);  // COMPARE REGISTER
extern void handle_MOVR(CPU *); // MOVE REGISTER

extern void handle_AND(CPU *); // LOGICAL-AND ON REGISTER
extern void handle_OR(CPU *);  // LOGICAL-OR ON REGISTER
extern void handle_XOR(CPU *); // LOGICAL-XOR ON REGISTER
extern void handle_NOT(CPU *); // LOGICAL-NOT ON REGISTER

extern void handle_JE(CPU *);  // JUMP IF EQUAL TO
extern void handle_JNE(CPU *); // JUMP IF NOT EQUAL TO
extern void handle_JL(CPU *);  // JUMP IF LOWER THAN
extern void handle_JLE(CPU *); // JUMP IF LOWER OR EQUAL
extern void handle_JG(CPU *);  // JUMP IF GREATER THAN
extern void handle_JGE(CPU *); // JUMP IF GREATER OR EQUAL
extern void handle_JMP(CPU *); // JUMP

extern void handle_LD(CPU *); // LOAD
extern void handle_ST(CPU *); // STORE

extern void handle_LDR(CPU *); // LOAD VIA REGISTER
extern void handle_STR(CPU *); // STORE VIA REGISTER

extern void handle_MOVI(CPU *); // MOVE IMMEDIATE
extern void handle_ADDI(CPU *); // ADD IMMEDIATE
extern void handle_SUBI(CPU *); // SUBTRACT IMMEDIATE
extern void handle_MULI(CPU *); // MULTIPLY IMMEDIATE
extern void handle_DIVI(CPU *); // DIVIDE IMMEDIATE

extern void handle_LSH(CPU *); // LEFT SHIFT
extern void handle_RSH(CPU *); // RIGHT SHIFT

#endif
