
extern void PrintGood();

// ��� ���̺�� ����
typedef void(* CALLBACK)();
CALLBACK CallBack[4];

int EnrollFunc(const CALLBACK EnrollFunc)
{
	static int iFuncCnt = 0;
	CallBack[iFuncCnt] = EnrollFunc;
	return ++iFuncCnt;
}

void StartFunc(const int iFuncCnt)
{
	int i;
	CALLBACK a = PrintGood;
	for (i = 0; i < iFuncCnt; ++i)
	{
		// �ݹ� �Լ� ȣ��
		a();
		//CallBack[0]();
		//good[i] = i;
		//CallBack[i]();
	}
	puts("");
	//PrintGood();
} 
