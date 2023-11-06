#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int*b)
{
    *b=*b+*a;
    *a=*b-*a;
    *b=*b-*a;
}
void reverse(int*arr,int n)
{
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--)
    {
        swap(&arr[i],&arr[j]);
    }
}
int main()
{
    int *arr,n,i;
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    reverse(arr,n);
    printf("\nReversed Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}