/*
	단순 출력 프로그램
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain2(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	

	// GetCurrentProcess() : 현재 실행되고 있는 프로세스 함수를 호출한 프로세스의 핸들을 얻을때 사용하는 함수
	// 반환값을 통해 핸들을 얻게 된다. ( 커널 오브젝트의 핸들(정수))

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++);

		_fputts(_T("Operation2.exe \n"), stdout);
	}

	return 0;
}