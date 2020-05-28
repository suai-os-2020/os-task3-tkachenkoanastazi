#include "lab3.h"
#include <windows.h>
#include <string>

#define MAX_COUNT 12

using namespace std;

//Threads
HANDLE  aThread,
	bThread,
	cThread,
	dThread,
	eThread,
	fThread,
	gThread,
	hThread,
	iThread,
	kThread,
	nThread,
	mThread;

//Mutex
HANDLE stdout_mutex;
DWORD IDThread;

//Semaphors
HANDLE  sem_A,
	sem_B,
	sem_C,
	sem_D,
	sem_E,
	sem_F,
	sem_G,
	sem_H,
	sem_I,
	sem_K,
	sem_M,
	sem_N,
	gap;

unsigned int lab3_thread_graph_id() 
{
    return 5;
}

const char* lab3_unsynchronized_threads()
{
    return "cdfg";
}

const char* lab3_sequential_threads()
{
    return "ikm";
}

DWORD WINAPI a (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "a"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

ReleaseSemaphore(sem_A, 1, NULL);
return 0;
}

DWORD WINAPI b (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "b"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

return 0;
}

DWORD WINAPI e (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "e"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

return 0;
}

DWORD WINAPI g (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "g"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

	ReleaseSemaphore(gap, 1, NULL);
	WaitForSingleObject(sem_G, INFINITE);

for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "g"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

	ReleaseSemaphore(gap, 1, NULL);
	WaitForSingleObject(sem_G, INFINITE);

for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "g"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}


return 0;
}


DWORD WINAPI c (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "c"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

	ReleaseSemaphore(gap, 1, NULL);
	WaitForSingleObject(sem_C, INFINITE);

for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "c"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

	ReleaseSemaphore(gap, 1, NULL);
	WaitForSingleObject(sem_C, INFINITE);

for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "c"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

return 0;
}

DWORD WINAPI d (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "d"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}


return 0;
}

DWORD WINAPI f (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "f"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}
return 0;
}

DWORD WINAPI h (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "h"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}
return 0;
}

DWORD WINAPI k (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "k"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

	ReleaseSemaphore(gap, 1, NULL);

for(int i=0; i<3; i++){
	WaitForSingleObject(sem_K, INFINITE);
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "k"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();
	ReleaseSemaphore(sem_M, 1, NULL);}
return 0;
}

DWORD WINAPI i (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(sem_I, INFINITE);
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "i"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();
	ReleaseSemaphore(sem_K, 1, NULL);}
return 0;
}

DWORD WINAPI m (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(sem_M, INFINITE);
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "m"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();
	ReleaseSemaphore(sem_I, 1, NULL);}

	ReleaseSemaphore(gap, 1, NULL);
	WaitForSingleObject(sem_M, INFINITE);

	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "m"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}

return 0;
}

DWORD WINAPI n (LPVOID pVoid)
{
	for(int i=0; i<3; i++){
	WaitForSingleObject(stdout_mutex, INFINITE);
	cout<< "n"<< flush;
	ReleaseMutex(stdout_mutex);
	computation();}
return 0;
}

int lab3_init()
{
    int inc=12;
	stdout_mutex=CreateMutex(NULL, false, NULL);
	if(stdout_mutex==NULL)
	return GetLastError();

sem_A=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_A == NULL)
return GetLastError();

sem_B=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_B == NULL)
return GetLastError();

sem_C=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_C == NULL)
return GetLastError();

sem_D=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_D == NULL)
return GetLastError();

sem_E=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_E == NULL)
return GetLastError();

sem_F=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_F == NULL)
return GetLastError();

sem_G=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_G == NULL)
return GetLastError();

sem_H=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_H == NULL)
return GetLastError();

sem_I=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_I == NULL)
return GetLastError();

sem_K=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_K == NULL)
return GetLastError();

sem_M=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_M == NULL)
return GetLastError();

sem_N=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (sem_N == NULL)
return GetLastError();

gap=CreateSemaphore(NULL, 0, MAX_COUNT, NULL);
if (gap == NULL)
return GetLastError();


aThread = CreateThread(NULL, 0, (a), 0, 0, &IDThread);
if(aThread == NULL)
	return GetLastError();

cThread = CreateThread(NULL, 0, (c), 0, 0, &IDThread);
if(cThread == NULL)
	return GetLastError();

WaitForSingleObject(aThread, INFINITE);
WaitForSingleObject(gap, INFINITE);

ReleaseSemaphore(sem_C, 1, NULL);

bThread = CreateThread(NULL, 0, (b), 0, 0, &IDThread);
if(bThread == NULL)
	return GetLastError();

eThread = CreateThread(NULL, 0, (e), 0, 0, &IDThread);
if(eThread == NULL)
	return GetLastError();

gThread = CreateThread(NULL, 0, (g), 0, 0, &IDThread);
if(gThread == NULL)
	return GetLastError();

WaitForSingleObject(bThread, INFINITE);
WaitForSingleObject(eThread, INFINITE);

WaitForSingleObject(gap, INFINITE);
WaitForSingleObject(gap, INFINITE);
ReleaseSemaphore(sem_C, 1, NULL);
ReleaseSemaphore(sem_G, 1, NULL);

dThread = CreateThread(NULL, 0, (d), 0, 0, &IDThread);
if(dThread == NULL)
	return GetLastError();

fThread = CreateThread(NULL, 0, (f), 0, 0, &IDThread);
if(fThread == NULL)
	return GetLastError();

WaitForSingleObject(dThread, INFINITE);
WaitForSingleObject(fThread, INFINITE);
WaitForSingleObject(cThread, INFINITE);

WaitForSingleObject(gap, INFINITE);
ReleaseSemaphore(sem_G, 1, NULL);

hThread = CreateThread(NULL, 0, (k), 0, 0, &IDThread);
if(dThread == NULL)
	return GetLastError();

hThread = CreateThread(NULL, 0, (h), 0, 0, &IDThread);
if(hThread == NULL)
	return GetLastError();
WaitForSingleObject(gThread, INFINITE);
WaitForSingleObject(hThread, INFINITE);

WaitForSingleObject(gap, INFINITE);
ReleaseSemaphore(sem_I, 1, NULL);

iThread = CreateThread(NULL, 0, (i), 0, 0, &IDThread);
if(iThread == NULL)
	return GetLastError();

mThread = CreateThread(NULL, 0, (m), 0, 0, &IDThread);
if(mThread == NULL)
	return GetLastError();
WaitForSingleObject(kThread, INFINITE);	
WaitForSingleObject(iThread, INFINITE);

WaitForSingleObject(gap, INFINITE);
ReleaseSemaphore(sem_M, 1, NULL);

nThread = CreateThread(NULL, 0, (n), 0, 0, &IDThread);
if(nThread == NULL)
	return GetLastError();

WaitForSingleObject(mThread, INFINITE);
WaitForSingleObject(nThread, INFINITE);

//закрываем дескриптор
CloseHandle(sem_B);
CloseHandle(sem_C);
CloseHandle(sem_D);
CloseHandle(sem_E);
CloseHandle(sem_F);
CloseHandle(sem_G);
CloseHandle(sem_K);
CloseHandle(sem_I);
CloseHandle(sem_H);
CloseHandle(sem_M);
CloseHandle(sem_N);
CloseHandle(gap);	
CloseHandle(stdout_mutex);
    
    return 0;
}
