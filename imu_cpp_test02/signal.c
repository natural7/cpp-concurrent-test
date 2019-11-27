#include"./signal.h"

void signal_init(signal_t *self,pf_read *read,pf_process *process,pf_write *write,char name)
{
    self->read = read;
    self->process = process;
    self->write = write;
    self->gname = signal_get_name;//这里直接用父类的即可，不用在子类中再初始化了，即：没有多态
                                  //注意函数指针的赋值，只需要把地址给了即可，不需要加参数：
                                  //不要写成self->gname = signal_get_name(self)
                                  //调用的时候，才传参
    self->name = name;
}

char signal_get_name(signal_t *self)
{
    return (char)self->name;
}