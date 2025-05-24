#pragma once
#ifndef FETCH_H
#define FETCH_H

#include "../assembly/assembly.h"
#include "../assembly/instruction_code.h"
#include "../hardware/hardware.h"

static inline void fetch(CPU *cpu) {
  cpu->reg.MAR = cpu->reg.PC;
  cpu->reg.MBR = 0x0;

  uint8_t opcode = (cpu->memory.memory[cpu->reg.MAR] >> 3) & 0x1F;
  uint8_t size = get_instruction_size((OPCODE)opcode);

  for (uint8_t i = 0; i < size; i++) {
    cpu->reg.MBR = ((cpu->reg.MBR << 8) | cpu->memory.memory[cpu->reg.MAR + i]);
  }

  cpu->reg.MBR = cpu->reg.MBR << (4 - size)*8 ;

  // The last eight bits are not used.
  cpu->reg.MBR = cpu->reg.MBR & 0xFFFFFF00;
  cpu->reg.PC += size;
  return;
}

static inline void decode(CPU *cpu) {
  // OpCode instruction
  cpu->reg.IR = OPCODE5(cpu->reg.MBR);
  switch (cpu->reg.IR) {
  case HLT:
  case NOP:
    break;
  case ADD:
  case LDR:
  case STR:
  case SUB:
  case MUL:
  case DIV:
  case CMP:
  case MOVR:
  case AND:
  case OR:
  case XOR:
    // 0 - 4 (OPCODE), 4 - 6 (Reg0), 6 - 8 (Reg1) (The bits were numbered left
    // to right) The buffer has 32 bits, but just 24 bits is used.
    cpu->reg.RO0 = (cpu->reg.MBR >> 25) & 0x03;
    cpu->reg.RO1 = (cpu->reg.MBR >> 23) & 0x03;
    break;
  case NOT:
    cpu->reg.RO0 = (cpu->reg.MBR >> 24) & 0x03;
    break;
  case JE:
  case JNE:
  case JL:
  case JLE:
  case JG:
  case JGE:
  case JMP:
    cpu->reg.MAR = (cpu->reg.MBR >> 8) & 0xFFFF; // Maybe this is wrong
    break;
  case LD:
  case ST:
    cpu->reg.MAR = (cpu->reg.MBR >> 8) & 0xFFFF;
    cpu->reg.RO0 = (cpu->reg.MBR >> 25) & 0x03;
    break;
  case MOVI:
  case ADDI:
  case SUBI:
  case MULI:
  case DIVI:
  case LSH:
  case RSH:
    cpu->reg.IMM = (cpu->reg.MBR >> 8) & 0xFFFF;
    cpu->reg.RO0 = (cpu->reg.MBR >> 25) & 0x03;
    break;
  default: // The "default" should never be reached
    break;
  }
}

static inline void execute(CPU *cpu) {
  InstructionHandler handler = instr_table[cpu->reg.IR];
  handler(cpu);
}

#endif
