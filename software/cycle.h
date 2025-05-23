#pragma once
#include "timer.h"
#ifndef FETCH_H
#define FETCH_H

#include "../assembly/assembly.h"
#include "../hardware/hardware.h"


static inline void fetch(CPU *cpu){
    cpu->reg.MBR = 0x0;
    for(int i = 0; i < 3; i ++){
        delay(cpu->memory.freq,cpu->clock);
        cpu->reg.MBR = ((cpu->reg.MBR<<8 ) | cpu->memory.memory[cpu->reg.PC++]);
    }
    return;
}

static inline void decode(CPU *cpu){
    cpu->reg.IR = OPCODE5(cpu->reg.MBR);

}



#endif
