/*
	프로그램 설명 
	1~10 까지 덧셈하여 출력
	기존에 지니던 문제점 해결
*/
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si1 = { 0, };
	STARTUPINFO si2 = { 0, };

	PROCESS_INFORMATION pi1;
	PROCESS_INFORMATION pi2;

	DWORD return_val1;
	DWORD return_val2;

	TCHAR command1[] = _T("PartAdder.exe 1 5");
	TCHAR command2[] = _T("PartAdder.exe 6 10");

	DWORD sum = 0;

	si1.cb = sizeof(si1);
	si2.cb = sizeof(si2);

	CreateProcess(NULL, command1,
		NULL, NULL, TRUE,
		0, NULL, NULL,
		&si1, &pi1);

	CreateProcess(NULL, command2,
		NULL, NULL, TRUE,
		0, NULL, NULL,
		&si2, &pi2);

	CloseHandle(pi1.hThread);
	CloseHandle(pi2.hThread);

	/**********문제 해결을 위해 추가되는 두줄의 코드 ****************/
	WaitForSingleObject(pi1.hProcess, INFINITE);
	WaitForSingleObject(pi2.hProcess, INFINITE);

	GetExitCodeProcess(pi1.hProcess, &return_val1);
	GetExitCodeProcess(pi2.hProcess, &return_val2);

	if (return_val1 == -1 || return_val2 == -1)
		return -1;	//비정상적 종료

	sum += return_val1;
	sum += return_val2;

	_tprintf(_T("total: %d \n"), sum);

	CloseHandle(pi1.hProcess);
	CloseHandle(pi2.hProcess);
	return 0;
}
