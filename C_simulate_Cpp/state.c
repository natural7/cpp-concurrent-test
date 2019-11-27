#include <stdio.h>
#include <stdlib.h>
#include "state.h"
#include "water.h"

const char* stateGetName(State* state);
State* newSolidState();
State* newLiquidState();
State* newGaseousState();
void solidStateInit(SolidState* self);
Boolean solidStateMatch(State* self, int temperature);
void solidStateHandle(State* self, struct Water* water);
void liquidStateInit(LiquidState* self);
Boolean liquidStateMatch(State* self, int temperature);
void liquidStateHandle(State* self, struct Water* water);
void gaseousStateInit(GaseousState* self);
Boolean gaseousStateMatch(State* self, int temperature);
void gaseousStateHandle(State* self, struct Water* water);

State* newState(StateIdentifier identifier)//相当于使用简单工厂模式
{
    switch(identifier)
    {
    case SOLID: return newSolidState();//这里直接用了return，代码规范性不好。。
    case LIQUID: return newLiquidState();//new新的数据，返回抽象数据类型
    case GASEOUS: return newGaseousState();
    default: return NULL;
    }
}


void stateInit(State* self,
        void (*handle)(struct State* self, struct Water* water),
        Boolean (*match)(struct State* self, int temperature),
        char* name)
{
    self->handle = handle;
    self->match = match;
    self->getName = stateGetName;
    self->name = name;
}

State* newSolidState()   //类的构造函数，完成内存分配和初始化
{
    State* state = (State*)malloc(sizeof(SolidState));
    if (state != NULL)
    {
       solidStateInit((SolidState*)state);
    }
    return state;
}

State* newLiquidState()
{
    State* state = (State*)malloc(sizeof(LiquidState));
    if (state != NULL)
    {
        liquidStateInit((LiquidState*)state);
    }
    return state;
}

State* newGaseousState()
{
    State* state = (State*)malloc(sizeof(GaseousState));
    if (state != NULL)
    {
        gaseousStateInit((GaseousState*)state);
    }
    return state;
}

const char* stateGetName(State* state)//只用实现一个
{
    return state->name;
}

void solidStateInit(SolidState* self)
{
    stateInit((State*)self, solidStateHandle, solidStateMatch, "SolidState");//初始化的时候，将函数指针分配好，也就是所谓的虚函数表
}

void solidStateHandle(State* self, Water* water)
{
    printf("solidState:tepm:%d C\n", water->getTemperature(water));
}

Boolean solidStateMatch(State* self, int temperature)
{
    return temperature < 0;
}

void liquidStateInit(LiquidState* self)
{
    stateInit((State*)self, liquidStateHandle, liquidStateMatch, "LiquidState");
}

void liquidStateHandle(State* self, Water* water)
{
    printf("liquidState:tepm%d C\n", water->getTemperature(water));
}

Boolean liquidStateMatch(State* self, int temperature)
{
    return temperature >= 0 && temperature < 100;
}

void gaseousStateInit(GaseousState* self)
{
    stateInit((State*)self, gaseousStateHandle, gaseousStateMatch, "GaseousState");
}

void gaseousStateHandle(State* self, Water* water)
{
    printf("gaseousState,tepm%d C\n", water->getTemperature(water));
}

Boolean gaseousStateMatch(State* self, int temperature)
{
    return temperature > 100;
}

void deleteState(State* state)
{
    free(state);
}