#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <float.h>

int main()
{
	// 8��Ʈ ��ǻ�� �ý���
	puts("<8��Ʈ ��ǻ�� �ý��ۿ����� int�� unsigned int>");
	printf("int�� �ּڰ� : %+d\nint�� �ִ� : %+d\n", INT8_MIN, INT8_MAX);
	printf("int�� �ν��ϴ� ���� : %+d ~ %+d\n", INT_LEAST8_MIN, INT_LEAST8_MAX);
	printf("int�� ����ȭ�� ���� : %+d ~ %+d\n", INT_FAST8_MIN, INT_FAST8_MAX);
	printf("unsigned int�� �ִ� : %u\n", UINT8_MAX);
	printf("unsigned int�� �ν��ϴ� ���� : 0 ~ %u\n", UINT_LEAST8_MAX);
	printf("unsigned int�� ����ȭ�� ���� : 0 ~ %u\n", UINT_FAST8_MAX);
	puts("----------------------------------------------");

	// 16��Ʈ ��ǻ�� �ý���
	puts("<16��Ʈ ��ǻ�� �ý��ۿ����� int�� unsigned int>");
	printf("int�� �ּڰ� : %+d\nint�� �ִ� : %+d\n", INT16_MIN, INT16_MAX);
	printf("int�� �ν��ϴ� ���� : %+d ~ %+d\n", INT_LEAST16_MIN, INT_LEAST16_MAX);
	printf("int�� ����ȭ�� ���� : %+d ~ %+d\n", INT_FAST16_MIN, INT_FAST16_MAX);
	printf("unsigned int�� �ִ� : %u\n", UINT16_MAX);
	printf("unsigned int�� �ν��ϴ� ���� : 0 ~ %u\n", UINT_LEAST16_MAX);
	printf("unsigned int�� ����ȭ�� ���� : 0 ~ %u\n", UINT_FAST16_MAX);
	puts("----------------------------------------------");

	// 32��Ʈ ��ǻ�� �ý���
	puts("<32��Ʈ ��ǻ�� �ý��ۿ����� int�� unsigned int>");
	printf("int�� �ּڰ� : %+d\nint�� �ִ� : %+d\n", INT32_MIN, INT32_MAX);
	printf("int�� �ν��ϴ� ���� : %+d ~ %+d\n", INT_LEAST32_MIN, INT_LEAST32_MAX);
	printf("int�� ����ȭ�� ���� : %+d ~ %+d\n", INT_FAST32_MIN, INT_FAST32_MAX);
	printf("unsigned int�� �ִ� : %u\n", UINT32_MAX);
	printf("unsigned int�� �ν��ϴ� ���� : 0 ~ %u\n", UINT_LEAST32_MAX);
	printf("unsigned int�� ����ȭ�� ���� : 0 ~ %u\n", UINT_FAST32_MAX);
	puts("----------------------------------------------");

	// 64��Ʈ ��ǻ�� �ý���
	puts("<64��Ʈ ��ǻ�� �ý��ۿ����� int�� unsigned int>");
	printf("int�� �ּڰ� : %+lld\nint�� �ִ� : %+lld\n", INT64_MIN, INT64_MAX);
	printf("int�� �ν��ϴ� ���� : %+lld ~ %+lld\n", INT_LEAST64_MIN, INT_LEAST64_MAX);
	printf("int�� ����ȭ�� ���� : %+lld ~ %+lld\n", INT_FAST64_MIN, INT_FAST64_MAX);
	printf("unsigned int�� �ִ� : %llu\n", UINT64_MAX);
	printf("unsigned int�� �ν��ϴ� ���� : 0 ~ %llu\n", UINT_LEAST64_MAX);
	printf("unsigned int�� ����ȭ�� ���� : 0 ~ %llu\n", UINT_FAST64_MAX);

	int64_t
	return 0;
}