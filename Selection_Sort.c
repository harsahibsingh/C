#include<stdio.h>
void select_sort(int a[],int );
int main()
{
    int n,i,ele;
    printf("Enter The Array size\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);//&ele);
        //arr[i]=ele;
    }
    printf("Array Entered is:\n");
     for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\nArray after performing Selection Sorting is:\n");
    select_sort(arr,n);

    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }


return 0;
}
void select_sort(int a[],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        int min=i;
        for(j=i+1;j<size;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
