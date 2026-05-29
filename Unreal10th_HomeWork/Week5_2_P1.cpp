#include <iostream>

#include "Week5_2_P1.h"

using namespace std;

void Homework01_Run()
{
	printf("1. 요일 구하기\n\n");
	Date Start_Date;
	Date Input_Date;
	int Days = 0;
	printf("날짜를 입력해주세요.(ex 2026 5 29) : ");
	cin >> Input_Date.Year, Input_Date.Moth, Input_Date.Day;
	Days = Calculation_Days(Start_Date, Input_Date);
}

int Calculation_Days(Date Start, Date Input)
{
	int Days = 0;
	while (Start.Year < Input.Year)
	{

	}
	return Days;
}

bool Check_LeapYear(Date Da)
{

	return false;
}