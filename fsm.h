#ifndef _FSM_H_
#define _FSM_H_

#include <stdio.h>

void spring_thing();
void summer_thing();
void autumn_thing();
void winter_thing();

enum year_state
{
    SPRING = 1,
    SUMMER,
    AUTUMN,
    WINTER
};

enum year_event
{
    EVENT1 = 1,
    EVENT2,
    EVENT3,
    EVENT4
};

typedef struct FsmTable_s
{
    int event;
    int curState;
    void (*eventActFun)();
    int nextState;
} FsmTable_t;

typedef struct FSM_s
{
    int curState;
    FsmTable_t *pFsmTable;
    int size;
} FSM_t;

void FSM_Regist(FSM_t *pFsm, FsmTable_t *pTable);
void FSM_StateTransfer(FSM_t *pFsm, int state);
void FSM_EventHandle(FSM_t *pFsm, int event);

#endif
