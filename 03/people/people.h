#pragma once

#include <iostream>
#include <stdint.h> 
using namespace std;  
  
class people
{
   public:
   people(string name, uint32_t age):age(age),name(name)
   {
      cout<<"hello people"<<endl;
   };

   people(void);
   ~ people(void);
   people(const people &p);
   void set_age(uint32_t age);
   int get_age(void) const;
   string get_name(void)const;
   void print_people(void);

   virtual void life_style(void);
   virtual void spend_life(void) = 0;

   private:
   string  name;
   uint32_t age;
   
};