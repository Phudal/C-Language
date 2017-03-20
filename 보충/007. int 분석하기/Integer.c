#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <float.h>

int main()
{
	// 8비트 컴퓨터 시스템
	puts("<8비트 컴퓨터 시스템에서의 int와 unsigned int>");
	printf("int의 최솟값 : %+d\nint의 최댓값 : %+d\n", INT8_MIN, INT8_MAX);
	printf("int를 인식하는 범위 : %+d ~ %+d\n", INT_LEAST8_MIN, INT_LEAST8_MAX);
	printf("int에 최적화된 범위 : %+d ~ %+d\n", INT_FAST8_MIN, INT_FAST8_MAX);
	printf("unsigned int의 최댓값 : %u\n", UINT8_MAX);
	printf("unsigned int를 인식하는 범위 : 0 ~ %u\n", UINT_LEAST8_MAX);
	printf("unsigned int에 최적화된 범위 : 0 ~ %u\n", UINT_FAST8_MAX);
	puts("----------------------------------------------");

	// 16비트 컴퓨터 시스템
	puts("<16비트 컴퓨터 시스템에서의 int와 unsigned int>");
	printf("int의 최솟값 : %+d\nint의 최댓값 : %+d\n", INT16_MIN, INT16_MAX);
	printf("int를 인식하는 범위 : %+d ~ %+d\n", INT_LEAST16_MIN, INT_LEAST16_MAX);
	printf("int에 최적화된 범위 : %+d ~ %+d\n", INT_FAST16_MIN, INT_FAST16_MAX);
	printf("unsigned int의 최댓값 : %u\n", UINT16_MAX);
	printf("unsigned int를 인식하는 범위 : 0 ~ %u\n", UINT_LEAST16_MAX);
	printf("unsigned int에 최적화된 범위 : 0 ~ %u\n", UINT_FAST16_MAX);
	puts("----------------------------------------------");

	// 32비트 컴퓨터 시스템
	puts("<32비트 컴퓨터 시스템에서의 int와 unsigned int>");
	printf("int의 최솟값 : %+d\nint의 최댓값 : %+d\n", INT32_MIN, INT32_MAX);
	printf("int를 인식하는 범위 : %+d ~ %+d\n", INT_LEAST32_MIN, INT_LEAST32_MAX);
	printf("int에 최적화된 범위 : %+d ~ %+d\n", INT_FAST32_MIN, INT_FAST32_MAX);
	printf("unsigned int의 최댓값 : %u\n", UINT32_MAX);
	printf("unsigned int를 인식하는 범위 : 0 ~ %u\n", UINT_LEAST32_MAX);
	printf("unsigned int에 최적화된 범위 : 0 ~ %u\n", UINT_FAST32_MAX);
	puts("----------------------------------------------");

	// 64비트 컴퓨터 시스템
	puts("<64비트 컴퓨터 시스템에서의 int와 unsigned int>");
	printf("int의 최솟값 : %+lld\nint의 최댓값 : %+lld\n", INT64_MIN, INT64_MAX);
	printf("int를 인식하는 범위 : %+lld ~ %+lld\n", INT_LEAST64_MIN, INT_LEAST64_MAX);
	printf("int에 최적화된 범위 : %+lld ~ %+lld\n", INT_FAST64_MIN, INT_FAST64_MAX);
	printf("unsigned int의 최댓값 : %llu\n", UINT64_MAX);
	printf("unsigned int를 인식하는 범위 : 0 ~ %llu\n", UINT_LEAST64_MAX);
	printf("unsigned int에 최적화된 범위 : 0 ~ %llu\n", UINT_FAST64_MAX);

	int64_t
	return 0;
}