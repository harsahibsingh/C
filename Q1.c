#include<stdio.h>
int add(int,int);
int sub(int,int);
//Q1_A.Implement Calculator using function pointers???
int mul(int,int);
int div(int,int);

int main()
{
	int val1,val2;
	printf("\n*****Calculator Using Function Pointer****\n");
	printf("Enter first value:\t");
	scanf("%d",&val1);
	printf("Enter second value:\t");
	scanf("%d",&val2);

	int (*fptr)(int,int);//function pointer
	fptr=add;//passing address of add()function to function pointer
	int add_res=fptr(val1,val2);
	printf("Addition Result is: %d\n",add_res);
	fptr=sub;//passing address of sub()function to function pointer
	int sub_res=fptr(val1,val2);
	printf("Subtraction Result is: %d\n",sub_res);
	fptr=mul;//passing address of mul()function to function pointer
	int mul_res=fptr(val1,val2);
	printf("Multiplication Result is: %d\n",mul_res);
	fptr=div;//passing address of add()function to function pointer
	int div_res=fptr(val1,val2);
	printf("Division Result is: %d\n",div_res);

return 0;
}

int add(int x,int y)
{
return(x+y);
}
int sub(int x,int y)
{
return(x-y);
}
int mul(int x,int y)
{
return(x*y);
}
int div(int x,int y)
{
return(x/y);
}
