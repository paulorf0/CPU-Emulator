#include "../hardware/hardware.h"
#include "cycle.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // 1) Inicializa a CPU
  CPU *cpu = init_cpu();
  if (!cpu) {
    fprintf(stderr, "Falha ao alocar a CPU\n");
    return EXIT_FAILURE;
  }

  // 2) Carrega na memória (byte a byte) o seguinte "programa em binário":
  //
  //    0x00–0x02: MOVI R0, 5       (3 bytes)
  //    0x03–0x05: MOVI R1, 3       (3 bytes)
  //    0x06–0x07: ADD  R0, R1      (2 bytes)
  //    0x08     : HLT              (1 byte)
  //
  // Endereços restantes ficam a zero (NOP/garbage).
  //
  // Detalhes de codificação:
  //   MOVI R0, 5 → opcode=0b10111, rX=00 → byte0=0b10111000=0xB8, byte1=0x00,
  //   byte2=0x05 MOVI R1, 3 → opcode=0b10111, rX=01 → byte0=0b10111010=0xBA,
  //   byte1=0x00, byte2=0x03 ADD R0, R1 → opcode=0b00010, rX=00, rY=01 →
  //   byte0=0b00010_00_0 = 0x10, byte1=0b1_0000000 = 0x80 HLT       →
  //   opcode=0b00000 → byte0=0b00000000=0x00
  //
  uint8_t *M = cpu->memory.memory; // ponteiro para os 65536 bytes de memória

  // --- MOVI R0, 5 ---
  M[0] = 0xB8; // 0b10111000
  M[1] = 0x00; // IMM high (5 >> 8)
  M[2] = 0x05; // IMM low  (5 & 0xFF)

  // --- MOVI R1, 3 ---
  M[3] = 0xBA; // 0b10111010 (opcode=10111, rX=01)
  M[4] = 0x00; // IMM high (3 >> 8)
  M[5] = 0x03; // IMM low  (3 & 0xFF)

  // --- ADD R0, R1 ---
  M[6] = 0x10; // 0b00010000 (opcode=00010, rX=00, rY_msb=0)
  M[7] = 0x80; // 0b10000000 (rY_lsb=1 em bit7)

  // --- HLT ---
  M[8] = 0x00; // 0b00000000 (opcode=00000)

  // (Opcionalmente, podemos inicializar o restante da memória com 0x00 ou 0xFF,
  // mas não é
  //  necessário para este exemplo de demonstração.)

  // 3) Exibe os primeiros bytes para conferirmos (em hex):
  printf("Memória carregada nos 10 primeiros bytes:\n");
  for (int i = 0; i < 10; i++) {
    printf("  M[%02d] = 0x%02X\n", i, M[i]);
  }

  // 4) Opcional: inicializa todos os registradores em zero (já feito pelo
  // init_cpu()),
  //    depois mostra como ficariam r0 e r1 (antes de rodar qualquer coisa).
  printf("\nAntes da execução:\n");
  printf("  r0 = %u\n", cpu->reg.GPR[0]);
  printf("  r1 = %u\n", cpu->reg.GPR[1]);


  while(!cpu->terminate_flag){
    fetch(cpu);
    decode(cpu);
    execute(cpu);
  }

  printf("Depois da execução:\n");
  printf("  r0 = %u\n", cpu->reg.GPR[0]);
  printf("  r1 = %u\n", cpu->reg.GPR[1]);


  free(cpu);
  return EXIT_SUCCESS;
}
