#include "BMW_bike.h"

BMW_bike::BMW_bike()
{
    cout<< "i am constructor BMW bike"<<endl;
}

BMW_bike::~BMW_bike()
{
    cout<< "BMW bike will go away"<<endl;
}

void BMW_bike::speak_name(void)//声明有void，实现就得有void
{
    cout<< "i am BMW bike~~~"<<endl;
}