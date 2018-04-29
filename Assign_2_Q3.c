//Q3. Implement a system to calculate the Grade of the student based on marks in n subjects.
#include<stdio.h>
int main()
{
    int n;
    char str[20];
    float marks,sum=0,avg;
    char grade;
    printf("Enter The Number Of Subjects:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Subject:\t");
        scanf("%s",str);//Note: To Input String "&" is not used....
        printf("Enter Marks:\t");
        scanf("%f",&marks);
        sum+=marks;
    }
    avg=sum/n;
    if(avg>=85)
        grade='A';
    else if(avg>=75 && avg<85)
        grade='B';
    else if(avg>=65 && avg<75)
        grade='C';
    else if(avg>=55 && avg<65)
        grade='D';
    else if(avg>=35 && avg<55)
        grade='E';
    else if(avg<35)
        grade='F';
    printf("Your Final Grade Is: %c",grade);

return 0;
}
