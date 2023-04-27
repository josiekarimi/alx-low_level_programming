#include "main.h"

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/

int convert_day(int month, int day)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0;
    int i;

    /* Count the number of days in the year up to the current month */
    for (i = 0; i < month - 1; i++)
    {
        day_count += days_in_month[i];
    }

    /* Add the number of days in the current month */
    day_count += day;

    return (day_count);
}

