#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_STRING 40

typedef enum tagGram
{
	GRAM_CONTINUE = 0,
	GRAM_END      = 1,
}GRAM;

void SetUnicode()
{
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, "korean");
}

int main()
{
	int i, j;
	int iGram;
	int iLength;
	GRAM eGram = GRAM_CONTINUE;
	wchar_t  wszStr[MAX_STRING];
	wchar_t  InitBuff[MAX_STRING]; // 버퍼 삭제용
	wchar_t* pwszStr = wszStr;

	SetUnicode();

	wprintf(L"N-Gram의 기준 수를 입력해주세요 : ");
	wscanf(L"%d", &iGram);

	wprintf(L"기준 수가 %d로 설정되었습니다.\n", iGram);
	_putws(L"-------------------------------------");
	
	setbuf(stdin, InitBuff);
	wprintf(L"아무 문자열이나 입력해주세요 : ");
	_getws(wszStr);

	wprintf(L"입력된 문자열은 %s입니다.\n", wszStr);
	_putws(L"-------------------------------------");
	iLength = wcslen(wszStr);

	if (iGram > iLength)
	{
		_putws(L"입력된 문자열이 N-Gram보다 작습니다.");
	}
	else
	{
		_putws(L"입력된 문자열로 N-Gram을 판단합니다.");
		_putws(L"-------------------------------------");
	}

	for (i = 0; i < iLength; ++i)
	{
		for (j = 0; j < iGram; ++j)
		{
			if (pwszStr[j] == L'\0')
			{
				eGram = GRAM_END;
			}
		}

		if (eGram == GRAM_CONTINUE)
		{
			for (j = 0; j < iGram; ++j)
			{
				putwchar(pwszStr[j]);
			}
			pwszStr++;
			_putws(L"");
		}
	}
	return 0;
} 
