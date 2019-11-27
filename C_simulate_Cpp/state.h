#ifndef HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5
#define HFD8D9C8D_31C0_40B2_84CC_320E29DCACB5

// #include "pub/Keyword.h"
// #include "pub/BasicType.h"
#include "water.h"

struct Water;

/*方法一：声明了函数指针，在下边直接用*/
typedef ABSTRACT(void (*_handle)(struct State* self, struct Water* water));
typedef struct State
{
    _handle handle;
    ABSTRACT(Boolean (*match)(struct State* self, int temperature));//抽象类 State 的抽象方法通过宏关键字 VIRTUAL 来显式标记
    const char* (*getName)(struct State* self);//抽象类 State 的非抽象方法，在该抽象类中实现，具体子类继承相关方法直接复用
    char* name;
}State;

//方法二：在结构体中直接定义，直接用
// typedef struct State
// {
//     ABSTRACT(void (*handle)(struct State* self, struct Water* water));
//     ABSTRACT(Boolean (*match)(struct State* self, int temperature));//抽象类 State 的抽象方法通过宏关键字 VIRTUAL 来显式标记
//     const char* (*getName)(struct State* self);//抽象类 State 的非抽象方法，在该抽象类中实现，具体子类继承相关方法直接复用
//     char* name;
// }State;

typedef struct SolidState
{
    State base;
}SolidState;

typedef struct LiquidState
{
    State base;
}LiquidState;

typedef struct GaseousState
{
    State base;
}GaseousState;

typedef enum
{
    SOLID,
    LIQUID,
    GASEOUS
}StateIdentifier;

State* newState(StateIdentifier identifier);
void deleteState(State* state);

#endif