//Q6. Write a C program to find out sum & average of n numbers.
#include<stdio.h>
int main()
{
    int n,no,sum=0;
    float avg;
    printf("Enter the range:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&no);
        sum+=no;

    }
    avg=sum/n;
    printf("Sum Of Entered Numbers is: %d \n",sum);
    printf("Average Of Entered Numbers is: %f \n",avg);
return 0;
}
