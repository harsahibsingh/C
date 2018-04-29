//Q7. Write a C program to calculate the factorial of given number
#include<stdio.h>
int main()
{
    int no;
    float fac=1;;
    printf("Enter The Number For Which Factorial Need To Calculate: \t");
    scanf("%d",&no);
    if(no==0)
        fac=1;
    else
        {
             for(int i=1;i<=no;i++)
             {

                fac*=i;
             }
        }
    printf("Factorial Of The Entered Number Is: %f",fac);


return 0;
}
