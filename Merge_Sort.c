#include<stdio.h>
void merge_sort(int a[],int);
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

    merge_sort(arr,n);
    printf("Array After Merge Sorting\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

return(0);

}
void merge_sort(int a[],int size)
{
    int p,q,r,n1,n2,i,j,k;
    p=0;//starting index of array
    q=(size-1)/2;//middle element of array
    r=size-1;//last element of array
    n1=q-p+1;
    n2=r-q;
    int a1[n1],a2[n2];
    for(i=0;i<n1;i++)
    {
        a1[i]=a[i];
    }
    a1[n1+1]=9999;
    for(j=0;j<n2;j++)
    {
        a2[j]=a[j+q+1];
    }
    a2[n2+1]=9999;
    i=0,j=0;
    for(k=0;k<size;k++)
    {
        if(a1[i]<a2[j])
        {
            a[k]=a1[i];
            i++;
        }
        else
        {
            a[k]=a2[j];
            j++;
        }
    }

}
