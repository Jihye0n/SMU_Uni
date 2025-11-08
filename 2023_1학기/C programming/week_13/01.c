// 한글타자 단문 연습 프로그램 + 지금까지 모든 프로그램을 하나의 프로그램으로 메뉴 처리하여 프로그램 완성

// 문장을 읽을때는 gets를 사용 단어를 읽을 때는 scanf를 사용
#define _CRT_SECURE_NO_WARNINGS // 안전하지 않아도 프로그램을 돌린다.
#include <stdio.h> // 프로그램 시작 전 표준 입출력 함수 포함
#include <Windows.h> // 프로그램 시작 전 Sleep() 함수 포함
#include <stdlib.h> // 프로그램 시작 전 rand() 함수 포함

int menu() // int는 함수가 끝나고 반환되는 정수 1개의 값이 있다.
{
	int n = 0; // 지역변수이다. // 정수형 메모리 n을 만들고 0으로 초기화

	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("이 프로그램은 제가 만든 프로그램입니다.\ n"); // "이 프로그램은 제가 만든 프로그램입니다."를 출력
	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("1. 파일 암호화 \n"); // "1. 파일 암호화"를 출력
	printf("2. 파일 복호화 \n"); // "2. 파일 복호화"를 출력
	printf("3. 한글 단문 연습 프로그램 \n"); // "3. 한글 단문 연습 프로그램"을 출력
	printf("4. 업 다운 게임 프로그램 \n"); // "4. 업 다운 게임 프로그램"을 출력
	printf("5. 야구 게임 프로그램 \n"); // "5. 야구 게임 프로그램"을 출력
	printf("6. 소수 판단 프로그램 \n"); // "6. 소수 판단 프로그램"을 출력
	printf("7. 같은 단어 확인 프로그램 \n"); // "7. 같은 단어 확인 프로그램"을 출력
	printf("8. 10명의 성적 프로그램 \n"); // "8. 10명의 성적 프로그램"을 출력
	printf("9. 10명의 이름 오름차순, 내림차순 정렬 프로그램 \ n"); // "9. 10명의 이름 오름차순, 내림차순 정렬 프로그램"을 출력
	printf("10. 시, 분, 초 -> 초 바꾸는 프로그램 \n"); // "10. 시, 분, 초 -> 초 바꾸는 프로그램"을 출력
	printf("11. 파일의 단어의 개수와 최대길이 구하는 프로그램 \ n"); // "11. 파일의 단어의 개수와 최대길이 구하는 프로그램"을 출력
	printf("12. 프로그램 종료 \n"); // "12. 프로그램 종료"를 출력
	printf("--------------------------------------\n"); // "--------------------------------------" 출력
	printf("메뉴를 선택하세요 : "); // "메뉴를 선택하세요 : "를 출력
	scanf("%d", &n); // 입력받은 정수가 n의 메모리 주소로 배달
	getchar(); // 엔터키가 여기로 들어간다
	return n; // n의 값이 menu로 들어간다
}
// 파라미터 패싱

void encrypt() // void는 함수가 끝나고 반환되는 값이 없다.
{
	unsigned char fname[256] = "", sname[256] = "", data = 0; // 문자열 메모리 fname, sname, data를 만들고 모두 0으로 초기화
	int key = 0; // 정수형 메모리 key를 만들고 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(fname); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	printf("암호 키 값을 입력하세요 : "); // "암호 키 값을 입력하세요 : "를 출력
	scanf("%d", &key); // 입력받은 정수를 key의 메모리 주소로 배달

	FILE* fp_in = fopen(fname, "rb"); // 파일이 저장된 주소, fname의 파일을 read 바이너리 모드로 열어서 fp_in에 대입
	FILE* fp_out = fopen(sname, "wb"); // sname의 파일을 write 바이너리 모드로 열어서 파일을 생성하고 fp_out에 대입

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp_in == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		fread(&data, sizeof(char), 1, fp_in); // fp_in에서 1바이트[sizeof(char)] 하나를 읽어서 data에 배달
		data = data ^ key; // 암호화 처리
		// fp가 끝인지 아닌지 확인
		if (feof(fp_in)) // fp_in이 끝이라면
			break; // 반복문 종료
		fwrite(&data, sizeof(char), 1, fp_out); // data에 있는 1바이트[sizeof(char)] 하나를 fp_out에 쓴다
	}
	printf("%s ---> %s 파일로 암호화 처리되었습니다. \n", fname, sname); // 암호화 처리 안내문 출력

	// 파일 닫기
	fclose(fp_in); // fp_in 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}

