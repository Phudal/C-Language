
extern void PrintGood();

// 룩업 테이블로 관리
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
		// 콜백 함수 호출
		a();
		//CallBack[0]();
		//good[i] = i;
		//CallBack[i]();
	}
	puts("");
	//PrintGood();
} 
