/*
	�ܼ� ��� ���α׷�
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain2(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	

	// GetCurrentProcess() : ���� ����ǰ� �ִ� ���μ��� �Լ��� ȣ���� ���μ����� �ڵ��� ������ ����ϴ� �Լ�
	// ��ȯ���� ���� �ڵ��� ��� �ȴ�. ( Ŀ�� ������Ʈ�� �ڵ�(����))

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++);

		_fputts(_T("Operation2.exe \n"), stdout);
	}

	return 0;
}