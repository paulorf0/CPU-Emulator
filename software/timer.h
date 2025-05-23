#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
#include <time.h>

static inline void delay(uint16_t cycles, uint16_t clock_hz){
    double delay_seconds = cycles / clock_hz;

    struct timespec ts;
    ts.tv_sec = (time_t)delay_seconds;
    ts.tv_nsec = (long)((delay_seconds - ts.tv_sec) * 1e9);

    nanosleep(&ts, NULL);
}

#endif
