#include "bsw.h"
#include "mutex.h"

MutexType s1;
MutexType s2;

ISR2(TimerISR)
{
    static long c = -5;
    printfSerial("\n%4ld: ", ++c);
    if(c == -4) {
    	InitMutex(&s1, Event1);
    	InitMutex(&s2, Event2);
    }
    //Write the code below.
    else if (c == 0) {
    	ActivateTask(TaskL);
    }
    else if (c == 4) {
    	ActivateTask(TaskM);
    }
    else if (c == 6) {
    	ActivateTask(TaskH);
    }
}

TASK(TaskH)
{
	printfSerial("<TaskH begins.> ");	//6s
	//Write the code below.
	mdelay(1000);

	printfSerial("TaskH : Try Lock(S1). ");		//7s
	//Write the code below.
	GetMutex(&s1);
	printfSerial("TaskH : Get Lock(S1). ");		//7s

	//Write the code below.
	mdelay(3000);

	printfSerial("TaskH : Try Lock(S2). ");		//10s
	//Write the code below.
	GetMutex(&s2);
	printfSerial("TaskH : Get Lock(S2). ");		//7s
	//Write the code below.
	mdelay(3000);

	printfSerial("TaskH : Release Lock(S2). ");	//13s
	//Write the code below.
	ReleaseMutex(&s2);

	//Write the code below.
	mdelay(1000);

	printfSerial("TaskH : Release Lock(S1). ");	//14s
	//Write the code below.
	ReleaseMutex(&s1);

	//Write the code below.
	mdelay(1000);
	printfSerial("<TaskH ends.> ");	//15s
    TerminateTask();
}

TASK(TaskM)
{
	printfSerial("<TaskM begins.> ");	//15s
	//Write the code below.
	mdelay(1000);

	printfSerial("TaskM : Try Lock(S2). ");	//16s
	//Write the code below.
	GetMutex(&s2);
	printfSerial("TaskM : Get Lock(S2). ");		//7s

	//Write the code below.
	mdelay(2000);

	printfSerial("TaskM : Release Lock(S2). ");	//18s
	//Write the code below.
	ReleaseMutex(&s2);

	//Write the code below.
	mdelay(1000);
	printfSerial("<TaskM ends.> ");	//19s
	TerminateTask();
}

TASK(TaskL)
{
	printfSerial("<TaskL begins.> ");	//0s
	//Write the code below.
	mdelay(2000);

	printfSerial("TaskL : Try Lock(S1). ");	//2s
	//Write the code below.
	GetMutex(&s1);
	printfSerial("TaskL : Get Lock(S1). ");		//7s

	//Write the code below.
	mdelay(4000);

	printfSerial("TaskL : Release Lock(S1). ");	//6s
	//Write the code below.
	ReleaseMutex(&s1);

	//Write the code below.
	mdelay(1000);
	printfSerial("<TaskL ends.> ");	//19.5s
	TerminateTask();
}
