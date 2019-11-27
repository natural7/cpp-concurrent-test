#include<stdint.h>
#include<stdio.h>
#include"./water.h"
#include"./state.h"

void statePatternRun()
{
    Water* water = newWater(25);
    if (water == NULL) return;

    water->behavior(water);
    water->riseTemperature(water, 50);
    water->behavior(water);
    water->reduceTemperature(water, 100);
    water->behavior(water);
    water->riseTemperature(water, 200);
    water->behavior(water);

    deleteWater(water);
}

int main(void)
{  
   statePatternRun();
   return 0;
}
