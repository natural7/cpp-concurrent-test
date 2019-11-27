#include <stdlib.h>
#include "./basic.h"

signal_t* new_basic_signal(void)
{
    signal_t* signal = (signal_t*)malloc(sizeof(basic_t));//这里虽然malloc basic_t的空间，但只用 继承部分
    if (signal != NULL)
    {
       basic_signal_init((basic_t*)signal,read_basic_signal,proces_basic_signal,write_basic_signal,'B');
    }
    return signal;
}

void basic_signal_init(basic_t *self,pf_read *read,pf_process *process,pf_write *write,char name)
{
    signal_init((signal_t*)self,read,process,write,name);
    printf("basic_signal_init name: %c\n",name);
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