/*
    3GHz CPU-16bits.
    Memory delay of 150 clocks.
*/

#pragma once
#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdint.h>
#include <stdlib.h>

#define MAX_ADDRESS 65536   // 2^16 = 65536
#define CPU_CLOCK 3         // 3 GHz = 3 * 2^30 ciclos / s
#define MEM_DELAY_CLOCK 150 // 150 clocks de delay

// Hardware //
typedef struct {
  uint8_t memory[MAX_ADDRESS]; // 65536 bytes, 1 word = 1 byte
  uint16_t freq;
} Memory;

typedef struct {
  uint32_t MBR;    // - Memory Buffer Register -
  uint16_t MAR;    // – Memory Address Register –
  uint16_t IMM;    // – Immediate –
  uint16_t PC;     // – Program Counter –
  uint8_t IR;      // - Instruction Register -
  uint8_t RO0;     // – Register Operand 0 –
  uint8_t RO1;     // – Register Operand 1 –
  uint8_t E;       // - Equal To -
  uint8_t L;       // - Lower Than -
  uint8_t G;       // - Greater Than -
  uint16_t GPR[4]; // - General Purpose Register -
} Reg;

typedef struct {
  Reg reg;
  Memory memory;
  uint32_t clock;
  uint8_t terminate_flag;
} CPU;
// Hardware //

// Initialization //
static inline CPU* init_cpu(){
    CPU *cpu = (CPU*)malloc(sizeof(CPU));
    if (!cpu) {
        return NULL;
    }
    cpu->reg.MBR = 0;
    cpu->reg.MAR = 0;
    cpu->reg.IMM = 0;
    cpu->reg.PC = 0;
    cpu->reg.IR = 0;
    cpu->reg.RO0 = 0;
    cpu->reg.RO1 = 0;
    cpu->reg.E = 0;
    cpu->reg.L = 0;
    cpu->reg.G = 0;
    cpu->terminate_flag = 0;
    for (int i = 0; i < 4; i++) {
        cpu->reg.GPR[i] = 0;
    }
    cpu->memory.freq = CPU_CLOCK;
    cpu->clock = 0;
    return cpu;
}
// Initialization //

#endif
