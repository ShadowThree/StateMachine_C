#include <stdio.h>
#include "fsm.h"

extern FsmTable_t *year_table;

int main(void)
{
    FSM_t year_fsm;
    FSM_Regist(&year_fsm, year_table);
    year_fsm.curState = SPRING;
    year_fsm.size = sizeof(year_table)/sizeof(FsmTable_t);

    printf("\n-------1--init spring------\n");
    printf("state:%d\n", year_fsm.curState);

    printf("\n-------2--spring->summer------\n");
    FSM_EventHandle(&year_fsm,EVENT1);
    printf("state:%d\n",year_fsm.curState);

    printf("\n-------3--summer->autumn------\n");
    FSM_EventHandle(&year_fsm,EVENT2);
    printf("state:%d\n",year_fsm.curState);

    printf("\n-------4--autumn->winter------\n");
    FSM_EventHandle(&year_fsm,EVENT3);
    printf("state:%d\n",year_fsm.curState);

    printf("\n-------5--winter->spring------\n");
    FSM_EventHandle(&year_fsm,EVENT4);
    printf("state:%d\n",year_fsm.curState);

    printf("\n-------6--receive EVENT2 not EVENT1------\n");
    FSM_EventHandle(&year_fsm,EVENT2);
    printf("state:%d\n",year_fsm.curState);

    return 0;
}
