#include <stdlib.h>
#include"./signal.h"
signal_t* new_signal(pf_read read,pf_process process,pf_write write,char name)
{
    signal_t* signal = (signal_t*)malloc(sizeof(signal_t));
    printf("new pointer signal address: %x\n",&signal);
    printf("new real signal address: %x\n",&(*signal));
    if (signal != NULL)
    {
       signal_init(signal,read,process,write,name);
    }
    printf("signal construtor\n");
    return signal;
}

static void signal_init(signal_t *self,pf_read read,pf_process process,pf_write write,char name)
{
    self->read = read;
    self->process = process;
    self->write = write;
    self->gname = signal_get_name;//这里直接用父类的即可，不用在子类中再初始化了，即：没有多态
    self->name = name;
    printf("read address: %x\n",&(*read));
    printf("process address: %x\n",&(*process));
    printf("write address: %x\n",&(*write));
    printf("read address: %x\n",&read);//直接指针地址，就是指针的地址，在 栈 区
    printf("process address: %x\n",&process);
    printf("write address: %x\n",&write);
    printf("read address: %x\n",read);//上边和这里一样，都指的是函数的地址，在 .text 段
    printf("process address: %x\n",process);
    printf("write address: %x\n",write);
    printf("name address: %x\n",name);
    printf("in --- self->read address: %x\n",&self->read);
}

char signal_get_name(signal_t *self)
{
    return (char)self->name;
}

void delete_signal(signal_t *self)
{
    if(NULL != self)
    {
        free(self);
    }

    self->read = NULL;
    self->write = NULL;
    self->process = NULL;
    self->gname = NULL;
    printf("signal destrutor\n");
}