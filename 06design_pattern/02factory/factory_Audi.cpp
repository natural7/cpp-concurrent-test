#include "factory_Audi.h"


shared_ptr<car> factory_Audi::create_car(void)
{
    shared_ptr<car> p(new Audi());
    return p;
}
