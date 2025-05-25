#include "../include/hardware.h"
#include "../include/terminal_io.h"
#include "../include/cycle.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static inline int wait_for_input() {
    printf("Pressione ENTER para continuar ou 't' + ENTER para executar até o próximo fetch: ");
    int c = getchar();
    // Limpa o buffer caso tenha sobrado algo
    while (getchar() != '\n' && !feof(stdin));
    return (c == 't' || c == 'T');
}


int main(void) {
  // 1) Inicializa a CPU
  CPU *cpu = init_cpu();
  if (!cpu) {
    fprintf(stderr, "Falha ao alocar a CPU\n");
    return EXIT_FAILURE;
  }

  print_memory(cpu);
  int run_until_next_fetch = 0;
  while (!cpu->terminate_flag) {
      if (!run_until_next_fetch) {
          run_until_next_fetch = wait_for_input();
      }
      fetch(cpu);

      if (!run_until_next_fetch) {
          run_until_next_fetch = wait_for_input();
      }
      decode(cpu);

      if (!run_until_next_fetch) {
          run_until_next_fetch = wait_for_input();
      }
      execute(cpu);

      if (run_until_next_fetch) {
          run_until_next_fetch = 0;
      }
  }


  free(cpu);
  return EXIT_SUCCESS;
}