void decrypt() // void는 함수가 끝나고 반환되는 값이 없다.
{
	unsigned char fname[256] = "", sname[256] = "", data = 0; // 문자열 메모리 fname, sname, data를 만들고 모두 0으로 초기화
	int key = 0; // 정수형 메모리 key를 만들고 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(fname); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	printf("암호 키 값을 입력하세요 : "); // "암호 키 값을 입력하세요 : "를 출력
	scanf("%d", &key); // 입력받은 정수를 key의 메모리 주소로 배달

	FILE* fp_in = fopen(fname, "rb"); // 파일이 저장된 주소, fname의 파일을 read 바이너리 모드로 열어서 fp_in에 대입
	FILE* fp_out = fopen(sname, "wb"); // sname의 파일을 write 바이너리 모드로 열어서 파일을 생성하고 fp_out에 대입

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp_in == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		fread(&data, sizeof(char), 1, fp_in); // fp_in에서 1바이트[sizeof(char)] 하나를 읽어서 data에 배달
		data = data ^ key; // 복호화 처리
		// fp가 끝인지 아닌지 확인
		if (feof(fp_in)) // fp_in이 끝이라면
			break; // 반복문 종료
		fwrite(&data, sizeof(char), 1, fp_out); // data에 있는 1바이트[sizeof(char)] 하나를 fp_out에 쓴다
	}
	printf("%s ---> %s 파일로 복호화 처리되었습니다. \n", fname, sname); // 복호화 처리 안내문 출력

	// 파일 닫기
	fclose(fp_in); // fp_in 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}

