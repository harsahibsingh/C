#include<stdio.h>
void heap_sort(int a[],int);
void max_heap(int ar[],int,int);
int main()
{
    int n,i;
    printf("Enter Array Size\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("Entered Array Is:\n");
    for(i=0;i<n;i++)
        printf(" %d ",arr[i]);
    heap_sort(arr,n);

    printf("\nArray after Sorting Is:\n");
    for(i=0;i<n;i++)
        printf(" %d ",arr[i]);

return (0);
}
void heap_sort(int a[],int size)
{
    int n,temp;
    for(n=size/2-1;n>=0;n--)
        max_heap(a,n,size);

    for (int i=size-1; i>=0; i--)
    {
        // Move current root to end
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        // call max heapify on the reduced heap
        max_heap(a,0,i);
    }
}

void max_heap(int ar[],int i,int length)
{
    int l,r,largest,temp;
    l=2*i+1;
    r=2*i+2;
    if(l<length&&ar[l]>ar[i])
        largest=l;
    else
        largest=i;
    if(r<length&&ar[r]>ar[largest])
        largest=r;
    if(largest!=i)
    {
        temp=ar[i];
        ar[i]=ar[largest];
        ar[largest]=temp;
        max_heap(ar,largest,length);

    }
}
