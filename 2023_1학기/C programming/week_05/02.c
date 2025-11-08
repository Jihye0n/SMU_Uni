// 영단어를 입력받아 카이사르, XOR 암호문 만드는 프로그램

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작점
{
	char ch = 0, i = 0, key = 5; // 문자형 변수 ch, i, key를 만들고 ch, i에는 0으로 초기화 key에는 5를 대입
	char str[20] = ""; // str 0 ~ 19까지 20개를 만들고 0로 모두 초기화(스택 메모리에 순서대로 20개를 만든다.)

	printf("영단어 입력 : "); // "영단어 입력 : "을 출력
	scanf_s("%s", &str[0], sizeof(str)); //문자열을 입력 받아서 (공백과 엔터키를 받을때까지) 0번째 메모리 주소로 배달 (\0를 넣음)
	//gets_s(&str[0]);
	printf("str is %s \n", &str[0]); // str주소를 출력 (\0를 만나면 그만둔다.)

	//카이사르
	for (i = 0; i <= 19; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 19 이상이 될 때 까지 반복 -> (4) i에 1을 증가
	{
		if (str[i] == '\0') // (3) str의 문자가 \0과 같아지면
			break; // 프로그램 종료

		str[i] = str[i] + key; // str의 문자마다 key의 값(5)을 증가
	}
	printf("카이사르 암호문 is %s \n", &str[0]); // str주소를 출력

	for (i = 0; i <= 19; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 19 이상이 될 때 까지 반복 -> (4) i에 1을 증가
	{
		if (str[i] == '\0') // (3) str의 문자가 \0과 같아지면
			break; // 프로그램 종료

		str[i] = str[i] - key; // str의 문자마다 key의 값(5)을 감소
	}
	printf("카이사르 원문 is %s \n", &str[0]); // str주소를 출력

	// XOR
	for (i = 0; i <= 19; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 19 이상이 될 때 까지 반복 -> (4) i에 1을 증가
	{
		if (str[i] == '\0') // (3) str의 문자가 \0과 같아지면
			break; // 프로그램 종료

		str[i] = str[i] ^ key; // str의 문자마다 key값을 XOR 연산
	}
	printf("XOR 암호문 is %s \n", &str[0]); // str주소를 출력

	for (i = 0; i <= 19; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 19 이상이 될 때 까지 반복 -> (4) i에 1을 증가
	{
		if (str[i] == '\0') // (3) str의 문자가 \0과 같아지면
			break; // 프로그램 종료

		str[i] = str[i] ^ key; // str의 문자마다 key값을 XOR 연산
	}
	printf("XOR 원문 is % s \n", &str[0]); // str주소를 출력
}