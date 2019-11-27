#include"./signal.h"

void signal_init(signal_t *self,pf_read *read,pf_process *process,pf_write *write,char name)
{
    self->read = read;
    self->process = process;
    self->write = write;
    self->gname = signal_get_name;//这里直接用父类的即可，不用在子类中再初始化了，即：没有多态
    self->name = name;
    printf("signal_init name: %c\n",name);
}

char signal_get_name(signal_t *self)
{
    return (char)self->name;
}