#include <iostream>

#include "Week5_2_P1.h"

using namespace std;

void Homework01_Run()
{
	printf("1. 요일 구하기\n\n");
	Date Start_Date;
	Date Input_Date;
	int Days = 0;
	GetInput_Date(Input_Date);
	Days += Calculation_Days(Start_Date, Input_Date);
	printf("%d년 %d월 %d일은 %s요일 입니다.\n", Input_Date.Year, Input_Date.Moth, Input_Date.Day, DayofWeek_Calculation(Days));
}

void GetInput_Date(Date& Input)
{// 년월일 입력
	int Common_Month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };// 확인위한 평년 각월 일수
	printf("날짜를 입력해주세요.\n");
	while (1)
	{// input년이 정상인지 입력 반복
		printf("년 : ");
		cin >> Input.Year;
		if (Input.Year < 1)
		{
			printf("연도는 1년 이상이어야 합니다.\n ");
		}
		else
		{
			break;
		}
	}
	while (1)
	{// input월이 정상인지 입력 반복
		printf("월 : ");
		cin >> Input.Moth;
		if (Input.Moth < 0 || Input.Moth > 12)
		{
			printf("월은 1월부터 12월 사이어야 합니다.\n ");
		}
		else
		{
			break;
		}
	}
	while (1)
	{// input일이 정상인지 입력 반복
		printf("일 : ");
		cin >> Input.Day;
		if (((Check_LeepYear(Input) && Input.Moth == 2) && Input.Day > 29) || (Common_Month[Input.Moth - 1] < Input.Day))
		{
			printf("일이 안맞습니다.\n ");
		}
		else
		{
			break;
		}
	}
	
}

bool Check_LeepYear(Date Year)
{// 윤년 계산
	if ((Year.Year % 4 == 0 && Year.Year % 100 != 0) || Year.Year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Calculation_Days(Date Start, Date Input)
{
	int Days = 0;
	int Leap_Month[] = { 2,0,2,1,2,1,2,2,1,2,1,2 }; //윤년 월
	int Common_Month[] = { 3,0,3,2,3,2,3,3,2,3,2,3 }; //평년 월
	while (Start.Year < Input.Year)//년 계산
	{
		if (Check_LeepYear(Start))
		{//윤년이면
			Days += 366;
		}
		else
		{//평년이면
			Days += 365;
		}
		Start.Year++;
	}
	if (Check_LeepYear(Start))//월 계산
	{//윤년이면
		for (int i = 0; i < Input.Moth - 1; i++)
		{
			Days += (29 + Leap_Month[i]);
		}
	}
	else
	{//평년이면
		for (int i = 0; i < Input.Moth - 1; i++)
		{
			Days += (28 + Common_Month[i]);
		}
	}
	Days += (Input.Day - 1);//일 계산
	return Days;
}

const char* DayofWeek_Calculation(int Days)
{// 요일 계산
	switch (Days % 7)
	{
	case 0:
		return "월";
	case 1:
		return "화";
	case 2:
		return "수";
	case 3:
		return "목";
	case 4:
		return "금";
	case 5:
		return "토";
	case 6:
		return "일";
	}
	return "?";
}