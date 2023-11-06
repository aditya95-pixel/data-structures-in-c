//Emulating 2d array as 1d array
/*formulae used
row major
k=j+(i*n)
column major
k=i+(j*m)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int**mat,*arr1,*arr2;
    int i,j,m,n;
    printf("Enter the no. of rows and columns:");
    scanf("%d%d",&m,&n);
    mat=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        mat[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    arr1=(int*)malloc(m*n*sizeof(int));
    arr2=(int*)malloc(m*n*sizeof(int));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            arr1[i*n+j]=mat[i][j];
            arr2[j*m+i]=mat[i][j];
        }
    }
    printf("\nMatrix using row major\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr1[i*n+j]);
        }
        printf("\n");
    }
    printf("\nMatrix using column major\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr2[j*m+i]);
        }
        printf("\n");
    }
    free(mat);
    free(arr1);
    free(arr2);
    return 0;
}
