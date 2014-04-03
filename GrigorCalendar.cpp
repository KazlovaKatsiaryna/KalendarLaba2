#include "GrigorCalendar.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;


int leapYearOrNot (int year);
int numberOfDaysInTheYear (int day, int year);
int numberOfLeapYears (int year);


Date enterDate ()

{
    Date data;
    cout << "Enter Date: \n";
    cin.ignore(1,'\n');

        cout << "Year: ";
        cin >> data.year;

        cout << "Month: ";
        cin >> data.month;

        cout << "Day: ";
        cin >> data.day;
        cout << endl;

        return data;

}

int leapYearOrNot (int year)// проверяет високосный год или нет
{
    int res;
    cout<<"Enter year: ";
    cin>>year;
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

int numberOfDaysInTheYear (int day, int year)//узнаёт количество дней в году
{
    int nOfDInTheY;
    day = leapYearOrNot (year);
    nOfDInTheY = 365+day;
    return nOfDInTheY;
}

int numberOfLeapYears (int year)//узнаёт количество високосных лет до введённого года включительно
{
    int numberLY = 0;
    for (int i=0; i<=year; i++)
    {
        if(leapYearOrNot (i) == 1)
        {
            numberLY++;
        }
    }
    return numberLY;
}


/*здесь несколько, пока не написанных функций, к вечеру будут*/




Date addDays (struct Date data1 , struct Date data2)
{
    Date res;

            res.year = data1.year + data2.year;
            res.month = data1.month + data2.month;
            res.day = data1.day + data2.day;

    return res;
}
