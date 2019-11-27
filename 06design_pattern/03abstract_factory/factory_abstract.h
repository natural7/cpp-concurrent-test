#ifndef FACTORY_ABSTRACT_H
#define FACTORY_ABSTRACT_H
#include <iostream>
#include <stdint.h>
#include "car.h"
#include "bike.h"
#include <memory>

using namespace std;

class factory_abstract
{
public:
    virtual shared_ptr<car> create_car(void) = 0;
    virtual shared_ptr<bike> create_bike(void) = 0;
};

#endif
/*Created: wang on 19/10/07.*/