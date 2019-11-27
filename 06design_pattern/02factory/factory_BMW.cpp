#include "factory_BMW.h"

shared_ptr<car> factory_BMW::create_car(void)
{
    shared_ptr<car> p(new BMW());
    return p;
}