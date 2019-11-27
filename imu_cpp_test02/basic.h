#ifndef BASIC_H
#define BASIC_H
#include <stdint.h>
#include <stdio.h>
#include "./signal.h"
static void basic_signal_init(signal_t *self,pf_read *read,pf_process *process,pf_write *write,char name);
void new_basic_signal(signal_t* basic_signal);
void read_basic_signal(void);
void proces_basic_signal(void);
void write_basic_signal(void);
void delete_basic_signal(signal_t *self);
/*Created: wang on 19/10/08.*/
#endif