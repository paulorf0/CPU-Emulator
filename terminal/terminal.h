#pragma once
#ifndef TERMINAL_H
#define TERMINAL_H

#include "../hardware/hardware.h"
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

static inline void terminal_fetch(CPU *cpu) {
  // Terminal for fetch. Print informations.
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