void short_test() // void는 함수가 끝나고 반환되는 값이 없다.
{
	// wordshort.txt 단문 길이 및 최대 길이 측정
	char wordDB[1261][77] = { "" }, ans[77] = ""; // 문자열 메모리 wordDB, ans를 만들고 모두 0으로 초기화
	int strCount = 0, max = 0, len = 0, choice = 0, score = 0, cur = 0, avg = 0, inputCnt = 0; // 정수형 메모리 strCount, max, len, choice, score, cur, avg, inputCnt를 만들고 모두 0으로 초기화
	unsigned int start_t = 0, end_t = 0, total_t = 0, total_len = 0; // 정수형 메모리 start_t, end_t, total_t, total_len을 만들고 모두 0으로 초기화
	FILE* fp = fopen("wordshort.txt", "rt"); // 파일이 저장된 주소, wordshort.txt 파일을 read text모드로 열어서 fp에 대입

	while (1) // 0 이외의 수이기 때문에 무한 반복
	{
		fgets(&wordDB[strCount][0], sizeof(wordDB[strCount]), fp); // fp가 가리키는 파일에서 한 줄씩 주소를 받아 온다.
		len = strlen(wordDB[strCount]); // 문자열(wordDB[strCount])의 길이를 측정해서 len에 대입

		// 마지막 앞에 엔터키가 들어가있어서 엔터키가 날려야 한다. ( fgets는 엔터키도 입력)
		wordDB[strCount][len - 1] = '\0'; // wordDB 마지막 문자 바로 앞에 '\0'을 대입
		// 최대값 구하기
		if (len > max) max = len; // len이 max보다 크다면 len을 max에 대입
		// printf("%s : %d, %d", wordDB[strCount], len, max);
		strCount++; // strCount에 1을 증가
		// getch();
		if (feof(fp)) break; // fp가 끝이라면 반복문 종료
	}
	// printf("strCount is %d, max length is %d \n", strCount, max);

	for (int i = 0; i < strCount; i++) // i에 0을 대입하고 1씩 증가하면서 strCount가 되면 반복 종료
	{
		printf("%s", wordDB[i]); // wordDB[i] 출력
	}
	fclose(fp); // fp 파일 닫기

	// 1261개 문장중 하나의 문장을 선택
	srand(time(NULL)); // 1970년 1월 1일 0시 0분 부터 현재까지의 시간(초)을 대입
	choice = rand() % strCount; // 1에서 1261까지의 랜덤숫자를 choice에 대입

	while (1) // 0 이외의 수이기 때문에 무한 반복
	{
		system("cls"); // 화면 지우기
		printf("한글 단문 연습 프로그램입니다. 프로그램을 종료하시려면 \"종료\"를 입력하세요 \n"); // "한글 단문 연습 프로그램입니다. 프로그램을 종료하시려면 "종료"를 입력하세요"를 출력
		printf("점수 : %d, 현재 타수 : %d, 평균 타수 : %d \n", score, cur, avg); // score, cur, avg의 값을 출력
		printf("----------------------------------------- \n"); // "----------------------------------------- " 출력
		printf("%s \n", wordDB[choice]); // wordDB[choice] 출력 // while (!kbhit()) {} // 키보드가 눌러지지 않으면 계속 무한루프, 키보드가 입력되면 1이 들어감
		start_t = time(NULL); // 시작시간
		gets(&ans[0]); // 입력
		end_t = time(NULL); // 종료시간
		len = strlen(ans); // ans의 길이를 측정해서 len에 대입

		total_t = total_t + (end_t - start_t); // 전체 입력 시간 구하기
		total_len = total_len + len; // 전체 입력 글자 수 구하기
		inputCnt++; // inputCnt에 1씩 증가
		// printf("소요시간 %d, len is %d \n", end_t - start_t, len);
		// Sleep(1000);

		// printf("%d, %d \n", strlen(wordDB[choice]), strlen(ans));

		if (strcmp(ans, "종료") == 0) break; // 종료라고 넣으면 while문 빠져나간다.
		if (strcmp(ans, wordDB[choice]) == 0) // ans와 wordDB[choice] 비교했을 때 같으면
		{
			printf("정답입니다. \n"); // "정답입니다."를 출력
			choice = rand() % strCount; // 랜덤으로 문장 선택, 1에서 1261까지의 랜덤숫자를 choice에 대입
			Sleep(100); // 딜레이를 준다
			score = score + 10; // score에 10을 증가하고 대입
			cur = (60 * len) / (end_t - start_t); // 현재 타수를 구하여 cur에 대입
			avg = (total_len / inputCnt) * (60 / (total_t / inputCnt)); // 평균 타수를 구하여 avg에 대입
		}

		else // ans와 wordDB[choice] 비교했을 때 같지 않으면
		{
			printf("오답입니다. \n"); // "오답입니다."를 출력
			Sleep(100); // 딜레이를 준다
			score = score - 5; // score에 5를 감소하고 대입
		}
	}
}

