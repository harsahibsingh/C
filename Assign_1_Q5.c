//Q5. Write a C program to find out given year is leap year or not.
#include<stdio.h>
int main()
{
   int year;
    printf("Enter Any Year To Check. \n");
    scanf("%d",&year);
   if((year%100!=0 && year%4==0)||year%400==0)//Condition Of Leap Year
    printf("Entered Year Is Leap Year.\n ");
    else
    printf("Entered Year Is Not A Leap Year.\n");
return 0;
}
