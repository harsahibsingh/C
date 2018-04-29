//Q1. Implement a choice based arithmetic calculator (1-add,2-sub,3-mul,4-div etc), by implementing functions.
#include<stdio.h>
float add(float,float);
float sub(float,float);
float mul(float,float);
float div(float,float);
int main()
{
    float num1,num2,res;
    int ch;
    printf("*****Arithmetic Calculator Program*****\n");
    printf("Enter 1st Number:\t");
    scanf("%f",&num1);
    printf("Enter 2nd Number:\t");
    scanf("%f",&num2);
    printf("Enter The Operation To Perform\n");
    printf(" 1.ADD\n 2.SUB\n 3.MUL\n 4.DIV\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: res=add(num1,num2);
                printf("Result Of Operation Is:%f",res);
                break;
        case 2: res=sub(num1,num2);
                printf("Result Of Operation Is:%f",res);
                break;
        case 3: res=mul(num1,num2);
                printf("Result Of Operation Is:%f",res);
                break;
        case 4: res=div(num1,num2);
                printf("Result Of Operation Is:%f",res);
                break;
        default: printf("Invalid Choice\n");
    }

return 0;
}
float add(float x,float y)
{
return (x+y);
}
float sub(float x,float y)
{
return (x-y);
}
float mul(float x,float y)
{
return (x*y);
}
float div(float x,float y)
{
return (x/y);
}
