#include "fsm.h"

FsmTable_t year_table[] = 
{
    {EVENT1, SPRING, summer_thing, SUMMER},
    {EVENT2, SUMMER, autumn_thing, AUTUMN},
    {EVENT3, AUTUMN, winter_thing, WINTER},
    {EVENT4, WINTER, spring_thing, SPRING},
};

void spring_thing()
{
    printf("This is spring\n");
}

void summer_thing()
{
    printf("This is summer\n");
}

void autumn_thing()
{
    printf("This is autumn\n");
}

void winter_thing()
{
    printf("This is winter\n");
}

void FSM_Regist(FSM_t *pFsm, FsmTable_t *pTable)
{
    pFsm->pFsmTable = pTable;
}

void FSM_StateTransfer(FSM_t *pFsm, int state)
{
    pFsm->curState = state;
}

void FSM_EventHandle(FSM_t *pFsm, int event)
{
    FsmTable_t *pActTable = pFsm->pFsmTable;
    void (*eventActFun)() = NULL;
    int nextState;
    int curState = pFsm->curState;
    int g_max_num = pFsm->size;
    int flag = 0;
    int i = 0;

    for(i = 0; i < g_max_num; i++)
    {
        if(event == pActTable[i].event && curState == pActTable[i].curState)
	{
	    flag = 1;
	    eventActFun = pActTable[i].eventActFun;
	    nextState = pActTable[i].nextState;
	    break;
	}
    }

    if(flag)
    {
        if(eventActFun)
	{
	    eventActFun();
	}
	FSM_StateTransfer(pFsm, nextState);
    }
    else
    {
        printf("There is no match\n");
    }
}
