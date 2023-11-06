#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,*P,*Q,k,*R,col,j;
    printf("Enter the no. of rows/columns:");
    scanf("%d",&n);
    P=(int*)malloc(n*sizeof(int));
    Q=(int*)malloc(n*sizeof(int));
    R=(int*)malloc(n*sizeof(int));
    printf("\nEnter colmuns where 1 is stored row-wise of P\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the column position of 1 in row %d\n",i);
        scanf("%d",&col);
        P[i]=col;  
    }
    printf("\nEnter columns where 1 is stored row-wise of Q\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the column position of 1 in row %d\n",i);
        scanf("%d",&col);
        Q[i]=col;  
    }
    for(i=0;i<n;i++)
    {
        R[i]=Q[P[i]]; //multiplication done in O(n)
    }
    printf("\nR\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",R[i]);
    }
    printf("\nMultiplied matrix\n");
    for(i=0;i<n;i++)
    {
        printf("1 is stored in column %d of row %d\n",R[i],i);
    }
    free(P);
    free(Q);
    free(R);
    return 0;
}