#include <iostream>
#include <stdint.h>
#include "factory_BMW.h"
#include "factory_Audi.h"
#include <memory>
using namespace std;




void foo(void)
{
   factory_abstract *pf = NULL;
   shared_ptr<car> pcar = NULL;
   shared_ptr<bike> pbike = NULL;

   pf = new factory_Audi();
   pcar = pf->create_car();
   pcar->speak_name();
   pbike = pf->create_bike();
   pbike->speak_name();

   cout << "-------------"<<endl;
   
   pf = new factory_BMW();
   pcar = pf->create_car();
   pcar->speak_name();
   pbike = pf->create_bike();
   pbike->speak_name();

}

int main(void)
{
   foo();
   cout << "hello main"<<endl;
   return 0;

}