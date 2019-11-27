#ifndef BMW_BIKE_H
#define BMW_BIKE_H
#include <iostream>
#include <stdint.h>
#include"bike.h"
using namespace std;

class BMW_bike:public bike
{
public:
    BMW_bike();
    ~BMW_bike();
    virtual void speak_name(void);
};

/*Created: wang on 19/10/07.*/
#endif