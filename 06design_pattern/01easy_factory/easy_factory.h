#ifndef EASY_FACTORY_H
#include <iostream>
#include <stdint.h>
#include "car.h"
#include "BMW.h"
#include "Audi.h"
#include <memory>

using namespace std;

class easy_factory
{
public:
    enum CAR
    {
        CAR_BWM = 0,
        CAR_Audi
    };
    // easy_factory();
    shared_ptr<car> create_car(enum CAR);
};






#define EASY_FACTORY_H
#endif // 
/*Created: wang on 19/10/02.*/