// 1~100 사이의 정수 중에서 짝수의 합을 구하여 화면에 출력하는 프로그램

#include <stdio.h> // 프로그램 시작전 표준입출력 함수 포함

void main() // 프로그램 시작점
{
	int evensum = 0, i = 1; // 정수형 메모리 evensum, i를 만들고 evensum을 0으로 초기화 i는 1로 초기화

	for (i = 2; i <= 100; i = i + 2) // (1) i에 2를 대입 -> (2) i가 100이상이 될때까지 반복 -> (4) i에 2씩 증가
	{
		evensum = evensum + i; // (3) i가 100보다 적으면 evensum에 + i
	}

	printf("evensum is %d \n", evensum); // i가 100이상 되면 evensum 을 출력
}