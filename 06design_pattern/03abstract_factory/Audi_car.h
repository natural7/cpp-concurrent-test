#ifndef AUDI_CAR_H
#define AUDI_CAR_H

#include <iostream>
#include <stdint.h>
#include "car.h"
#include "Audi_car.h"
using namespace std;


class Audi_car:public car
{
public:
    Audi_car(/* args */);
    ~Audi_car();
    virtual void speak_name(void);
};

/*Created: wang on 19/10/07.*/
#endif