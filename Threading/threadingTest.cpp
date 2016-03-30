/*=======================================================
	Code written by Jacob Hughes 
	
	jacob.solomon.hughes@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#pragma once

#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <stdio.h>
#include <iostream>

using namespace std;

unsigned __stdcall threadMain(void* p);

/*=======================================================
	Test program to explore the stats of the computer
	that this program is being run on.

	Uses WindowsAPI to test threading.
=======================================================*/

int wmain(int argc, wchar_t **args) {
	//Get the number of processors in the system
	DWORD_PTR c = GetMaximumProcessorCount((WORD)0);

	//create number of threads equal to number of processors
	HANDLE *m_threads = new HANDLE[c];

	cout << "==== System Information ====" << endl;

	cout << "Maximum number of processors supported: " << GetMaximumProcessorCount((WORD)0) << endl;

	cout << "Number of active processors: " << GetActiveProcessorCount((WORD)0) << endl;

	cout << "Maximum number of processor groups supported: " << GetMaximumProcessorGroupCount() << endl;

	cout << "Number of active processor groups: " << GetActiveProcessorGroupCount() << endl;

	cout << "============================" << endl << endl;
        
        //for each processor we create a thread and attempt an operation
	for (DWORD_PTR i = 0; i < c; i++) {

		//these two variables are for creating threads
		unsigned m_id = 0;
		DWORD_PTR m_mask = 1 << i;

		//
		//m_threads[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadMain, (LPVOID)i, NULL, &m_id);
		m_threads[i] = (HANDLE)_beginthreadex(NULL, 0, &threadMain, (LPVOID)i, NULL, &m_id);
		//

                //set eachthread to run on a separate CPU core
		SetThreadAffinityMask(m_threads[i], m_mask);
		//SetThreadIdealProcessor(m_threads[i], m_mask);

		int masknum = log(m_mask) / log(2);

		printf("Creating Thread %d (0x%08x) Assigning to CPU %d%\n", i, (LONG_PTR)m_threads[i],masknum);
	}

	//Wait for all the threads to finish
	cout << "Waiting for threads to complete..." << endl;
	WaitForMultipleObjects(c, m_threads, TRUE, INFINITE);
	cout << "All threads complete!" << endl;

	//Standard exit on keypress	
	std::cout << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);

	return 0;
}

//simple function for each thread to execute
unsigned __stdcall threadMain(void* p) {
	//print the number of the processor we are currently using
        printf("Current processor number: %d\n", (DWORD)GetCurrentProcessorNumber());
	return 0;
}
