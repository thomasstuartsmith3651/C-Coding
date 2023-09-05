#include <stdio.h>
#include <stdlib.h>

typedef enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;

typedef struct date{
                    month m;
                    int day;
                    }date;

int monthSize;

void printDate(date *ptrDate)
{   switch(ptrDate ->m)
    {   
        case JAN:
            printf("January %d",ptrDate -> day);
            monthSize = 31;break;

        case FEB:
            printf("February %d",ptrDate -> day);
            monthSize = 28;break;

        case MAR:
            printf("March %d",ptrDate -> day);
            monthSize = 31;break;
        
        case APR:
            printf("April %d",ptrDate -> day);
            monthSize = 30;break;

        case MAY:
            printf("May %d",ptrDate -> day);
            monthSize = 31;break;

        case JUN:
            printf("June %d",ptrDate -> day);
            monthSize = 30;break;

        case JUL:
            printf("July %d",ptrDate -> day);
            monthSize = 31;break;

        case AUG:
            printf("AUG %d",ptrDate -> day);
            monthSize = 31;break;

        case SEP:
            printf("SEPTEMBER %d",ptrDate -> day);
            monthSize = 30;break;
        
        case OCT:
            printf("October %d",ptrDate -> day);
            monthSize = 31;break;
        
        case NOV:
            printf("November %d",ptrDate -> day);
            monthSize = 30;break;

        case DEC:
            printf("January %d",ptrDate -> day);
            monthSize = 31;break;}}

date *nextday(date *dateP)
{
    if (dateP->day == monthSize)                 //accounts for end of month
    {
        dateP->m = (dateP->m + 1) % 12;          //accounts for end of year without need for if else
        dateP->day = (dateP->day + 1) % monthSize; //new month
    }

    else                                   
        dateP->day = (dateP->day + 1); //nextday within the month

  return dateP;
}

int main()
{
    int i;

    date date_1 = {JAN, 1};
    date date_2 = {FEB, 28};
    date date_3 = {MAR, 14};
    date date_4 = {OCT, 31};
    date date_5 = {DEC, 31};
    date date[] = {date_1, date_2, date_3, date_4, date_5};
    
    for (i=0; i<5; i++)
    {
        printf("\nInput Date: ");
        printDate(&date[i]);

        printf("\nNext Date: ");
        nextday(&date[i]);              
        printDate(&date[i]);
    }

    return 0;
}