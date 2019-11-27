#ifndef WATER_H
#define WATER_H

#define MAX_STATE_NUM (int)3
typedef unsigned char Boolean;
typedef unsigned long ErrCode;

#define ERR_SUCC (ErrCode)0
#define ERR_FAILED (ErrCode)1
#define ERR_MEM_MALLOC_FAILED (ErrCode)2
#define ABSTRACT(x) x

struct State;

typedef struct Water
{
    int (*getTemperature)(struct Water* self);
    void (*riseTemperature)(struct Water* self, int step);
    void (*reduceTemperature)(struct Water* self, int step);
    void (*behavior)(struct Water* self);
    void (*changeState)(struct Water* self);
    struct State* states[MAX_STATE_NUM];    //这里实现了多态
    struct State* currentState;
    int temperature;
} Water;

Water* newWater(int temperature);
void deleteWater(Water* water);

#endif