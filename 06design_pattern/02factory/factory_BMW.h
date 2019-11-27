#include "factory.h"


class factory_BMW:public factory
{
public:
     virtual shared_ptr<car> create_car(void);
};
