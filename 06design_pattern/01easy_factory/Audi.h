#ifndef AUDI_H
#define AUDI_H

#include <iostream>
#include <stdint.h>
#include "car.h"
#include "Audi.h"
using namespace std;


class Audi:public car
{
public:
    Audi(/* args */);
    ~Audi();
    virtual void speak_name(void);
};

/*Created: wang on 19/10/02.*/
#endif