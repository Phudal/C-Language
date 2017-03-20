#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_STRING 40

typedef enum tagMatch
{
	MATCH_FALSE = 0,
	MATCH_TRUE  = 1,
}MATCH;

void SetUnicode()
{
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, "korean");
}

int main()
{
	MATCH eResult;
	int iStart, iEnd;
	wchar_t wszBuffer[MAX_STRING];

	SetUnicode();

	wprintf(L"�˻��� ���ڿ��� �Է��ϼ��� : ");
	_getws(wszBuffer);
	wcsupr(wszBuffer); // ���� ��ҹ��� ����
	iEnd = wcslen(wszBuffer) - 1;

	for (iStart = 0; iStart < iEnd; ++iStart)
	{
		if (wszBuffer[iStart] != wszBuffer[iEnd])
		{
			if (wszBuffer[iStart] == L' ') // ������ ���ʿ� �ִ� ���
			{
				// ������ ���� �ε����� iStart�� �ڵ� ����
				continue;
			}
			else if (wszBuffer[iEnd] == L' ') // ������ �����ʿ� �ִ� ���
			{
				// ������ �ε����� �ϳ� ������
				// �ڵ� ���� ������ ���� iStart�� �ϳ� ����
				--iStart;
				--iEnd;
				continue;
			}
			else
			{
				eResult = MATCH_FALSE;
				break;
			}
		}
		else
		{
			eResult = MATCH_TRUE;
		}
		--iEnd;
	}

	if (eResult == MATCH_TRUE)
	{
		_putws(L"�� ���ڿ��� ȸ���Դϴ�.");
	}
	else
	{
		_putws(L"�� ���ڿ��� ȸ���� �ƴմϴ�.");
	}
	return 0;
} 
