#include <iostream>
#include <stdint.h>
#include "factory.h"
#include "factory_BMW.h"
#include "factory_Audi.h"
#include <memory>
using namespace std;




void foo(void)
{
   factory *pf = NULL;
   shared_ptr<car> pcar = NULL;

   pf = new factory_BMW();
   pcar = pf->create_car();
   pcar->speak_name();

   pf = new factory_Audi();
   pcar = pf->create_car();
   pcar->speak_name();

}

int main(void)
{
   foo();

   cout << "in main"<<endl;
   return 0;

}