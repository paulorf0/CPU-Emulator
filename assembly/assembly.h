
#pragma once
#include <cstdint>
#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "../handlers/handlers.h"
#include "../hardware/hardware.h"
// Defining Instructions //
// The OPCODE have 5 bits.
enum OPCODE : uint8_t {
  HLT = 0b00000, // HALT
  NOP = 0b00001, // NO OPERATION

  ADD = 0b00010,  // ADD REGISTER
  SUB = 0b00011,  // SUBTRACT REGISTER
  MUL = 0b00100,  // MULTIPLY REGISTER
  DIV = 0b00101,  // DIVIDE REGISTER
  CMP = 0b00110,  // COMPARE REGISTER
  MOVR = 0b00111, // MOVE REGISTER

  AND = 0b01000, // LOGICAL-AND ON REGISTER
  OR = 0b01001,  // LOGICAL-OR ON REGISTER
  XOR = 0b01010, // LOGICAL-XOR ON REGISTER
  NOT = 0b01011, // LOGICAL-NOT ON REGISTER

  JE = 0b01100,  // JUMP IF EQUAL TO
  JNE = 0b01101, // JUMP IF NOT EQUAL TO
  JL = 0b01110,  // JUMP IF LOWER THAN
  JLE = 0b01111, // JUMP IF LOWER OR EQUAL
  JG = 0b10000,  // JUMP IF GREATER THAN
  JGE = 0b10001, // JUMP IF GREATER OR EQUAL
  JMP = 0b10010, // JUMP

  LD = 0b10011, // LOAD
  ST = 0b10100, // STORE

  LDR = 0b10101, // LOAD VIA REGISTER
  STR = 0b10110, // STORE VIA REGISTER

  MOVI = 0b10111, // MOVE IMMEDIATE
  ADDI = 0b11000, // ADD IMMEDIATE
  SUBI = 0b11001, // SUBTRACT IMMEDIATE
  MULI = 0b11010, // MULTIPLY IMMEDIATE
  DIVI = 0b11011, // DIVIDE IMMEDIATE

  LSH = 0b11100, // LEFT SHIFT
  RSH = 0b11101, // RIGHT SHIFT

};

// Instruction Size by bytes.
static constexpr uint8_t instruction_size[] = {
    /* HLT  */ 1,
    /* NOP  */ 1,

    /* ADD  */ 2,
    /* SUB  */ 2,
    /* MUL  */ 2,
    /* DIV  */ 2,
    /* CMP  */ 2,
    /* MOVR */ 2,

    /* AND  */ 2,
    /* OR   */ 2,
    /* XOR  */ 2,
    /* NOT  */ 1,

    /* JE   */ 3,
    /* JNE  */ 3,
    /* JL   */ 3,
    /* JLE  */ 3,
    /* JG   */ 3,
    /* JGE  */ 3,
    /* JMP  */ 3,

    /* LD   */ 3,
    /* ST   */ 3,

    /* LDR  */ 2,
    /* STR  */ 2,

    /* MOVI */ 3,
    /* ADDI */ 3,
    /* SUBI */ 3,
    /* MULI */ 3,
    /* DIVI */ 3,

    /* LSH  */ 3,
    /* RSH  */ 3};
inline uint8_t get_instruction_size(OPCODE op) {
  return instruction_size[static_cast<int>(op)];
}
// Defining Instructions //

// Defining Regs //
enum GR : uint8_t { R0 = 0b00, R1 = 0b01, R2 = 0b10, R3 = 0b11 };
// Defining Regs //

// Assembly Instructions //
typedef void (*InstructionHandler)(CPU *);

// MBR have 24 bits code.
static inline OPCODE OPCODE5(uint32_t word) {
  return (OPCODE)((word >> 27) & 0x1F);
}

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
