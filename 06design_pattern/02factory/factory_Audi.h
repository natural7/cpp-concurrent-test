#include "factory.h"



class factory_Audi:public factory
{
public:
    virtual shared_ptr<car> create_car(void);
};
