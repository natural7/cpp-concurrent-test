#include "factory_abstract.h"
#include "BMW_car.h"
#include "BMW_bike.h"

class factory_BMW: public factory_abstract
{
public:
     virtual shared_ptr<car> create_car(void);
     virtual shared_ptr<bike> create_bike(void);
};
