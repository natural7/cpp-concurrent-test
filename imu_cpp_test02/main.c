#include<stdint.h>
#include<stdio.h>
#include"./basic.h"
#include"./gradient.h"
signal_t basic_signal;

void foo()
{
    // signal_init(&basic_signal,read_basic_signal,proces_basic_signal,write_basic_signal,'B');
    new_basic_signal(&basic_signal);
    // signal_t* basic_signal = new_basic_signal();
    basic_signal.read();
    basic_signal.process();
    basic_signal.write();
    // printf("name: %c\n",basic_signal.gname());
    printf("name: %c\n",basic_signal.gname(&basic_signal));
    printf("sizeof signal_t: %d\n",sizeof(signal_t));

    // delete_basic_signal(basic_signal)
}

int main(void)
{  
   foo();
//    signal_t1 tt;
//    tt.gname = signal_get_name1;
//    tt.gname(&tt);
   return 0;
}
