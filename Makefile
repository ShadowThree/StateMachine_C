# This is a comment
# "mingw32-make" to execute this file on mingw64 platform.
# "make" to execute this file on Linux platform.

FSM_C: fsm.o main.o
	gcc -Wall fsm.o main.o -o FSM_C
fsm.o:fsm.c
	gcc -Wall -c fsm.c -o fsm.o
main.o:
	gcc -Wall -c main.c -o main.o
clean:
	rm -f *.o
	rm -f FSM_C
