#pragma once
#ifndef INSTRUCTION_CODE_H
#define INSTRUCTION_CODE_H

#include <stdint.h>
// Instruction Size by bytes.
static uint8_t instruction_size[] = {
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

// Defining Instructions //
// The OPCODE have 5 bits.
typedef enum {
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

} OPCODE;


static inline uint8_t get_instruction_size(OPCODE op) {
  return instruction_size[(int)op];
}
// MBR have 24 bits code.
static inline OPCODE OPCODE5(uint32_t word) {
  return (OPCODE)((word >> 27) & 0x1F);
}

#endif
