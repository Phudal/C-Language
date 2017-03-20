#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>      // 윈도우에만 존재
#include <windows.h> // 윈도우에만 존재
#include "FileIO.h"

typedef enum _State
{
	PLAY, STOP
}STATE;

double CheckTime(LARGE_INTEGER *pLastTime, LARGE_INTEGER *pNowTime, LARGE_INTEGER *pFrequnecy)
{
	double dTimeInterval;

	// 시작 시간, 마이크로초 구하기
	// 1초 = 1000밀리초 = 1000000마이크로초
	QueryPerformanceCounter(pNowTime);

	dTimeInterval =
		((double)(pNowTime->QuadPart - pLastTime->QuadPart) / (double)pFrequnecy->QuadPart);
	pLastTime->QuadPart = pNowTime->QuadPart;
	return dTimeInterval;
}

int main(int argc, char *argv[])
{
	char   Buffer[500];
	char   cLF;
	char   FindPath[100];
	int    iResult = 0;
	double dResult = 0.0; // 복합 할당 연산자를 사용하려면 초기화 필수!
	STATE  eState = PLAY;
	FILE   *pASCIIArt = NULL;
	intptr_t FileHandle; // 4바이트와 8바이트 전환
	LARGE_INTEGER LastTime, NowTime, Frequnecy;
	COORD CursorPos = {0, 0};
	struct _finddata_t FindASCIIArt;

	// 현재 시스템이 측정할 수 있는 초당 주파수 구하기
	// 현재 시스템 측정 결과 3320337 => 주파수가 3320337이 되면 1초
	QueryPerformanceFrequency(&Frequnecy);

	QueryPerformanceCounter(&LastTime); // 측정할 시간 초기화

	while (1)
	{
		strcpy(FindPath, argv[1]);
		strcat(FindPath, "\\*.txt");

		FileHandle = _findfirst(FindPath, &FindASCIIArt);

		if (FileHandle == -1)
		{
			perror("파일 핸들 가져오기 실패!");
			return 0;
		}

		iResult = 0; // iResult 초기화

		// 폴더 검색
		while (iResult != -1)
		{
			if (eState == PLAY)
			{
				strcpy(FindPath, argv[1]);
				strcat(FindPath, "\\");
				strcat(FindPath, FindASCIIArt.name);

				ByRuvendixOpenFile(&pASCIIArt, FindPath, "rt");

				// 문서 파일 검색
				while (feof(pASCIIArt) == 0)
				{
					fscanf(pASCIIArt, "%[^\n]s", Buffer);
					fscanf(pASCIIArt, "%c", &cLF);
					puts(Buffer);
				}

				ByRuvendixCloseFile(pASCIIArt);
				eState = STOP;
			}

			// 프레임 시간 측정
			dResult += CheckTime(&LastTime, &NowTime, &Frequnecy);

			if (dResult >= 1.0 / 14.0)
			{
				dResult = 0.0; // 측정 시간 초기화
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

				// 모든 작업이 끝난 후 다음 파일을 찾음
				iResult = _findnext(FileHandle, &FindASCIIArt);

				eState = PLAY;
			}
		}
		_findclose(FileHandle);
	}
	return 0;
}
