#include "GrigorCalendar.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;


int leapYearOrNot (int year);
int numberOfDaysInTheYear (int year);
int numberOfLeapYears (int year);
int numberOfDaysInMonth1 (int month);
int numberOfDaysInMonth2 (int month);
int FromDateToDays (struct Date data);
Date FromDaysToDate (int numberOfDays);


Date enterDate1 ()
{
    Date data1;
    cout << "Enter Date: \n";
    cin.ignore(1,'\n');
    cout << "Year: ";
    cin >> data1.year;

    cout << "Month: ";
    cin >> data1.month;

    cout << "Day: ";
    cin >> data1.day;
    cout << endl;

    return data1;
}

Date enterDate2 ()
{
    Date data2;
    cout << "Enter Date: \n";
    cin.ignore(1,'\n');
    cout << "Year: ";
    cin >> data2.year;

    cout << "Month: ";
    cin >> data2.month;

    cout << "Day: ";
    cin >> data2.day;
    cout << endl;

    return data2;
}

int enterNum ()
{
    int number;
    cout << "Numder: ";
    cin >> number;
    return number;
}

int leapYearOrNot (int year)// проверяет високосный год или нет
{
    int res;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        res=1;
    }
    else
    {
        res=0;
    }
    return res;
}

int numberOfDaysInTheYear (int year)//узнаёт количество дней в году
{
    int nOfDInTheY;
    nOfDInTheY = 365+leapYearOrNot (year);
    return nOfDInTheY;
}

int numberOfLeapYears (int year)//узнаёт количество високосных лет до введённого года включительно
{
    int numberLY=0;
    numberLY = year / 4 - year / 100 + year /400;
    return numberLY;
}

int numberOfDaysInMonth1 (int month)
{
    int monthsInYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int sumOfDays1 = 0;
    for (int i=0; i<=month; i++)
    {
        sumOfDays1 += monthsInYear[i];
    }
    return sumOfDays1;
}

int numberOfDaysInMonth2 (int month)
{
    int monthsInLeapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int sumOfDays2 = 0;
    for (int i=0; i<=month; i++)
    {
        sumOfDays2 += monthsInLeapYear[i];
    }
    return sumOfDays2;
}

int FromDateToDays (struct Date data) //переводит дату в дни
{
    int DateToDays;
    DateToDays= numberOfLeapYears (data.year) + data.year*365 + data.day;
    if(leapYearOrNot(data.year) == 1)
    {
        DateToDays += numberOfDaysInMonth2 (data.month);
    }
    else
    {
        DateToDays += numberOfDaysInMonth1 (data.month);
    }
    return DateToDays;
}

Date addDays (struct Date data1, int number) //прибавляет дни
{
    int res;
    res = FromDateToDays(data1) + number;
    Date res1= FromDaysToDate (res);
    return res1;
}

Date subctractDays (struct Date data1, int number) //отнимает дни
{
    int res;
    res = FromDateToDays(data1) - number;
    Date res1= FromDaysToDate (res);
    return res1;
}

int numberOfDays (struct Date data1 , struct Date data2) // находит разницу между датами
{
    int res;
    res = FromDateToDays(data1) - FromDateToDays(data2);
    return res;
}

Date FromDaysToDate (int numberOfDays)
{
    Date newData;
    int n=1;
    int Sum = 0;
    int DaysToDate;
    int Year1, Year2, Year3, Year4, Ost1, Ost2, Ost3, Ost4;
    int monthsInYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    Year1 = numberOfDays/146097;
    Ost1 =numberOfDays- (Year1*146097);
    Year2 = Ost1/36524;
    Ost2 = Ost1 - (Year2*36524);
    Year3 = Ost2/1461;
    Ost3 = Ost2 - (Year3*1461);
    Year4 = Ost3/365;
    Ost4 = Ost3 - (Year4*365);
    while (Sum<=Ost4)
    {
        for (int i=0; i<=12; i++)
        {
            Sum += monthsInYear[i];
            n++;
        }
    }
    newData.day = Ost4 - Sum;
    newData.year = 400*Year1 + 100*Year2 + 4*Year3 + Year4;
    newData.month = n;
    return newData;
}
