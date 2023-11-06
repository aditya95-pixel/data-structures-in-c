#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *A,*B,*C1,*C2,*C,i,k1,k2,n,m,j,c;
    printf("Enter the no. of elements of array1:");
    scanf("%d",&n);
    printf("Enter the no. of elements of array1:");
    scanf("%d",&m);
    A=(int*)malloc(n*sizeof(int));
    B=(int*)malloc(m*sizeof(int));
    C1=(int*)malloc(n*sizeof(int));
    C2=(int*)malloc(m*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
    }
    printf("\nFirst array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\nSecong Array\n");
    for(i=0;i<m;i++)
    {
        printf("%d ",B[i]);
    }
    k1=0;
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=0;j<m;j++)
        {
            if(A[i]==B[j])
            {
                c+=1;
                j=m;
            }
        }
        if(c==0)
        {
            C1[k1++]=A[i];
        }
    }
    k2=0;
    for(i=0;i<m;i++)
    {
        c=0;
        for(j=0;j<n;j++)
        {
            if(B[i]==A[j])
            {
                c+=1;
                j=m;
            }
        }
        if(c==0)
        {
            C2[k2++]=B[i];
        }
    }
    C=(int*)malloc((k1+k2)*sizeof(int));
    for(i=0;i<k1;i++)
    {
        C[i]=C1[i];
    }
    for(j=0,i=k1;i<k1+k2;i++,j++)
    {
        C[i]=C2[j];
    }
    printf("\nFinal Array\n");
    for(i=0;i<k1+k2;i++)
    {
        printf("%d ",C[i]);
    }
    free(A);
    free(B);
    free(C1);
    free(C2);
    free(C);
    return 0;
}
