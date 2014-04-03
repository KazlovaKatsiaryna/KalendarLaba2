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

    while(true)
    {
        system("cls");
        cout << "Hello!\n "<<endl;
        data1=enterDate();
        data2=enterDate();

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
            Date newData;
            newData=addDays (data1 , data2);
            cout << "New Date: " << newData.year << " " << newData.month << " " << newData.day << endl;
            system("pause");
        }
        if( enterNumber == '2')
        {
            system("cls");
            //subctractDays (data1, data2);
            system("pause");
        }
        if( enterNumber == '3')
        {
            system("cls");
           //numberOfDays (data1, data2);
            cout << endl;
            system("pause");
        }
    }
    system("pause");
}
