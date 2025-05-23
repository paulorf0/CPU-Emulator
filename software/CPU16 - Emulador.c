/*
    At argv[1] should be the name of input text with assembly code.

    Emulator flow:
        Run -> Load input in memory -> Fetch -> Decode -> Execute |
                                           |-----------------------|

    Each word have 1 byte, and MBR have 24 bits. Its necessary three cycle
    of fetch in memory to load the MBR.
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  if (argc == 1 || argc > 2) {
    printf("Modo de uso: ./*.exe <input.txt>\nDentro de input.txt deve ter "
           "o programa em assembly para execucao.");
    return 1;
  }

  static void *jump_table[] = {
      &&L_hlt, // 0x00 HLT
      &&L_nop, // 0x01 NOP

      &&L_add,  // 0x02 ADD
      &&L_sub,  // 0x03 SUB
      &&L_mul,  // 0x04 MUL
      &&L_div,  // 0x05 DIV
      &&L_cmp,  // 0x06 CMP
      &&L_movr, // 0x07 MOVR

      &&L_and, // 0x08 AND
      &&L_or,  // 0x09 OR
      &&L_xor, // 0x0A XOR
      &&L_not, // 0x0B NOT

      &&L_je,  // 0x0C JE
      &&L_jne, // 0x0D JNE
      &&L_jl,  // 0x0E JL
      &&L_jle, // 0x0F JLE
      &&L_jg,  // 0x10 JG
      &&L_jge, // 0x11 JGE
      &&L_jmp, // 0x12 JMP

      &&L_ld, // 0x13 LD
      &&L_st, // 0x14 ST

      &&L_ldr, // 0x15 LDR
      &&L_str, // 0x16 STR

      &&L_movi, // 0x17 MOVI
      &&L_addi, // 0x18 ADDI
      &&L_subi, // 0x19 SUBI
      &&L_muli, // 0x1A MULI
      &&L_divi, // 0x1B DIVI

      &&L_lsh, // 0x1C LSH
      &&L_rsh  // 0x1D RSH
  };

  while (1) {
  L_hlt:

    goto L_continue;

  L_nop:
    // Implement NOP operation here
    goto L_continue;

  L_add:
    // Implement ADD operation here
    goto L_continue;

  L_sub:
    // Implement SUB operation here
    goto L_continue;

  L_mul:
    // Implement MUL operation here
    goto L_continue;

  L_div:
    // Implement DIV operation here
    goto L_continue;

  L_cmp:
    // Implement CMP operation here
    goto L_continue;

  L_movr:
    // Implement MOVR operation here
    goto L_continue;

  L_and:
    // Implement AND operation here
    goto L_continue;

  L_or:
    // Implement OR operation here
    goto L_continue;

  L_xor:
    // Implement XOR operation here
    goto L_continue;

  L_not:
    // Implement NOT operation here
    goto L_continue;

  L_je:
    // Implement JE operation here
    goto L_continue;

  L_jne:
    // Implement JNE operation here
    goto L_continue;

  L_jl:
    // Implement JL operation here
    goto L_continue;

  L_jle:
    // Implement JLE operation here
    goto L_continue;

  L_jg:
    // Implement JG operation here
    goto L_continue;

  L_jge:
    // Implement JGE operation here
    goto L_continue;

  L_jmp:
    // Implement JMP operation here
    goto L_continue;

  L_ld:
    // Implement LD operation here
    goto L_continue;

  L_st:
    // Implement ST operation here
    goto L_continue;

  L_ldr:
    // Implement LDR operation here
    goto L_continue;

  L_str:
    // Implement STR operation here
    goto L_continue;

  L_movi:
    // Implement MOVI operation here
    goto L_continue;

  L_addi:
    // Implement ADDI operation here
    goto L_continue;

  L_subi:
    // Implement SUBI operation here
    goto L_continue;

  L_muli:
    // Implement MULI operation here
    goto L_continue;

  L_divi:
    // Implement DIVI operation here
    goto L_continue;

  L_lsh:
    // Implement LSH operation here
    goto L_continue;

  L_rsh:
    // Implement RSH operation here


    L_continue:
        continue;
  }

  return 0;
}
