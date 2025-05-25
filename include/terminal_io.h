#pragma once
#ifndef TERMINAL_H
#define TERMINAL_H

#include "hardware.h"
#include <stdio.h>

static inline void print_register(CPU *cpu) {
  Reg *r = &cpu->reg;

  printf("MBR : 0x%06X\tMAR : 0x%04X\tIMM : 0x%04X\n", r->MBR >> 8, r->MAR,
         r->IMM);
  printf("PC  : 0x%04X\tIR  : 0x%02X\tRO0 : 0x%02X\n", r->PC, r->IR, r->RO0);
  printf("RO1 : 0x%02X\tE   : 0x%02X\tL   : 0x%02X\n", r->RO1, r->E, r->L);
  printf("G   : 0x%02X\tGPR0: 0x%04X\tGPR1: 0x%04X\n", r->G, r->GPR[0],
         r->GPR[1]);
  printf("GPR2: 0x%04X\tGPR3: 0x%04X\n", r->GPR[2], r->GPR[3]);
}

static inline void print_memory(CPU *cpu) {
  uint8_t *memory = cpu->memory.memory;
  uint32_t addr = 0;

  printf("\n------------- Memory -------------\n");
  do {
    printf("%04X: %02X\n", addr, memory[addr]);
  } while (addr++ < cpu->memory.ptr);
  printf("------------- Memory -------------\n");
}

static inline void decode_instruction(CPU *cpu){
    uint8_t opcode = cpu->reg.IR;
      uint8_t r0 = cpu->reg.RO0;
      uint8_t r1 = cpu->reg.RO1;
      uint16_t imm = cpu->reg.IMM;
      uint16_t addr = cpu->reg.MAR;

      switch (opcode) {
          case 0: // HLT
              printf("HLT\n");
              break;

          case 1: // NOP
              printf("NOP\n");
              break;

          case 2: // ADD rX, rY
              printf("ADD R%u, R%u\n", r0, r1);
              break;
          case 3: // SUB rX, rY
              printf("SUB R%u, R%u\n", r0, r1);
              break;
          case 4: // MUL rX, rY
              printf("MUL R%u, R%u\n", r0, r1);
              break;
          case 5: // DIV rX, rY
              printf("DIV R%u, R%u\n", r0, r1);
              break;
          case 6: // CMP rX, rY
              printf("CMP R%u, R%u\n", r0, r1);
              break;
          case 7: // MOVR rX, rY
              printf("MOVR R%u, R%u\n", r0, r1);
              break;

          case 8:  // AND rX, rY
              printf("AND R%u, R%u\n", r0, r1);
              break;
          case 9:  // OR rX, rY
              printf("OR R%u, R%u\n", r0, r1);
              break;
          case 10: // XOR rX, rY
              printf("XOR R%u, R%u\n", r0, r1);
              break;
          case 11: // NOT rX
              printf("NOT R%u\n", r0);
              break;

          case 12: // JE Z
              printf("JE  0x%04X\n", addr);
              break;
          case 13: // JNE Z
              printf("JNE 0x%04X\n", addr);
              break;
          case 14: // JL Z
              printf("JL  0x%04X\n", addr);
              break;
          case 15: // JLE Z
              printf("JLE 0x%04X\n", addr);
              break;
          case 16: // JG Z
              printf("JG  0x%04X\n", addr);
              break;
          case 17: // JGE Z
              printf("JGE 0x%04X\n", addr);
              break;
          case 18: // JMP Z
              printf("JMP 0x%04X\n", addr);
              break;

          case 19: // LD rX, Z
              printf("LD  R%u, 0x%04X\n", r0, addr);
              break;
          case 20: // ST rX, Z
              printf("ST  R%u, 0x%04X\n", r0, addr);
              break;

          case 21: // LDR rX, rY
              printf("LDR R%u, R%u\n", r0, r1);
              break;
          case 22: // STR rX, rY
              printf("STR R%u, R%u\n", r0, r1);
              break;

          case 23: // MOVI rX, IMM
              printf("MOVI R%u, %u\n", r0, imm);
              break;
          case 24: // ADDI rX, IMM
              printf("ADDI R%u, %u\n", r0, imm);
              break;
          case 25: // SUBI rX, IMM
              printf("SUBI R%u, %u\n", r0, imm);
              break;
          case 26: // MULI rX, IMM
              printf("MULI R%u, %u\n", r0, imm);
              break;
          case 27: // DIVI rX, IMM
              printf("DIVI R%u, %u\n", r0, imm);
              break;

          case 28: // LSH rX, IMM
              printf("LSH  R%u, %u\n", r0, imm);
              break;
          case 29: // RSH rX, IMM
              printf("RSH  R%u, %u\n", r0, imm);
              break;

          default:
              // Caso IR tenha um valor inválido (fora de 0..29), avisamos
              printf("UNKNOWN OPCODE (IR=0x%02X)\n", opcode);
              break;
      }
}

static inline void terminal_fetch(CPU *cpu) {
  // Terminal for fetch. Print informations.
  decode_instruction(cpu);
  //
  printf("\n------------- Fetch Routine -------------\n");
  print_register(cpu);
  printf("------------- Fetch Routine -------------\n");
}

static inline void terminal_decode(CPU *cpu) {
  // Terminal for fetch. Print informations.
  printf("\n------------- Decode Routine -------------\n");
  print_register(cpu);
  printf("------------- Decode Routine -------------\n");
}

static inline void terminal_execute(CPU *cpu) {
  // Terminal for fetch. Print informations.
  printf("\n------------- Execute Routine -------------\n");
  print_register(cpu);
  printf("------------- Execute Routine -------------\n");
}

#endif
