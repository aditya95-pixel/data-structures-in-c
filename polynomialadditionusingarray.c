#include<stdio.h>
#include<stdlib.h>
struct term{
    int coeff;
    int power;
};
struct poly{
    int n;
    struct term *t; 
};
int main()
{
    struct poly *p,*q,*add;
    int i,j,k;
    p=(struct poly*)malloc(sizeof(struct poly));
    q=(struct poly*)malloc(sizeof(struct poly));
    printf("Enter the no. of terms of first polynomial:");
    scanf("%d",&p->n);
    printf("Enter the no. of terms of second polynomial:");
    scanf("%d",&q->n);
    p->t=(struct term*)malloc(p->n*sizeof(struct term));
    q->t=(struct term*)malloc(q->n*sizeof(struct term));
    add=(struct poly*)malloc(sizeof(struct poly));
    add->t=(struct term*)malloc((p->n+q->n)*sizeof(struct term)); 
    printf("Enter the terms of polynomial 1:\n");
    for(i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->t[i].coeff,&p->t[i].power);
    }
    printf("Enter the terms of polynomial 2:\n");
    for(i=0;i<q->n;i++)
    {
        scanf("%d%d",&q->t[i].coeff,&q->t[i].power);
    }
    k=i=j=0;
    while(i<p->n && j<q->n)
    {
        if(p->t[i].power>q->t[j].power)
        {
            add->t[k++]=p->t[i++];
        }
        else if(p->t[i].power<q->t[j].power)
        {
            add->t[k++]=q->t[j++];
        }
        else{
            add->t[k].coeff=p->t[i].coeff+q->t[j].coeff;
            add->t[k++].power=p->t[i].power;
            i++;
            j++;
        }
    }
    for(;i<p->n;i++)
    {
        add->t[k++]=p->t[i];
    }
    for(;j<q->n;j++)
    {
        add->t[k++]=q->t[j];
    }
    add->n=k;
    printf("Polynomial 1\n");
    for(i=0;i<p->n;i++)
    {
        printf("%dx^%d+",p->t[i].coeff,p->t[i].power);
    }
    printf("\nPolynomial 2\n");
    for(i=0;i<q->n;i++)
    {
        printf("%dx^%d+",q->t[i].coeff,q->t[i].power);
    }
    printf("\nResult polynomial\n");
    for(i=0;i<add->n;i++)
    {
        printf("%dx^%d+",add->t[i].coeff,add->t[i].power);
    }
    free(p);
    free(q);
    free(add);
    return 0;   
}