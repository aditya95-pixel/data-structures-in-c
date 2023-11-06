#include<stdio.h>
#include<stdlib.h>
int max(int arr[],int n)
{
    int m=arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i]>m)
            m=arr[i];
    return m;
}
void countsort(int arr[], int n, int exp,int k)
{
    int *output=(int*)malloc(n*sizeof(int));
    int i,*count=(int*)calloc(k,sizeof(int));
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
    free(count);
}
void radixsort(int arr[], int n)
{
    int m = max(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countsort(arr, n, exp,m);
}
int main()
{
    int *arr,n,i;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter 3 digit numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    radixsort(arr,n);
    printf("sorted array is\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}