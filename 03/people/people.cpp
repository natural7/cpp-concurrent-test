#include <iostream>
#include"people.h"
using namespace std;  



people::people(void)
{
   cout<< "just test people, no pata"<< endl;
}

people::people(const people &p):name(p.name),age(p.age)
{
   cout<<"people copy constructor is called "<< endl;
}

people::~ people(void)
{
   cout<< "~ people, no pata"<< endl;
}

void people::set_age(uint32_t age)
{
   this->age = age;
}

int people::get_age(void) const
{
   return this->age;
}

string people::get_name(void) const
{
   return this->name;
}

void people::print_people(void)
{
   cout<< "people name:"<< this->name << "  age:"<< this->age << endl;
}

void people::life_style(void)
{
   cout << "people " << this->name << " no style .. "<< endl;
}