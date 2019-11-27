#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include <stdint.h>
using namespace std;

class bike
{
    public:
    bike(void);//构造函数不能为虚函数
    virtual ~bike(void);
    virtual void speak_name(void) = 0;
};

/*Created: wang on 19/10/07.*/
#endif