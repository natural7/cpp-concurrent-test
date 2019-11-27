#include "factory_abstract.h"



class factory_Audi:public factory_abstract
{
public:
    virtual shared_ptr<car> create_car(void);
    virtual shared_ptr<bike> create_bike(void);
};
