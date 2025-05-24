#pragma once
#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "../handlers/handlers.h"
#include "../hardware/hardware.h"
#include <stdint.h>

// Defining Regs //
typedef enum { R0 = 0b00, R1 = 0b01, R2 = 0b10, R3 = 0b11 } GR;
// Defining Regs //

// Assembly Instructions //
typedef void (*InstructionHandler)(CPU *);
static const InstructionHandler instr_table[] = {
    handle_HLT, // HALT
    handle_NOP, // NO OPERATION

    handle_ADD,  // ADD REGISTER
    handle_SUB,  // SUBTRACT REGISTER
    handle_MUL,  // MULTIPLY REGISTER
    handle_DIV,  // DIVIDE REGISTER
    handle_CMP,  // COMPARE REGISTER
    handle_MOVR, // MOVE REGISTER

    handle_AND, // LOGICAL-AND ON REGISTER
    handle_OR,  // LOGICAL-OR ON REGISTER
    handle_XOR, // LOGICAL-XOR ON REGISTER
    handle_NOT, // LOGICAL-NOT ON REGISTER

    handle_JE,  // JUMP IF EQUAL TO
    handle_JNE, // JUMP IF NOT EQUAL TO
    handle_JL,  // JUMP IF LOWER THAN
    handle_JLE, // JUMP IF LOWER OR EQUAL
    handle_JG,  // JUMP IF GREATER THAN
    handle_JGE, // JUMP IF GREATER OR EQUAL
    handle_JMP, // JUMP

    handle_LD, // LOAD
    handle_ST, // STORE

    handle_LDR, // LOAD VIA REGISTER
    handle_STR, // STORE VIA REGISTER

    handle_MOVI, // MOVE IMMEDIATE
    handle_ADDI, // ADD IMMEDIATE
    handle_SUBI, // SUBTRACT IMMEDIATE
    handle_MULI, // MULTIPLY IMMEDIATE
    handle_DIVI, // DIVIDE IMMEDIATE

    handle_LSH, // LEFT SHIFT
    handle_RSH, // RIGHT SHIFT
};
// Assembly Instructions //
#endif
