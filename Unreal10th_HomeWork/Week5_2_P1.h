#pragma once

// 1. 요일 구하기
//  - 1년 1월 1일(월요일)을 기준으로 입력한 날짜까지 며칠이 지났는지 계산한 후, 7로 나눈 나머지로 요일을 구하기.
//  - 윤년도 올바르게 처리할 것( 4의 배수이면서 100의 배수가 아닐 때, 400의 배수일 때)
//  - 입력받은 연, 월, 일을 기준으로 요일을 출력.
//    - 예시 입력 : 2026 5 29 → 결과 : 금요일
//  - Homework01_Run(); 함수로 실행 가능해야 함.

struct Date
{
	int Year = 1;
	int Moth = 1;
	int Day = 1;

	Date() {}

	Date(int InYear, int InMoth, int InDay)
	{
		InYear = Year;
		InMoth = Moth;
		InDay = Day;
	}
};

void Homework01_Run();

void GetInput_Date(Date& Input);

bool Check_LeepYear(Date Year);

int Calculation_Days(Date Start, Date Input);

const char* DayofWeek_Calculation(int Days);