#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int **mat1,**mat2,**multi,i,j,k,x,row1,row2,col1,col2;
    long int x1,x2;
    printf("Enter no. of rows and columns of matrix1:");
    scanf("%d%d",&row1,&col1);
    printf("Enter no. of rows and columns of matrix2:");
    scanf("%d%d",&row2,&col2);
    if(col1==row2)
    {
        x1=time(NULL);
        mat1=(int**)malloc(row1*sizeof(int*));
        mat2=(int**)malloc(row2*sizeof(int*));
        for(i=0;i<row1;i++)
        {
            mat1[i]=(int*)malloc(col1*sizeof(int));
            for(j=0;j<col1;j++)
            {
                x=rand()%10;
                mat1[i][j]=x;
            }
        }
        for(i=0;i<row2;i++)
        {
            mat2[i]=(int*)malloc(col2*sizeof(int));
            for(j=0;j<col2;j++)
            {
                x=rand()%10;
                mat2[i][j]=x;
            }
        }
        multi=(int**)malloc(row1*sizeof(int*));
        for(i=0;i<row1;i++)
        {
            multi[i]=(int*)malloc(col2*sizeof(int));
            for(j=0;j<col2;j++)
            {
                multi[i][j]=0;
                for(k=0;k<row2;k++)
                {
                    multi[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
        }
        printf("\nFirst matrix\n");
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col1;j++)
            {
                printf("%d ",mat1[i][j]);
            }
            printf("\n");
        }
        printf("\nSecond Matrix\n");
        for(i=0;i<row2;i++)
        {
            for(j=0;j<col2;j++)
            {
                printf("%d ",mat2[i][j]);
            }
            printf("\n");
        }
        printf("\nfinal matrix\n");
        for(i=0;i<row1;i++)
        {
            for(j=0;j<col2;j++)
            {
            printf("%d ",multi[i][j]);
            }
            printf("\n");
        }
        x2=time(NULL);
        printf("the time is %ld",x2-x1);
        free(mat1);
        free(mat2);
        free(multi);
    }
    else{
        printf("Not possible");
    }
    return 0;
}
