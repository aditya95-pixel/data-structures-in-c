#include<stdio.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int power;
};
int main()
{
    struct poly *p,*q,*add;
    int m,n,i,j,k;
    printf("Enter the no. of terms of polynomial p:");
    scanf("%d",&m);
    p=(struct poly*)malloc(m*sizeof(struct poly));
    printf("Enter the no. of terms of polynomial q:");
    scanf("%d",&n);
    q=(struct poly*)malloc(n*sizeof(struct poly));
    add=(struct poly*)malloc((m+n)*sizeof(struct poly));
    printf("Enter polynomial 1\n");
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&p[i].coeff,&p[i].power);
    }
    printf("Enter polynomial 2\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&q[i].coeff,&q[i].power);
    }
    k=0;
    i=0;
    j=0;
    while(i<m && j<n)
    {
        if(p[i].power>q[j].power)
        {
            add[k].coeff=p[i].coeff;
            add[k++].power=p[i++].power;
        }
        else if(p[i].power<q[j].power)
        {
            add[k].coeff=q[j].coeff;
            add[k++].power=q[j++].power;
        }
        else{
            add[k].coeff=p[i].coeff+q[j].coeff;
            add[k++].power=p[i].power;
            i++;
            j++;
        }
    }
    for(;i<m;i++)
    {
        add[k].coeff=p[i].coeff;
        add[k++].power=p[i].power;
    }
    for(;j<n;j++)
    {
        add[k].coeff=q[j].coeff;
        add[k++].power=q[j].power;
    }
    printf("polynomial 1\n");
    for(i=0;i<m;i++)
    {
        printf("%dx^%d+",p[i].coeff,p[i].power);
    }
    printf("\npolynomial 2\n");
    for(i=0;i<n;i++)
    {
        printf("%dx^%d+",q[i].coeff,q[i].power);
    }
    printf("\nAdded\n");
    for(i=0;i<k;i++)
    {
        printf("%dx^%d+",add[i].coeff,add[i].power);
    }
    free(add);
    free(p);
    free(q);
    return 0;
}