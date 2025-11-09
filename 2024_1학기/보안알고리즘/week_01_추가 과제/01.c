// 시저 암호를 분석하여 평문과 키를 찾는 프로그램 (C언어)

#include <stdio.h>

void main()
{
	char code[20] = "CSYEVIXIVQMREXIH"; // 암호문 변수 선언, 기본 암호문 대입
	int shift = 0; // 키 값 입력받을 변수 선언, 초기화

	while (1)
	{
		printf("키 값 입력 (0 ~ 25 까지 입력) : ");
		scanf_s("%d", &shift); // 키 값 입력
		if (shift >= 0 && shift <= 25) // 0 ~ 25 사이의 숫자인 경우
			break; // 멈춤
		printf("! 키 값 잘못 입력 ! \n");
	}

	printf("\n * 키 n = %d 인 경우 \n", shift); // 키 값 출력
	printf("암호문 : %s \n", code); // 암호문 출력
	printf("------------------------------------------------------------ \n");

	printf("과정 1 : ");
	for (int i = 0; code[i] != '\0'; ++i)
	{
		printf("%d ", code[i]); // 기본 암호문 아스키코드의 문자를 숫자로 변환
		if (code[i] >= 'A' && code[i] <= 'Z') // 기본 암호문의 문자가 A ~ Z 사이의 숫자인 경우
			code[i] = (code[i] - 'A' - shift + 26) % 26 + 'A'; // 키 값 만큼 복호화
	}

	printf("\n");
	printf("과정 2 : ");
	for (int i = 0; code[i] != '\0'; ++i)
	{
		printf("%d ", code[i]); // 복호화된 암호문 아스키코드의 문자를 숫자로 변환
		if (code[i] >= 'A' && code[i] <= 'Z') // 복호화된 암호문의 문자가 A ~ Z 사이의 숫자인 경우
			code[i] += 32; // 대문자에서 소문자로 변경
	}
	printf("\n분석문 : %s \n", code); // 결과 출력
}