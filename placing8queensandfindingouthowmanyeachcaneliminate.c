#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct queenpos{
    int row;
    int col;
};
int abs(int a)
{
    if(a<0)
    {
        return (-1)*a;
    }
    else return a;
}
int main()
{
    int arr[8]={0};
    int i,j,c1=0,c2=0,c3=0,c4=0,d1=0,d2=0,d3=0,d4=0,diff1,diff2,row1,col1,c;
    struct queenpos *q;
    q=(struct queenpos *)malloc(8*sizeof(struct queenpos));
    srand(time(NULL));
    i=0;
    while(i<8){
        row1=rand()%8;
        col1=rand()%8;
        c=0;
        if(i==0)
        {
            q[0].row=row1;
            q[0].col=col1;
            i++;
        }
        else{
            for(j=0;j<i;j++)
            {
                if(row1==q[j].row && col1==q[j].col)
                {
                    c++;
                }
            }
            if(c==0)
            {
                q[i].row=row1;
                q[i].col=col1;
                i++;
            }
        }
    }
    printf("The positions are:\n");
    for(i=0;i<8;i++)
    {
        printf("(%d,%d)\n",q[i].row,q[i].col);
    }
    for(i=0;i<8;i++)
    {
        c1=c2=c3=c4=d1=d2=d3=d4=0;
        for(j=0;j<8;j++)
        {
            if(i!=j){
                if(q[i].row==q[j].row && q[i].col<q[j].col && c1==0)
                {
                    c1++;
                }
                else if(q[i].row==q[j].row && q[i].col>q[j].col && c2==0)
                {
                    c2++;
                }
                else if(q[i].col==q[j].col && q[i].row<q[j].row && c3==0)
                {
                    c3++;
                }
                else if(q[i].col==q[j].col && q[i].row>q[j].row && c4==0)
                {
                    c4++;
                }
                else{
                    diff1=q[i].row-q[j].row;
                    diff2=q[i].col-q[j].col;
                    if(abs(diff1)==abs(diff2) && q[i].row>q[j].row && q[i].col>q[j].col && d1==0)
                    {
                        d1++;
                    }
                    else if(abs(diff1)==abs(diff2) && q[i].row>q[j].row && q[i].col<q[j].col && d2==0)
                    {
                        d2++;
                    }
                    else if(abs(diff1)==abs(diff2) && q[i].row<q[j].row && q[i].col<q[j].col && d3==0)
                    {
                        d3++;
                    }
                    else if(abs(diff1)==abs(diff2) && q[i].row<q[j].row && q[i].col>q[j].col && d4==0)
                    {
                        d4++;
                    }
                }
            }
        }
        arr[i]=c1+c2+c3+c4+d1+d2+d3+d4;
    }   
    for(i=0;i<8;i++)
    {
        printf("queen at (%d,%d) pos can capture %d queens and can be itself be captured by %d queens\n",q[i].row,q[i].col,arr[i],arr[i]);
    }
    free(q);
    return 0;
}
