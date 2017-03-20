#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>      // �����쿡�� ����
#include <windows.h> // �����쿡�� ����
#include "FileIO.h"

typedef enum _State
{
	PLAY, STOP
}STATE;

double CheckTime(LARGE_INTEGER *pLastTime, LARGE_INTEGER *pNowTime, LARGE_INTEGER *pFrequnecy)
{
	double dTimeInterval;

	// ���� �ð�, ����ũ���� ���ϱ�
	// 1�� = 1000�и��� = 1000000����ũ����
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
	double dResult = 0.0; // ���� �Ҵ� �����ڸ� ����Ϸ��� �ʱ�ȭ �ʼ�!
	STATE  eState = PLAY;
	FILE   *pASCIIArt = NULL;
	intptr_t FileHandle; // 4����Ʈ�� 8����Ʈ ��ȯ
	LARGE_INTEGER LastTime, NowTime, Frequnecy;
	COORD CursorPos = {0, 0};
	struct _finddata_t FindASCIIArt;

	// ���� �ý����� ������ �� �ִ� �ʴ� ���ļ� ���ϱ�
	// ���� �ý��� ���� ��� 3320337 => ���ļ��� 3320337�� �Ǹ� 1��
	QueryPerformanceFrequency(&Frequnecy);

	QueryPerformanceCounter(&LastTime); // ������ �ð� �ʱ�ȭ

	while (1)
	{
		strcpy(FindPath, argv[1]);
		strcat(FindPath, "\\*.txt");

		FileHandle = _findfirst(FindPath, &FindASCIIArt);

		if (FileHandle == -1)
		{
			perror("���� �ڵ� �������� ����!");
			return 0;
		}

		iResult = 0; // iResult �ʱ�ȭ

		// ���� �˻�
		while (iResult != -1)
		{
			if (eState == PLAY)
			{
				strcpy(FindPath, argv[1]);
				strcat(FindPath, "\\");
				strcat(FindPath, FindASCIIArt.name);

				ByRuvendixOpenFile(&pASCIIArt, FindPath, "rt");

				// ���� ���� �˻�
				while (feof(pASCIIArt) == 0)
				{
					fscanf(pASCIIArt, "%[^\n]s", Buffer);
					fscanf(pASCIIArt, "%c", &cLF);
					puts(Buffer);
				}

				ByRuvendixCloseFile(pASCIIArt);
				eState = STOP;
			}

			// ������ �ð� ����
			dResult += CheckTime(&LastTime, &NowTime, &Frequnecy);

			if (dResult >= 1.0 / 14.0)
			{
				dResult = 0.0; // ���� �ð� �ʱ�ȭ
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos);

				// ��� �۾��� ���� �� ���� ������ ã��
				iResult = _findnext(FileHandle, &FindASCIIArt);

				eState = PLAY;
			}
		}
		_findclose(FileHandle);
	}
	return 0;
}
