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
	wchar_t  InitBuff[MAX_STRING]; // ���� ������
	wchar_t* pwszStr = wszStr;

	SetUnicode();

	wprintf(L"N-Gram�� ���� ���� �Է����ּ��� : ");
	wscanf(L"%d", &iGram);

	wprintf(L"���� ���� %d�� �����Ǿ����ϴ�.\n", iGram);
	_putws(L"-------------------------------------");
	
	setbuf(stdin, InitBuff);
	wprintf(L"�ƹ� ���ڿ��̳� �Է����ּ��� : ");
	_getws(wszStr);

	wprintf(L"�Էµ� ���ڿ��� %s�Դϴ�.\n", wszStr);
	_putws(L"-------------------------------------");
	iLength = wcslen(wszStr);

	if (iGram > iLength)
	{
		_putws(L"�Էµ� ���ڿ��� N-Gram���� �۽��ϴ�.");
	}
	else
	{
		_putws(L"�Էµ� ���ڿ��� N-Gram�� �Ǵ��մϴ�.");
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
