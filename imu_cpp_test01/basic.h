#ifndef BASIC_H
#define BASIC_H
#include <stdint.h>
#include <stdio.h>
#include "./signal.h"
typedef struct basic_signal
{
    signal_t *signal;//重点，这里是指针
}basic_t;
signal_t* new_basic_signal(void);
void read_basic_signal(void);
void proces_basic_signal(void);
void write_basic_signal(void);
/*Created: wang on 19/10/08.*/
#endif