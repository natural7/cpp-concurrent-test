#include <stdlib.h>
#include "./basic.h"

void new_basic_signal(signal_t* basic_signal)
{
    basic_signal_init(basic_signal,read_basic_signal,proces_basic_signal,write_basic_signal,'B');
}

static void basic_signal_init(signal_t *self,pf_read *read,pf_process *process,pf_write *write,char name)
{
    signal_init((signal_t*)self,read,process,write,name);
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

void delete_basic_signal(signal_t *self)
{
    if(NULL != self)
    {
        free(self);
    }

    self->read = NULL;
    self->write = NULL;
    self->process = NULL;
}