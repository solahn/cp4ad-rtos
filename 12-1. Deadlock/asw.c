#include "bsw.h"
#include "mutex.h"

volatile unsigned long shared = 0;

MutexType s1;
MutexType s2;

ISR2(TimerISR)
{
    static long c = -5;
    printfSerial("\n%4ld: ", ++c);
    if(c == -4) {
    	//Write the code below.
    	InitMutex(&s1, Event1);
    	InitMutex(&s2, Event2);
    }
    //Write the code below.
    else if (c == 4) {
    	ActivateTask(TaskL);
    }
    else if (c == 6) {
    	ActivateTask(TaskH);
    }
}

TASK(TaskH)
{
	printfSerial("<TaskH begins.> ");
	//Write the code below.
	mdelay(1000);

	printfSerial("TaskH : Try Lock(S1). ");
	//Write the code below.
	GetMutex(&s1);
	printfSerial("TaskH : Get Lock(S1). ");

	//Write the code below.
	mdelay(3000);

	printfSerial("TaskH : Try Lock(S2). ");
	//Write the code below.
	GetMutex(&s2);
	printfSerial("TaskH : Get Lock(S2). ");

	//Write the code below.
	mdelay(2000);

	printfSerial("TaskH : Release Lock(S2). ");
	//Write the code below.
	ReleaseMutex(&s2);

	//Write the code below.
	mdelay(1000);

	printfSerial("TaskH : Release Lock(S1). ");
	//Write the code below.
	ReleaseMutex(&s1);

	//Write the code below.
	mdelay(2000);

	printfSerial("<TaskH ends.> ");
    TerminateTask();
}

TASK(TaskL)
{
	printfSerial("<TaskL begins.> ");
	//Write the code below.
	mdelay(1000);

	printfSerial("TaskL : Try Lock(S2). ");
	//Write the code below.
	GetMutex(&s2);
	printfSerial("TaskL : Get Lock(S2). ");

	//Write the code below.
	mdelay(2000);

	printfSerial("TaskL : Try Lock(S1). ");
	//Write the code below.
	GetMutex(&s1);
	printfSerial("TaskL : Get Lock(S1). ");

	//Write the code below.
	mdelay(2000);

	printfSerial("TaskL : Release Lock(S1). ");
	//Write the code below.
	ReleaseMutex(&s1);

	//Write the code below.
	mdelay(1000);

	printfSerial("TaskL : Release Lock(S2). ");
	//Write the code below.
	ReleaseMutex(&s2);

	//Write the code below.
	mdelay(1000);
	printfSerial("<TaskL ends.> ");
	TerminateTask();
}
