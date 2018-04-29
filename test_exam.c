#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct student
{
	char name[20];
	int rollno;
	int marks;
}stu;
void push(stu *arr,int *top);
void  inp(stu *arr,int *top);
void display(stu *arr,int *top);
void pop(stu *arr,int *top);

int main()
{
	int n;
	int top=-1;
	stu arr[size];
		while(1)
	{
	printf("Enter: \n1. To push student detail in Stack\n2. To Pop student detail in Stack\n3. To Display TOP student detail in Stack\n4. To Exit\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("Enter the Student detail to push in stack\n");
			push(arr,&top);
			break;

		case 2:
			pop(arr,&top);
			break;

		case 3:
			printf("");
			display(arr,&top);
			break;
		case 4:
			exit(0);

		default:
			printf("Invalid Entry!\n");

	}
}
}
void push(stu *arr,int *top)
{
	if(*top==size-1)
	{
		printf("Stack is Full!\n");
		return;
	}
	(*top)++;
	inp(arr,top);

}

void display(stu *arr,int *top)
{
	if(*top==-1)
	{
		printf("Stack is Empty!\n");
		return;
	}
	printf("Top element\n",arr[*top]);
	printf("Student Name: %s\n",arr[*top].name);
	printf("Roll No.: %d\n",arr[*top].rollno);
	printf("Marks: %d\n",arr[*top].marks);

}
void inp(stu *arr,int *top)
{

	printf("Enter Student Name\n");
	scanf("%s",arr[*top].name);
	printf("Enter Student Roll no.\n");
	scanf("%d",&arr[*top].rollno);
	printf("Enter Student Marks\n");
	scanf("%d",&arr[*top].marks);
	return;
}
void pop(stu *arr,int *top)
{
	if(*top==-1)
	{
		printf("Stack is Empty!\n");
		return;
	}
	arr[*top]={NULL};
	(*top)--;
	printf("Element Popped!\n");
	return;
}
