// 정수를 입력 받아 홀수, 짝수 , 소수  구분하는 프로그램

#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함

void main() // 프로그램 시작 점
{
	int num = 0, oddCnt = 0, evenCnt = 0, primeCnt = 0, flag = 0, i = 0; // 정수형 메모리 num, oddCnt, evenCnt, primeCnt, flag, i를 만들고 모두 0으로 초기화
	while (1) // 0 이외의 다른 값 이기 때문에 무한 반복
	{
		printf("정수 입력 : "); // "정수 입력 : "을 출력
		scanf_s("%d", &num); // 정수를 입력받아 num의 주소로 배달
		printf("num is %d \n", num); // num의 값을 출력

		if (num <= 0) // num의 값이 0 이거나 음수이면
			break; // 프로그램 종료

		// 홀수 확인
		if (num % 2 != 0) // num의 값을 2로 나누었을 때 나누어 떨어지지 않으면
			oddCnt = oddCnt + 1; // oddCnt에 1을 증가
		// printf("odd : %d \n",oddCnt);

		// 짝수 확인
		if (num % 2 == 0) // num의 값을 2로 나누었을 때 나누어 떨어지면
			evenCnt = evenCnt + 1; // evenCnt에 1을 증가
		// printf("even : %d \n",evenCnt);

		// 소수 확인
		for (i = 1; i <= num; i = i + 1) // (1) i에 1을 대입 -> (2) i의 값이 num의 값의 이상이 될 때 까지 반복 -> (4) i에 1을 증가
		{
			if (num % i == 0) // (3) num의 값을 i로 나누었을 때 나누어 떨어지면
				flag = flag + 1; // flag에 1을 증가
			if (flag >= 3) // flag의 값이 3 이상이면
				break; // 프로그램 종료
		}

		if (flag == 2) // flag의 값이 2와 같으면
			primeCnt = primeCnt + 1; // primeCnt에 1을 증가
		flag = 0; // flag의 값을 0으로 초기화

		printf("odd : %d even : %d prime : %d \n", oddCnt, evenCnt, primeCnt); // oddCnt, evenCnt, primeCnt의 값을 출력
	}
}