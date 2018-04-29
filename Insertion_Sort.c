#include<stdio.h>
void insertion_sort(int a[],int);
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
    insertion_sort(arr,n);

    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

return 0;
}
void insertion_sort(int a[],int size)
{
    int i,j,key;
    for(j=1;j<size;j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}
