#include<stdio.h>
void bubble_sort(int a[],int);
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
    bubble_sort(arr,n);

    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

return 0;
}
void bubble_sort(int a[],int size)
{
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }
}
