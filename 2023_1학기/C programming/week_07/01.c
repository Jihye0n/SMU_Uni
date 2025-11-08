// 업다운 게임 (예측 문제 맞추기, random 함수)

// int : 명령어, rand() : 함수
#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <stdlib.h> // 프로그램 시작 전 rand() 함수 포함
#include <Windows.h> // 프로그램 시작 전 Sleep() 함수 포함

void main() // 프로그램 시작 점
{
	int com = 0, usr = 0, i = 0, t = 0, count = 0; // 정수형 메모리 com, usr, i, t, count 를 만들고 0으로 초기화

	printf("업다운 게임입니다. (기회는 10번) \n"); // "업다운 게임입니다." 를 출력
	printf("컴퓨터가 하나의 숫자를 생성중입니다. \n"); // "컴퓨터가 하나의 숫자를 생성중입니다." 를 출력

	for (i = 0; i < 10; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 10이 되면 반복 종료
	{
		printf("■"); // "■" 출력
		Sleep(100); // 딜레이
	}

	t = time(NULL); // t에 1970년 1월 1일 0시 0분 부터 현재까지의 시간(초)을 대입
	// t = time(NULL) ^ 3; // t를 암호화

	srand(t); // srand에 t를 넣어줌으로써 rand의 시드가 계속 바뀐다.
	// printf("t is %d \n", t); // t값을 출력

	com = (rand() % 100) + 1; // 1에서 100까지의 랜덤숫자를 com에 대입
	/*
	for (i = 0; i < 6; i = i + 1)
	{
		com = (rand() % 100) + 1;
		printf("com is %d \n", com);
	}
	*/

	printf("\n"); // 다음줄
	while (1) // 0이외의 다른 수 이기 때문에 무한 반복
	{
		// 숫자 입력받기
		printf("1 ~ 100까지의 숫자를 입력하세요 : "); // "1 ~ 100까지의 숫자를 입력하세요 : " 를 출력
		scanf_s("%d", &usr); // 정수를 입력받아 usr의 메모리 주소로 배달
		count = count + 1; // count에 1을 증가
		// printf("%d", count);

		// 열번 입력할 때
		if (count == 10) // count의 값이 10이 되면
		{
			printf("10번이 넘었습니다. 다음에 다시 도전하세요,"); // "10번이 넘었습니다.다음에 다시 도전하세요," 를 출력
			break; // while 반복문에서 빠져나옴
		}

		// 잘못된 숫자 입력
		if (usr > 100 || usr == 0) // usr의 값이 100이 넘거나 0 이면
		{
			printf("0 혹은 100 초과의 숫자입니다. \n"); // "0 혹은 100 초과의 숫자입니다." 를 출력
			continue; // 반복문 처음으로 돌아가기
		}

		// 정답
		if (usr == com) // usr의 값과 com의 값이 같으면
		{
			printf("정답입니다! \n"); // "정답입니다!"를 출력
			printf("%d번 만에 맞추셨습니다.", count); // count의 값을 출력
			break; // while 반복문에서 빠져나옴
		}

		// 업
		if (usr < com) // usr의 값이 com의 값보다 작으면
		{
			printf("업 \n"); // "업"을 출력
			continue; // 반복문 처음으로 돌아가기
		}

		// 다운
		if (usr > com) // usr의 값이 com의 값보다 크면
		{
			printf("다운 \n"); // "다운"을 출력
			continue; // 반복문 처음으로 돌아가기
		}
	}
}