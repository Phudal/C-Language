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

	wprintf(L"검사할 문자열을 입력하세요 : ");
	_getws(wszBuffer);
	wcsupr(wszBuffer); // 영어 대소문자 방지
	iEnd = wcslen(wszBuffer) - 1;

	for (iStart = 0; iStart < iEnd; ++iStart)
	{
		if (wszBuffer[iStart] != wszBuffer[iEnd])
		{
			if (wszBuffer[iStart] == L' ') // 공백이 왼쪽에 있는 경우
			{
				// 어차피 왼쪽 인덱스는 iStart라서 자동 증가
				continue;
			}
			else if (wszBuffer[iEnd] == L' ') // 공백이 오른쪽에 있는 경우
			{
				// 오른쪽 인덱스는 하나 내리고
				// 자동 증가 방지를 위해 iStart도 하나 내림
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
		_putws(L"이 문자열은 회문입니다.");
	}
	else
	{
		_putws(L"이 문자열은 회문이 아닙니다.");
	}
	return 0;
} 
