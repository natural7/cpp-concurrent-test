#include "Audi.h"
Audi::Audi(/* args */)
{
    cout<< "i am constructor Audi"<<endl;
}

Audi::~Audi()
{
    cout<< "Audi will go away"<<endl;
}

void Audi::speak_name(void)
{
    cout<< "i am Audi~~~"<<endl;
}