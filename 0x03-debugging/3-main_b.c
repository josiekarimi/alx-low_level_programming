#include "main.h"

/**
 * main - takes date from user input and prints how many days are left in the year
 * Return: Always 0.
 */

int main(void)
{
    int month;
    int day;
    int year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    if (month < 1 || month > 12)
    {
        printf("Invalid date: Month must be between 1 and 12\n");
        return (1);
    }

    if (day < 1 || day > 31)
    {
        printf("Invalid date: Day must be between 1 and 31\n");
        return (1);
    }

    if (year < 0)
    {
        printf("Invalid date: Year must be a positive integer\n");
        return (1);
    }

    if (convert_day(month, day) == -1)
    {
        printf("Invalid date: Day must be between 1 and 28/30/31, depending on the month\n");
        return (1);
    }

    print_remaining_days(month, day, year);

    return (0);
}

