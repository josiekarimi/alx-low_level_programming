#include <stdio.h>
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

  for (i = 0; i < month - 1; i++)
  {
    day_count += days_in_month[i];
  }
  day_count += day;
  return (day_count);
}

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */

void print_remaining_days(int month, int day, int year)
{
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_count;

  day_count = convert_day(month, day);

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  {
    if (month >= 3)
    {
      day_count += 1;
    }
  }

  if (month < 1 || month > 12)
  {
    printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
  }
  else if (day < 1 || day > days_in_month[month - 1])
  {
    printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
  }
  else
  {
    printf("Day of the year: %d\n", day_count);
    printf("Remaining days: %d\n", 365 - day_count + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0));
  }
}

