//Q4. Implement a C program to calculate GCD and LCM of 2 input number.
//Note: LCM*GCD=Product Of The Numbers.
#include<stdio.h>
int GCD(int,int);
int main()
{
    int num1,num2,l,g;
    printf("Enter The 1st Number:\t");
    scanf("%d",&num1);
    printf("Enter The 2nd Number:\t");
    scanf("%d",&num2);
    g=GCD(num1,num2);
    l=(num1*num2)/g;
    printf("LCM Of The Entered Numbers Is: %d\n",l);
    printf("GDC Of The Entered Numbers Is: %d\n",g);


return 0;
}
int GCD(int x,int y)
{
    int rem;
    if(x%y==0)
        return y;
    else
        {
        rem=x%y;
        GCD(y,rem);//Recursive Euclid's Approach

        }
}
