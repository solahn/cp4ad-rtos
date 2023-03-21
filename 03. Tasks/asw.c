#include "bsw.h"

ISR2(TimerISR)
{
    static long c = 0;
    printfSerial("\n%4ld: ", c++);
}

TASK(Task1)
{
	printfSerial("Task1 Begins...");
	mdelay(3000);
	printfSerial("Task1 Finishes...");

	TerminateTask();
}

//Write the code below.
TASK(Task2)
{
	printfSerial("Task2 Begins...");
	mdelay(3000);
	printfSerial("Task2 Finishes...");

	TerminateTask();
}
