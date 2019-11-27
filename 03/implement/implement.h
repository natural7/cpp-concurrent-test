#pragma once
#include <iostream>
#include <stdint.h> 
#include "../interface/interface.h"



class implement : public action
{
   public:
   virtual void dress(void);
   virtual void eat(void);
   virtual void live(void);
   virtual void move(void);
};

