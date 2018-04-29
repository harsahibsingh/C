/* Q6. Implement a C program to print Fibonacci series
 ( 0, 1, 1, 2, 3, 5, 8,13, 21, 34 ..... )*/
 #include<stdio.h>
 int main()
 {
     int n,p=1,q=0,next=0,i;
     printf("Enter The Numbers In The Fibonacci Series:\t");
     scanf("%d",&n);
     if(n==0)
        printf("0");
     else if(n==1)
        printf("0, 1");
     else
     {
        printf("0, 1, ");
       for(i=2;i<n;i++)
       {
        next=p+q;
        q=p;
        p=next;
        printf("%d, ",next);
       }
     }

return 0;
 }
