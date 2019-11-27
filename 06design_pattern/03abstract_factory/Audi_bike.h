#ifndef AUDI_BIKE_H
#define AUDI_BIKE_H
#include <iostream>
#include <stdint.h>
#include "bike.h"
using namespace std;

class Audi_bike:public bike
{
public:
    Audi_bike();
    ~Audi_bike();
    virtual void speak_name(void);
};

/*Created: wang on 19/10/07.*/
#endif