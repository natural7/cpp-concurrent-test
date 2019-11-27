#include<stdint.h>
#include<stdio.h>
#include"./basic.h"
#include"./gradient.h"

void foo()
{
    uint8_t cycle_time = 10;
    signal_t* ps = new_basic_signal(cycle_time);
    printf("ps address: %x\n",&ps);
    printf("ps real address: %x\n",&(*ps));
    printf("read_basic_signal address: %x\n",&read_basic_signal);
    printf("---------\n");
    printf("ps->read address: %x\n",&(*(ps->read)));
    printf("ps->read address: %x\n",&ps->read);
    printf("ps->read address: %x\n",&((signal_t*)(&ps))->read);

    printf("ps->read address: %x\n",((signal_t*)(*(ps->read)))->read);
    printf("ps->gname address: %x\n",((signal_t*)(*(ps->read)))->gname);
    printf("ps->gname address: %x\n",&signal_get_name);

    ((signal_t*)(*(ps->read)))->read();//因为new了两次，所以对地址进行了转换
    ((signal_t*)(*(ps->read)))->process();
    ((signal_t*)(*(ps->read)))->write();
    ((signal_t*)(*(ps->read)))->gname(ps);
    printf("name: %c\n",((signal_t*)(*(ps->read)))->name);
    printf("name: %c\n",((signal_t*)(*(ps->read)))->gname(ps));//入参还不是ps，而是下边的
    printf("name: %c\n",((signal_t*)(*(ps->read)))->gname((signal_t*)(*(ps->read))));//入参是signal部分的首地址
    printf("signal_t: %d\n",sizeof(signal_t));

    delete_basic_signal((basic_t *)ps);
}

int main(void)
{  
   foo();
   return 0;
}
