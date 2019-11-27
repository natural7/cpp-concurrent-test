#ifndef BMW_H
#define BMW_H

#include <iostream>
#include <stdint.h>
#include "car.h"
#include "BMW.h"
using namespace std;


class BMW:public car
{
public:
    BMW(/* args */);
    ~BMW();
    virtual void speak_name(void);
};

/*Created: wang on 19/10/02.*/
#endif