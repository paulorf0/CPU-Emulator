#include "handlers.h"

void handle_HLT(CPU *cpu) { return; }  // HALT
void handle_NOP(CPU *cpu) { return; }  // NO OPERATION
void handle_ADD(CPU *cpu) { return; }  // ADD REGISTER
void handle_SUB(CPU *cpu) { return; }  // SUBTRACT REGISTER
void handle_MUL(CPU *cpu) { return; }  // MULTIPLY REGISTER
void handle_DIV(CPU *cpu) { return; }  // DIVIDE REGISTER
void handle_CMP(CPU *cpu) { return; }  // COMPARE REGISTER
void handle_MOVR(CPU *cpu) { return; } // MOVE REGISTER
void handle_AND(CPU *cpu) { return; }  // LOGICAL-AND ON REGISTER
void handle_OR(CPU *cpu) { return; }   // LOGICAL-OR ON REGISTER
void handle_XOR(CPU *cpu) { return; }  // LOGICAL-XOR ON REGISTER
void handle_NOT(CPU *cpu) { return; }  // LOGICAL-NOT ON REGISTER
void handle_JE(CPU *cpu) { return; }   // JUMP IF EQUAL TO
void handle_JNE(CPU *cpu) { return; }  // JUMP IF NOT EQUAL TO
void handle_JL(CPU *cpu) { return; }   // JUMP IF LOWER THAN
void handle_JLE(CPU *cpu) { return; }  // JUMP IF LOWER OR EQUAL
void handle_JG(CPU *cpu) { return; }   // JUMP IF GREATER THAN
void handle_JGE(CPU *cpu) { return; }  // JUMP IF GREATER OR EQUAL
void handle_JMP(CPU *cpu) { return; }  // JUMP
void handle_LD(CPU *cpu) { return; }   // LOAD
void handle_ST(CPU *cpu) { return; }   // STORE
void handle_LDR(CPU *cpu) { return; }  // LOAD VIA REGISTER
void handle_STR(CPU *cpu) { return; }  // STORE VIA REGISTER
void handle_MOVI(CPU *cpu) { return; } // MOVE IMMEDIATE
void handle_ADDI(CPU *cpu) { return; } // ADD IMMEDIATE
void handle_SUBI(CPU *cpu) { return; } // SUBTRACT IMMEDIATE
void handle_MULI(CPU *cpu) { return; } // MULTIPLY IMMEDIATE
void handle_DIVI(CPU *cpu) { return; } // DIVIDE IMMEDIATE
void handle_LSH(CPU *cpu) { return; }  // LEFT SHIFT
void handle_RSH(CPU *cpu) { return; }  // RIGHT SHIFT