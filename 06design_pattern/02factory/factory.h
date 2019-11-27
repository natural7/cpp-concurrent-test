#ifndef FACTORY_H
#include <iostream>
#include <stdint.h>
#include "car.h"
#include "BMW.h"
#include "Audi.h"
#include <memory>

using namespace std;

class factory
{
public:
    virtual shared_ptr<car> create_car(void) = 0;
};






#define FACTORY_H
#endif // 
/*Created: wang on 19/10/02.*/