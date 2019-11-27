#include <iostream>
#include <stdint.h>
#include "easy_factory.h"
#include <memory>
using namespace std;




void foo(void)
{
   easy_factory *pf = new easy_factory;
   shared_ptr<car> pcar = NULL;

   pcar = pf->create_car(easy_factory::CAR_BWM);//这里使用类的域
   pcar->speak_name();
   cout << "-------"<<endl;

   pcar = pf->create_car(easy_factory::CAR_Audi);//这里使用类的域
   pcar->speak_name();

   cout << "-------"<<endl;

}

int main(void)
{
   foo();

   cout << "in main"<<endl;
   return 0;

}