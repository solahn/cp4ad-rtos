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
    else if ( ) {
    	ActivateTask( );
    }
    else if ( ) {
    	ActivateTask( );
    }
    else if ( ) {
    	ActivateTask( );
    }
}

TASK(TaskH)
{
	printfSerial("<TaskH begins.> ");	//6s
	//Write the code below.


	printfSerial("TaskH : Try Lock(S1). ");		//7s
	//Write the code below.


	printfSerial("TaskH : Get Lock(S1). ");		//7s

	//Write the code below.


	printfSerial("TaskH : Try Lock(S2). ");		//10s
	//Write the code below.


	printfSerial("TaskH : Get Lock(S2). ");		//7s
	//Write the code below.


	printfSerial("TaskH : Release Lock(S2). ");	//13s
	//Write the code below.


	//Write the code below.


	printfSerial("TaskH : Release Lock(S1). ");	//14s
	//Write the code below.


	//Write the code below.


	printfSerial("<TaskH ends.> ");	//15s
    TerminateTask();
}

TASK(TaskM)
{
	printfSerial("<TaskM begins.> ");	//15s
	//Write the code below.


	printfSerial("TaskM : Try Lock(S2). ");	//16s
	//Write the code below.

	printfSerial("TaskM : Get Lock(S2). ");		//7s

	//Write the code below.


	printfSerial("TaskM : Release Lock(S2). ");	//18s
	//Write the code below.


	//Write the code below.


	printfSerial("<TaskM ends.> ");	//19s
	TerminateTask();
}

TASK(TaskL)
{
	printfSerial("<TaskL begins.> ");	//0s
	//Write the code below.


	printfSerial("TaskL : Try Lock(S1). ");	//2s
	//Write the code below.


	printfSerial("TaskL : Get Lock(S1). ");		//7s

	//Write the code below.


	printfSerial("TaskL : Release Lock(S1). ");	//6s
	//Write the code below.


	//Write the code below.


	printfSerial("<TaskL ends.> ");	//19.5s
	TerminateTask();
}
