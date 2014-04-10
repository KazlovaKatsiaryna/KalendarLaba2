#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "GrigorCalendar.h"

using namespace std;

int main()
{
    Date data1, data2;
    choiceOfAction(data1 , data2);
    return 0;
}

void choiceOfAction(struct Date data1 , struct Date data2)
{
    int number;
    while(true)
    {
        system("cls");
        cout << "Hello!\n "<<endl;
        data1 = enterDate1();

        cout << "If you want to: " << endl;
        cout << " exit, please, click <0>\n";
        cout << " add the number of days, please, click <1>\n";
        cout << " subtract the number of days, please, click <2>\n";
        cout << " know the number of days between dates, please, click <3>\n";

        char enterNumber;
        cin >> enterNumber;

        if( enterNumber == '0')
        {
            system("cls");
            exit(0);
        }

        if( enterNumber == '1')
        {
            system("cls");
            cout<<"Enter the number of days: ";
            number = enterNum();

            Date newData=addDays(data1, number);

            cout << "New Date: " << newData.year << " " << newData.month << " " << newData.day << endl;
            system("pause");
        }
        if( enterNumber == '2')
        {
            system("cls");
            cout<<"Enter the number of days: ";
            number = enterNum();

            Date newData=subctractDays(data1, number);
            cout << "New Date: " << newData.year << " " << newData.month << " " << newData.day << endl;
            system("pause");
        }
        if( enterNumber == '3')
        {
            system("cls");
            data2 = enterDate2();
            cout << numberOfDays (data1, data2)<< endl;
            system("pause");
        }
    }
    system("pause");
}
