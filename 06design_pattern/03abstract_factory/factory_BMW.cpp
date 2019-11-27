#include "factory_BMW.h"

shared_ptr<car> factory_BMW::create_car(void)
{
    shared_ptr<car> p(new BMW_car());
    return p;
}

shared_ptr<bike> factory_BMW::create_bike(void)
{
    shared_ptr<bike> p(new BMW_bike());
    return p;
}