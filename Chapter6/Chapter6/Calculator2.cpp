/*
	프로그램 설명 :
	1. 사칙연산 프로그램
	2. 개선된 예제
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

enum { DIV =1 , MUL , ADD ,MIN , ELSE , EXIT};

DWORD ShowMenu();

void Divide(double, double);
void Multiple(double, double);
void Add(double, double);
void Min(double, double);

int _tmain(int argc, TCHAR* argv[])
{

	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	TCHAR command[] = _T("calc.exe");
	SetCurrentDirectory(_T("C:\\WINDOWS\\system32"));

	DWORD sel;
	double num1, num2;
	while (true)
	{
		sel = ShowMenu();
		if (sel == EXIT)
			return 0;

		if (sel != ELSE)
		{
			_fputts(_T("Input Num1 Num2 : "), stdout);
			_tscanf(_T("%if %if"), &num1, &num2);
		}

		switch (sel)
		{
		case DIV:
			Divide(num1, num2);
			break;

		case MUL:
			Multiple(num1, num2);
			break;

		case ADD:
			Add(num1, num2);
			break;

		case MIN:
			Min(num1, num2);
			break;

		case ELSE:
			ZeroMemory(&pi, sizeof(pi));
			CreateProcess(
				NULL, command, NULL, NULL,
				TRUE, 0, NULL, NULL, &si, &pi);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			break;

		}
	}
	return 0;

}

DWORD ShowMenu()
{
	DWORD sel;
	_fputts(_T("______MENU______\n"), stdout);
	_fputts(_T("num 1 : Dibide \n"), stdout);
	_fputts(_T("num 2 : Multiple \n"), stdout);
	_fputts(_T("num 3 : Add \n"), stdout);
	_fputts(_T("num 4 : Minus \n"), stdout);
	_fputts(_T("num 5 : Any Other Operations. \n"), stdout);
	_fputts(_T("num 6 : Exit \n"), stdout);
	_fputts(_T("SELECTION >> "), stdout);
	_tscanf(_T("%d"), &sel);

	return sel;
}

void Divide(double a, double b)
{
	_tprintf(_T("%f/%f = %f \n\n"), a, b, a / b);
}

void Multiple(double a, double b)
{
	_tprintf(_T("%f*%f = %f \n\n"), a, b, a * b);
}

void Add(double a, double b)
{
	_tprintf(_T("%f+%f = %f \n\n"), a, b, a + b);
}

void Min(double a, double b)
{
	_tprintf(_T("%f-%f = %f \n\n"), a, b, a-b);
}
