#include<stdio.h>
#include<stdlib.h>
struct sparse{
    int row;
    int col;
    int data;
};
int main()
{
    int **mat,m,n,i,j,counter=0,k=1,len=0;
    struct sparse *s,*transpose,temp;
    printf("Enter the no. of rows and columns:");
    scanf("%d%d",&m,&n);
    mat=(int**)malloc(m*sizeof(int));
    printf("Enter the elements:\n");
    for(i=0;i<m;i++)
    {
        mat[i]=(int*)malloc(m*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0)
            counter++;
        }
    }
    s=(struct sparse*)malloc((counter+1)*sizeof(struct sparse));
    transpose=(struct sparse*)malloc((counter+1)*sizeof(struct sparse));
    s[0].row=transpose[0].row=m;
    s[0].col=transpose[0].col=n;
    s[0].data=transpose[0].data=counter;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]!=0){
                s[k].row=i;
                s[k].col=j;
                s[k++].data=mat[i][j];
            }
        }
    }
    len=k;
    printf("The sparse matrix is\n");
    for(i=0;i<len;i++)
    {
        printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].data);
    }
    k=1;
    printf("Matrix printed\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==s[k].row && j==s[k].col)
            {
                printf("%d\t",s[k++].data);
            }
            else printf("0\t");
        }
        printf("\n");
    }
    for(i=1;i<len;i++)
    {
        transpose[i].row=s[i].col;
        transpose[i].col=s[i].row;
        transpose[i].data=s[i].data;
    }
    for(i=1;i<len;i++)
    {
        for(j=1;j<len-i;j++)
        {
            if(transpose[j].row>transpose[j+1].row)
            {
                temp=transpose[j];
                transpose[j]=transpose[j+1];
                transpose[j+1]=temp;
            }
            else if(transpose[j].row==transpose[j+1].row && transpose[j].col>transpose[j+1].col)
            {
                temp=transpose[j];
                transpose[j]=transpose[j+1];
                transpose[j+1]=temp;
            }
        }
    }
    k=1;
    printf("Sparse matrix representation of transpose is \n");
    for(i=0;i<len;i++)
    {
        printf("%d\t%d\t%d\n",transpose[i].row,transpose[i].col,transpose[i].data);
    }
    printf("Transposed matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==transpose[k].row && j==transpose[k].col)
            {
                printf("%d\t",transpose[k++].data);
            }
            else printf("0\t");
        }
        printf("\n");
    }
    free(mat);
    free(s);
    free(transpose);
    return 0;
}
