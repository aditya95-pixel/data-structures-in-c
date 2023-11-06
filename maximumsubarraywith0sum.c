#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr;
    int n,i,maxlen=0,j,sum,pos=-1;
    printf("Enter the no. of terms:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==0)
            {
                if(maxlen<j-i+1)
                {
                    maxlen=j-i+1;
                    pos=i;
                }
            }

        }
    }
    if(pos!=-1){
    printf("Max subarray is \n");
    for(i=pos;i<pos+maxlen;i++)
    {
        printf("%d ",arr[i]);
    }
    }
    printf("\n");
    printf("%d is the maximum length",maxlen);
    free(arr);
    return 0;
}
