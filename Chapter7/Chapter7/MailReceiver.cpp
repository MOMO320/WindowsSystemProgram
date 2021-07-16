/*
	MailReceiver.cpp
	프로그램 설명 : 메일 슬롯 Receiver
*/

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot;	// mailSlot 핸들
	TCHAR messageBox[50];
	DWORD bytesRead;	

	/* mailSlot 생성 */
	hMailSlot = CreateMailslot(
		SLOT_NAME,	// 주소
		0,	// 메일 슬롯 버퍼크기 , 0은 허용하는 최대치
		MAILSLOT_WAIT_FOREVER,	// ReadFile 함수 특성
		NULL	// 보안 설정
	);

	if (hMailSlot == INVALID_HANDLE_VALUE)
	{
		_fputts(_T("Unable to create mailslot!\n"), stdout);
		return 1;
	}

	/* Message 수신 */
	_fputts(_T("********* Message *********\n"), stdout);

	while (1)
	{
		if (!ReadFile(hMailSlot, messageBox, sizeof(TCHAR) * 50, &bytesRead, NULL))
		{
			_fputts(_T("Unable to read!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcsncmp(messageBox, _T("exit"), 4))
		{
			_fputts(_T("Good Bye!"), stdout);
			break;
		}

		messageBox[bytesRead / sizeof(TCHAR)] = 0;	// NULL 문자삽입
		_fputts(messageBox, stdout);
	}

	CloseHandle(hMailSlot);
	return 0;

}