void updown_game() // void는 함수가 끝나고 반환되는 값이 없다.
{
	int com = 0, usr = 0, i = 0, t = 0, count = 0; // 정수형 메모리 com, usr, i, t, count를 만들고 0으로 초기화

	printf("업다운 게임입니다. (기회는 10번) \n"); // "업다운 게임입니다."를 출력
	printf("컴퓨터가 하나의 숫자를 생성중입니다. \n"); // "컴퓨터가 하나의 숫자를 생성중입니다."를 출력

	for (i = 0; i < 10; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 10이 되면 반복종료
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
		printf("1 ~ 100까지의 숫자를 입력하세요 : "); // "1 ~ 100까지의 숫자를 입력하세요 : "를 출력
		scanf_s("%d", &usr); // 정수를 입력받아 usr의 메모리 주소로 배달
		count = count + 1; // count에 1을 증가
		// printf("%d", count);

		// 열번 입력할 때
		if (count == 10) // count의 값이 10이 되면
		{
			printf("10번이 넘었습니다. 다음에 다시 도전하세요,"); // "10번이 넘었습니다. 다음에 다시 도전하세요,"를 출력
			break; // while 반복문에서 빠져나옴
		}

		// 잘못된 숫자 입력
		if (usr > 100 || usr == 0) // usr의 값이 100이 넘거나 0 이면
		{
			printf("0 혹은 100 초과의 숫자입니다. \n"); // "0 혹은 100 초과의 숫자입니다."를 출력
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

void baseball_game() // void는 함수가 끝나고 반환되는 값이 없다.
{
	int com[3] = { 0 }, usr[3] = { 0 }, i = 0, j = 0, t = 0, strike = 0, count = 0, ball = 0; // 정수형 메모리 com 3개, usr 3개, i, j, t, strike, count, ball을 만들고 모두 0으로 초기화 // { 0 } -> 0을 하나만 쓰면 나머지는 0로 채워짐

	printf("야구 게임입니다. \n"); // "야구 게임입니다."를 출력
	printf("컴퓨터가 세개의 숫자를 생성중입니다. \n"); // "컴퓨터가 세개의 숫자를 생성중입니다."를 출력

	for (i = 0; i < 10; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 10이 되면 반복종료
	{
		printf("■"); // "■" 출력
		Sleep(100); // 딜레이
	}

	printf("\n"); // 다음줄
	printf("세개의 숫자가 생성되었습니다. \n"); // "세개의 숫자가 생성되었습니다."를 출력
	printf("\n"); // 다음줄
	printf("1부터 9까지의 숫자를 입력하시오. (기회는 10번) \ n"); // "1부터 9까지의 숫자를 입력하시오. (기회는 열번)"을 출력
	printf("<숫자를 중복되게 입력하지마시오!> \n"); // "<숫자를 중복되게 입력하지마시오!>"를 출력

	t = time(NULL); // t에 1970년 1월 1일 0시 0분 부터 현재까지의 시간(초)을 대입
	srand(t); // srand에 t를 넣어줌으로써 rand의 시드가 계속 바뀐다.
	// printf("t is %d \n", t); // t값을 출력

	// 랜덤 숫자 3개 생성
	while (1) // 0외의 다른 수 이기 때문에 무한 반복
	{
		for (i = 0; i < 3; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
		{
			com[i] = (rand() % 9) + 1; // 1에서 9까지의 랜덤숫자를 com에 대입
			// printf("com[%d] = %d \n", i, com[i]);
		}

		if (com[0] == com[1] || com[0] == com[2] || com[1] == com[2]) // 중복 숫자 제외
			continue; // 반복문 처음으로 돌아가기
		else
			break; // while 반복문에서 빠져나옴
	}

	while (1) // 0외의 다른 수 이기 때문에 무한 반복
	{
		// 숫자 입력받기
		for (j = 0; j < 3; j = j + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
		{
			printf("usr[%d] : ", j); // "usr[%d] : "를 출력
			scanf_s("%d", &usr[j]); // 정수를 입력받아 usr의 메모리 주소로 배달
		}
		count = count + 1; // count에 1을 증가
		// printf("count is %d \n", count);

		// 열번 입력할 때
		if (count == 10) // count의 값이 10이면
		{
			printf("10번이 넘었습니다. 다음에 다시 도전하세요."); // "10번이 넘었습니다. 다음에 다시 도전하세요."를 출력
			break; // while 반복문에서 빠져나옴
		}

		// 잘못된 숫자 입력
		if (usr[0] == 0 || usr[0] > 9 || usr[1] == 0 || usr[1] > 9 || usr[2] == 0 || usr[2] > 9) // usr의 값이 0이거나 9를 넘을 경우
		{
			printf("1부터 9까지의 숫자가 아닙니다. 다시 입력하세요. \ n"); // "1부터 9까지의 숫자가 아닙니다. 다시 입력하세요."를 출력
			continue; // 반복문 처음으로 돌아가기
		}

		// 중복된 숫자 입력
		if (usr[0] == usr[1] || usr[0] == usr[2] || usr[1] == usr[2]) // 중복 숫자 제외
		{
			printf("중복된 숫자는 게임을 진행할 수 없습니다. 다시 입력하세요. \ n"); // "중복된 숫자는 게임을 진행할 수 없습니다. 다시 입력하세요."를 출력
			continue; // 반복문 처음으로 돌아가기
		}

		// 숫자와 숫자의 위치 비교
		for (i = 0; i < 3; i = i + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
		{
			for (j = 0; j < 3; j = j + 1) // i에 0을 대입하고 1씩 증가하면서 반복하다가 3이 되면 반복종료
			{
				if (com[i] == usr[j]) // com의 값과 usr의 값이 같으면서
				{
					if (i == j) // com의 위치와 usr의 위치가 같으면
						strike = strike + 1; // strike에 1을 증가
					else // 위치가 다르면
						ball = ball + 1; // ball에 1을 증가
				}
			}
			// printf("com is %d, usr is %d", com[i], usr[i]);
		}
		printf("strike is %d , ball is %d \n", strike, ball); // strike와 ball의 값 출력

		// 볼
		if (ball < 4) // ball의 값이 4 미만이면
			ball = 0; // ball의 값을 초기화

		// 스트라이크
		if (strike < 3) // strike의 값이 3 미만이면
			strike = 0; // strike의 값을 초기화

		if (strike == 3) // strike의 값이 3이면
		{
			printf("축하합니다. 스트라이크입니다. \n"); // "축하합니다. 스트라이크입니다."를 출력
			printf("%d번 만에 맞추셨습니다. \n", count); // count의 값 출력
			break; // while 반복문에서 빠져나옴
		}
	}
}

void prime() // void는 함수가 끝나고 반환되는 값이 없다.
{
	int num = 0, i = 0, count = 0; // 정수형 메모리 num, i, count를 만들고 0을 대입

	printf("정수 하나 입력 : "); // "정수 하나 입력 : " 을 출력
	scanf_s("%d", &num); // 키보드로 부터 %d에 정수를 받아서 num의 주소로 배달

	for (i = 1; i <= num; i = i + 1) // (1) i에 1을 대입 -> (2) i가 num의 값에 이하일 때 까지 반복 -> (4) i에 1을 증가
	{
		if (num % i == 0) // (3) num의 값을 i의 값으로 나누었을떄 나누어 떨어진다면
		{
			count = count + 1; // true일 경우 count의 값에 1을 증가
			// printf("num is %d \n", i); // true일 경우 출력
		}
	}

	// printf("count is %d \n", count); // count값 출력

	if (count == 2)
		printf("%d 숫자는 %d번 나누어 졌으니 소수 입니다. \n", num, count); // count의 값이 2일 때 출력
	else
		printf("%d 숫자는 %d번 나누어 졌으니 소수가 아닙니다. \n", num, count); // count의 값이 2가 아닐 때 출력
}

void same() // void는 함수가 끝나고 반환되는 값이 없다.
{
	char word_1[21] = "", word_2[21] = "", i = 0, wordCnt_1 = 0, wordCnt_2 = 0, flag = 0;// 문자열 21개('\0'포함) word_1과 word_2를 만들고, i, wordCnt_1, wordCnt_2, flag를 만들어 모두 0으로 초기화

	printf("단어 입력 : "); // "단어 입력 : " 을 출력
	scanf_s("%s", &word_1[0], sizeof(word_1)); // 문자열을 입력받아서 word_1의 0번째 메모리 주소로 배달
	printf("단어 입력 : "); // "단어 입력 : " 을 출력
	scanf_s("%s", &word_2[0], sizeof(word_2)); // 문자열을 입력받아서 word_2의 0번째 메모리 주소로 배달

	// printf("%s \n", &word_1[0]);
	// printf("%s \n", &word_2[0]);

	// 첫번째 입력 단어 길이 구하기
	for (i = 0; i < 21; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 21이 되면 반복종료 -> (4) i의 값에 1을 증가
	{
		if (word_1[i] == '\0') // (3) word_1의 i번째에 있는 문자가 '\0'과 같으면
			break; // 반복 종료
		wordCnt_1 = wordCnt_1 + 1; // wordCnt_1의 값에 1을 증가
	}

	// 두번째 입력 단어 길이 구하기
	for (i = 0; i < 21; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 21이 되면 반복종료 -> (4) i의 값에 1을 증가
	{
		if (word_2[i] == '\0') // (3) word_2의 i번째에 있는 문자가 '\0'과 같으면
			break; // 반복 종료
		wordCnt_2 = wordCnt_2 + 1; // wordCnt_2의 값에 1을 증가
	}

	// 두 단어의 길이 비교
	if (wordCnt_1 == wordCnt_2) // wordCnt_1의 값과 wordCnt_2의 값이 같으면
	{
		for (i = 0; i < wordCnt_1; i = i + 1) // (1) i에 0을 대입 -> (2) i의 값이 wordCnt_1의 값이랑 같아지게 되면 반복문 종료 -> (4) i의 값에 1을 증가
		{
			if (word_1[i] == word_2[i]) // (3) word_1의 i번째 있는 문자와 word_2의 i번째 있는 문자가 같으면
				flag = flag + 1; // flag의 값에 1을 증가
			else // 같지 않으면
				break; // 반복 종료
		}
		if (flag == wordCnt_1) // flag의 값과 wordCnt_1의 값이 같으면
			printf("두 단어는 같은 단어입니다. \n"); // "두 단어는 같은 단어입니다."를 출력
		else // flag의 값과 wordCnt_1의 값이 같지 않으면
			printf("두 단어는 다른 단어입니다. \n"); // "두 단어는 다른 단어입니다."를 출력
	}
	else // wordCnt_1의 값과 wordCnt_2의 값이 같지 않으면
		printf("두 단어는 다른 단어입니다. \n"); // "두 단어는 다른 단어입니다."를 출력
}

void grade() // void는 함수가 끝나고 반환되는 값이 없다.
{
	int score[10] = { 0 }, sum = 0, i = 0; // 정수형 메모리 score 10개와 sum, i를 만들고 모두 0으로 초기화 // score : 0의값이 0번메모리에 들어가고 나머지는 자동으로 0으로 채워짐
	double avg = 0; // 실수형 메모리 avg를 만들고 0으로 초기화

	// 성적 입력 받기
	for (i = 0; i < 10; i = i + 1) // i에 0을 대입하고 i에 1씩 증가하면서 9까지 반복
	{
		printf("성적 입력 : "); // "성적 입력 : "을 출력
		scanf_s("%d", &score[i]); // 입력받은 정수를 score의 i번째 메모리 주소로 배달
		sum = sum + score[i]; // sum에 score[i]값을 더하여 대입
	}

	// 평균 구하기
	avg = (double)sum / 10; // 계산할때만 sum을 소수로 강제 형변환을 하여 10으로 나누고 avg에 대입
	printf("총합 : %d, 평균 : %f \n", sum, avg); // sum, avg값을 출력
}

void asc_des() // void는 함수가 끝나고 반환되는 값이 없다.
{
	char name[10][10] = { "" }, temp[10] = ""; // 문자열 길이가 10개인 메모리를 name(10개)과 temp를 만들고 모두 0 으로 초기화
	int i = 0, j = 0, od = 0; // 정수형 메모리 i, j, od를 만들고 0으로 초기화

	for (i = 0; i < 10; i++) // i에 0을 대입하고 1씩 증가하면서 9까지 반복
	{
		printf("사람 이름 입력 : "); // "사람 이름 입력 : "을 출력
		gets_s(&name[i][0], sizeof(name[i])); // 입력받은 문자열을 name[i]번째 0번째의 주소로 배달, name[i]의 사이즈 크기로 정한다.
	}

	// 오름차순, 내림차순 입력 받기
	printf("오름차순은 1번, 내림차순은 2번을 선택해주세요 : "); // "오름차순은 1번, 내림차순은 2번을 선택해주세요 : "를 출력
	scanf_s("%d", &od); // 입력받은 정수를 od의 메모리 주소로 배달

	for (j = 0; j < 10 - 1; j = j + 1) // j에 0을 대입하고 j에 1씩 증가하면서 8까지 반복
	{
		for (i = 0; i < 10 - 1; i = i + 1) // i에 0을 대입하고 i에 1씩 증가하면서 8까지 반복
		{
			// 오름차순
			if (od == 1 && strcmp(name[i], name[i + 1]) > 0) // od의 값이 1과 같으면서 strcmp() 함수를 사용하여 문자열을 비교한 뒤 0 보다 크면
			{
				strcpy_s(temp, sizeof(name[i]), name[i]); // name[i]번 메모리에 있는 데이터를 temp에 복사
				strcpy_s(name[i], sizeof(name[i]), name[i + 1]); // name[i + 1]번 메모리에 있는 데이터를 name[i]번 메모리로 복사
				strcpy_s(name[i + 1], sizeof(name[i]), temp); // temp에 있는 데이터를 name[i + 1]번 메모리로 복사
				// strcpy_s -> sizeof를 넣어줘야 한다.
			}

			// 내림차순
			if (od == 2 && strcmp(name[i], name[i + 1]) < 0) // od의 값이 2와 같으면서 strcmp() 함수를 사용하여 문자열을 비교한 뒤 0 보다 작으면
			{
				strcpy_s(temp, sizeof(name[i]), name[i]); // name[i]번 메모리에 있는 데이터를 temp에 복사
				strcpy_s(name[i], sizeof(name[i]), name[i + 1]); // name[i + 1]번 메모리에 있는 데이터를 name[i]번 메모리로 복사
				strcpy_s(name[i + 1], sizeof(name[i]), temp); // temp에 있는 데이터를 name[i + 1]번 메모리로 복사
			}
		}
	}

	for (i = 0; i < 10; i++) // i에 0을 대입하고 1씩 증가하면서 9까지 반복
	{
		printf("%d: %s \n", i, &name[i][0]); // i와 name의 값 출력
	}
}

void time_main() // void는 함수가 끝나고 반환되는 값이 없다.
{
	int num = 0, hour = 0, min = 0, sec = 0, i = 0; // 정수형 메모리 num, hour, min, sec, i를 만들고 모두 0을 대입

	printf("시, 분, 초를 입력 : "); // "시, 분, 초를 입력 : "을 출력
	scanf_s("%d %d %d", &hour, &min, &sec); // 정수를 입력받아 첫번째 정수는 hour의 주소로 배달
	// 두번째 입력받은 정수는 min의 주소로 배달
	// 세번째 입력받은 정수는 sec의 주소로 배달
	num = (hour * 3600) + (min * 60) + sec; // hour의 값 곱하기 3600의 값과 min의 값 곱하기 60의 값을 더한 뒤, sec의 값까지 더하여 num에 대입
	printf("초 : %d \n", num); // num의 값을 출력
}

void file_main() // void는 함수가 끝나고 반환되는 값이 없다.
{
	unsigned char fname[256] = "", word[256] = "", sname[256] = ""; // 문자열 메모리 fname, word, sname을 만들고 모두 0으로 초기화 // 파일글자는 256까지 지원
	int count = 0, max = 0, len = 0; // 정수형 메모리 count, max, len을 만들고 모두 0으로 초기화

	printf("원본 파일 명을 입력하세요 : "); // "원본 파일 명을 입력하세요 : "를 출력
	gets(&fname[0]); // 입력받은 문자열을 fname의 0번 메모리 주소로 배달
	printf("사본 파일 명을 입력하세요 : "); // "사본 파일 명을 입력하세요 : "를 출력
	gets(&sname[0]); // 입력받은 문자열을 sname의 0번 메모리 주소로 배달
	// printf("file name is %s \n", fname);

	// 파일 열기, // 파일접근 할 때 파일구조체변수 사용
	FILE* fp = fopen(fname, "rt"); //파일이 저장된 주소, fname의 파일을 read text모드로 열어서 fp에 대입
	FILE* fp_out = fopen(sname, "wt"); // sname의 파일을 write text모드로 열어서 파일을 생성하고 fp_out에 대입
	// "rt" 뿐만 아니라 "wt". "rb", "wb" 도 있다.

	// 존재하지 않는 파일이라면 fopen은 NULL을 준다.
	if (fp == NULL) // fp가 NULL일 경우
	{
		printf("파일이 존재하지 않습니다. \n"); // "파일이 존재하지 않습니다."를 출력
		return; // 이전의 함수로 돌아간다.
	}

	while (1) // 0 이외의 다른 수 이기 때문에 무한 반복
	{
		fscanf(fp, "%s", &word[0]); // fp파일에서 word의 0번째 주소를 받아온다.
		// printf("word is %s \n", word);
		// 단어의 길이 확인
		len = strlen(word); // word의 길이를 구해 len에 대입
		fprintf(fp_out, "%d : %s, %d \n", count, &word[0], len); // fp_out파일로 count, word[0], len의 값 들을 포함해서 출력 *파일에 출력된다*
		count = count + 1; // count에 1을 증가

		// 최대 길이 확인
		if (len > max) // len의 값이 max보다 크다면
			max = len; // max에 len의 값을 대입

		// fp가 끝인지 아닌지 확인
		if (feof(fp)) // fp가 끝이라면
			break; // 반복문 종료
	}
	// 단어의 개수와 최대 길이 확인
	printf("단어의 개수 : %d, 단어의 최대 길이 : %d \n", count, max); // count, max의 값을 출력

	// 파일 닫기
	fclose(fp); // fp 파일 닫기
	fclose(fp_out); // fp_out 파일 닫기
}

void error() // void는 함수가 끝나고 반환되는 값이 없다.
{
	printf("잘못 입력 하셨습니다. 1~12의 메뉴를 선택하세요. \ n"); // "잘못 입력 하셨습니다. 1~12의 메뉴를 선택하세요."를 출력
}

void main() // 프로그램 시작 점
{
	int no = 0; // 정수형 메모리 no를 만들고 0으로 초기화
	while (1) // 0 이외의 다른 수 이기 때문에 무한반복
	{
		no = menu(); // menu() 함수 호출하여 결과값을 no에 대입
		// printf("선택된 값은 : %d \n", no);

		switch (no) // 어떤 변수의 값이 상수로 만들어 질 때 사용
		{
		case 1: encrypt(); break; // no가 1과 일치하면 encrypt() 함수 호출
		case 2: decrypt(); break; // no가 2와 일치하면 decrypt() 함수 호출
		case 3: short_test(); break; // no가 3과 일치하면 short_test() 함수 호출
		case 4: updown_game(); break; // no가 4와 일치하면 updown_game() 함수 호출
		case 5: baseball_game(); break; // no가 5와 일치하면 baseball_game() 함수 호출
		case 6: prime(); break; // no가 6과 일치하면 prime() 함수 호출
		case 7: same(); break; // no가 7과 일치하면 same() 함수 호출
		case 8: grade(); break; // no가 8과 일치하면 grade() 함수 호출
		case 9: asc_des(); break; // no가 9와 일치하면 asc_des() 함수 호출
		case 10: time_main(); break; // no가 10과 일치하면 time_main() 함수 호출
		case 11: file_main(); break; // no가 11과 일치하면 file_main() 함수 호출
		case 12: exit(1); break; // no가 12와 일치하면 프로그램 종료
		default: error(); break; // no가 일치한게 없다면 error() 함수 호출
			// 스위치 안에서 break를 만나면 스위치 문을 나간다.
		}

		/*
		if (no == 1) // no의 값이 1과 같다면
			encrypt(); // encrypt() 함수 호출
		if (no == 2) // no의 값이 2와 같다면
			encrypt(); // encrypt() 함수 호출
		if (no == 3) // no의 값이 3과 같다면
			break; // 반복문 종료
		*/
	}
}










