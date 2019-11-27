#include <iostream>
#include <stdint.h> 
#pragma once
#include "../people/people.h" 
using namespace std;  

class student : public people
{
   public:
   enum type
   {
      PRIMARY = 0,
      SECONDARY
   };

   student(bool type = PRIMARY);
   student(const string name, const uint32_t age, const uint8_t score,uint32_t print_num=0,bool type = PRIMARY);
   student(const student &st);
   ~ student(void);
   void set_score(uint8_t score);
   int get_score(void) const;
   void print_student(void) const;

   virtual void life_style(void);
   virtual void spend_life(void);

   private:
   uint8_t score;
   const bool type;
   static uint32_t sum;
   static string properity;

   mutable uint32_t print_num;/*mutable variable can only be change in the const member function*/
};
