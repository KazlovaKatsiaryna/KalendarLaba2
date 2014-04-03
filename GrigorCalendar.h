#ifndef GrigorCalendar_H
#define GrigorCalendar_H

struct Date
{
    int year;
    int month;
    int day;
};
void choiceOfAction(struct Date data1 , struct Date data2);

Date enterDate ();
Date addDays (struct Date data1 , struct Date data2);
Date subctractDays (struct Date data1 , struct Date data2);
Date numberOfDays (struct Date data1 , struct Date data2);

#endif // GrigorCalendar_H
