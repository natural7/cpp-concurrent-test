#ifndef BMW_CAR_H
#define BMW_CAR_H

#include <iostream>
#include <stdint.h>
#include "car.h"
#include "BMW_car.h"
using namespace std;


class BMW_car:public car
{
public:
    BMW_car(/* args */);
    ~BMW_car();
    virtual void speak_name(void);
};

/*Created: wang on 19/10/07.*/
#endif