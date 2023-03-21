#include "bsw.h"
#include "mutex.h"

volatile unsigned long shared = 0;

MutexType s1;

ISR2(TimerISR)
{
    static long c = -5;
    printfSerial("\n%4ld: ", ++c);
    if(c == -4) {
    	//Write the code below.

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
	printfSerial("<TaskH begins.> ");
	//Write the code below.


	printfSerial("TaskH : Try Lock(S1). ");
	//Write the code below.

	printfSerial("TaskH : Get Lock(S1). ");

	//Write the code below.


	printfSerial("TaskH : Release Lock(S1). ");
	//Write the code below.


	//Write the code below.


	printfSerial("<TaskH ends.> ");
    TerminateTask();
}

TASK(TaskM)
{
	printfSerial("<TaskM begins.> ");
	//Write the code below.

	printfSerial("<TaskM ends.> ");
	TerminateTask();
}

TASK(TaskL)
{
	printfSerial("<TaskL begins.> ");
	//Write the code below.


	printfSerial("TaskL : Try Lock(S1). ");
	//Write the code below.

	printfSerial("TaskL : Get Lock(S1). ");

	//Write the code below.


	printfSerial("TaskL : Release Lock(S1). ");
	//Write the code below.


	//Write the code below.

	printfSerial("<TaskL ends.> ");
	TerminateTask();
}
