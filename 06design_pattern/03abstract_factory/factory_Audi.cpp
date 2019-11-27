#include "factory_Audi.h"
#include "Audi_car.h"
#include "Audi_bike.h"

shared_ptr<car> factory_Audi::create_car(void)
{
    shared_ptr<car> p(new Audi_car());
    return p;
}

shared_ptr<bike> factory_Audi::create_bike(void)
{
    shared_ptr<bike> p(new Audi_bike());
    return p;
}

