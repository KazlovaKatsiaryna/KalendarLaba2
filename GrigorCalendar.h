#ifndef GrigorCalendar_H
#define GrigorCalendar_H

struct Date
{
    int year;
    int month;
    int day;
};

void choiceOfAction(struct Date data1 , struct Date data2);

Date enterDate1 ();
Date enterDate2 ();
int enterNum ();
Date addDays (struct Date data1, int number);
Date subctractDays (struct Date data1, int number);
int numberOfDays (struct Date data1 , struct Date data2);

#endif // GrigorCalendar_H
