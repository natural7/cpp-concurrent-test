#include<stdint.h>
#include<stdio.h>
#include"./basic.h"
#include"./gradient.h"

void foo()
{
    signal_t* basic_signal = new_basic_signal();
    basic_signal->read();
    basic_signal->process();
    basic_signal->write();
    printf("name: %c\n",basic_signal->gname(basic_signal));
    printf("signal_t: %d\n",sizeof(signal_t));

    delete_basic_signal(basic_signal)
    //gradient没有再实现，想想其实定义一个结构体就可以，没必要多态
    //read process write仅仅作为接口即可
    //当然，这里的多态思想，可以以后用
}

int main(void)
{  
   foo();
   return 0;
}
