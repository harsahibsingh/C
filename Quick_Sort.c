#include<stdio.h>
int partioning_algo(int a[],int,int);
void quick_sort(int a[],int,int);
int main()
{
     int i,n;
    printf("Enter Array Size\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Entered Array Is\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
    quick_sort(arr,0,n-1);
    printf("\nArray After Quick Sorting\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }


return 0;
}

int partioning_algo(int a[],int start, int size)
{
    int i,j,r,temp,pivot,p;
    p=start;
    r=size;
    i=start-1;
    j=start;
    pivot=a[r];
    for(j=start;j<=r-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }

    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
return(i+1);
}
void quick_sort(int a[],int start,int size)
{
    int p,r,q;
    p=start;
    r=size;
    if(p<r)
    {
        q=partioning_algo(a,p,r);//p as left element and r as right element
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);

    }
}
