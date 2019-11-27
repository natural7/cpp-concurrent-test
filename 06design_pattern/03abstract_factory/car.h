#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <stdint.h>

using namespace std;

class car
{
    public:
    car(void);//构造函数不能为虚函数
    virtual ~car(void);
    virtual void speak_name(void) = 0;
};

/*Created: wang on 19/10/02.*/
#endif
