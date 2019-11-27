#include <stdlib.h>
#include "./basic.h"
signal_t* new_basic_signal(uint8_t cycle_time)
{
    signal_t* pb = NULL;
    signal_t* basic = (signal_t*)malloc(sizeof(basic_t));
    printf("basic address: %x\n",&(*basic));
    printf("basic->signal address: %x\n",&((basic_t*)basic)->signal);
    printf("basic->cycle_time address: %x\n",&((basic_t*)basic)->cycle_time);
    if (basic != NULL)
    {
        pb = new_signal(read_basic_signal,proces_basic_signal,write_basic_signal,'B');
        ((basic_t*)basic)->signal = pb;
        printf("really basic->signal address: %x\n",&(*((basic_t*)basic)->signal));
        basic_init((basic_t *)basic,cycle_time);
        // ((basic_t*)basic)->signal = ps;
    }
    printf("basic construtor\n");
    return basic;
}

static void basic_init(basic_t *self,uint8_t cycle_time)
{
    self->cycle_time = cycle_time;
}

void read_basic_signal(void)
{
    printf("i am ReadBasicSignal\n");
}

void proces_basic_signal(void)
{
    printf("i am ProcessBasicSignal\n");
}

void write_basic_signal(void)
{
    printf("i am WriteBasicSignal\n");
}

void delete_basic_signal(basic_t *self)
{
    if(NULL != self)
    {
        free(self);
        free(self->signal);
    }

    self->signal = NULL;
}