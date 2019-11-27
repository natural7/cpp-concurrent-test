#ifndef BASIC_H
#define BASIC_H
#include <stdint.h>
#include <stdio.h>
#include "./signal.h"
typedef struct basic_signal
{
    signal_t *signal;//重点，这里是指针
    uint8_t cycle_time;
}basic_t;

signal_t* new_basic_signal(uint8_t cycle_time);
static void basic_init(basic_t *self,uint8_t cycle_time);
void read_basic_signal(void);
void proces_basic_signal(void);
void write_basic_signal(void);
void delete_basic_signal(basic_t *self);
/*Created: wang on 19/10/08.*/
#endif