#ifndef SIGNAL_H
#define SIGNAL_H
#include <stdint.h>
#include <stdio.h>

typedef void(*pf_read)(void);
typedef void(*pf_process)(void);
typedef void(*pf_write)(void);
typedef char(*get_name)(struct signal_t *self);

typedef struct signal_t
{
    pf_read read;
    pf_process process;
    pf_write   write;
    get_name   gname;
    char name;
}signal_t;
signal_t* new_signal(pf_read read,pf_process process,pf_write write,char name);
static void signal_init(signal_t *self,pf_read read,pf_process process,pf_write write,char name);
char signal_get_name(signal_t *self);
void delete_signal(signal_t* self);
/*Created: wang on 19/10/08.*/
#endif