/* Q5. Implement a C program to check given number is prime or not.
( eg. 1, 2, 3, 5. 7, 11, 13, 17 ... ) */
#include<stdio.h>
#include<math.h>
int main()
{
    int no,i;//Note:Declared 'i' before the for loop.
    printf("Enter Number to Check:\t");
    scanf("%d",&no);
    for(i=2;i<sqrt(no);i++) //Note:If wrote for(int i=2;i<sqrt(no);i++);
        if(no%i==0)
        break;
    if(i>sqrt(no)) //Then in this line giving error that 'i' is undeclared...
        printf("Entered Number Is Prime!!!");
    else
        printf("Entered Number Is Not Prime!!!");
return 0;
}
