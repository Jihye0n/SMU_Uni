// 시저 암호를 분석하여 평문과 키를 찾는 프로그램 (C언어) - 수정

#include <stdio.h>

void main() {
	char code[] = "CSYEVIXIVQMREXIH", temp = 0; // 암호문 변수 선언, 기본 암호문 대입 / temp 변수 선언, 초기화
	int i = 0, n = 0; // i, n 변수 선언, 초기화

	for (n = 0; n < 26; n++) { // 26번 출력
		for (i = 0; code[i] != '\0'; i++) {
			temp = code[i] - n; // 키 값 만큼 복호화 후, 변환된 암호를 저장
			if (temp < 'A') // 범위를 벗어난 경우
				temp += 26; // 26을 더해 범위로 조정
			temp += 32; // 대문자에서 소문자로 변경
			printf("%c", temp); // 변환된 암호를 출력
		}
		printf("\n"); // 줄 바꿈
	}
}