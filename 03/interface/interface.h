#pragma once
#include <iostream>
#include <stdint.h> 


class action
{
   public:
   virtual void dress(void) = 0;
   virtual void eat(void) = 0;
   virtual void live(void) = 0;
   virtual void move(void) = 0;
};