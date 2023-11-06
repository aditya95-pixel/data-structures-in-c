#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int power;
    struct node *next;
};
typedef struct node node;
node* createNode(){
    node*newNode=(node*)malloc(sizeof(node));
    newNode->next=NULL;
    printf("Enter the coeff and power:");
    scanf("%d%d",&newNode->coeff,&newNode->power);
    return newNode;
}
node * create(node*header,int n){
    int i;
    node*temp,*last;
    header->next=NULL;
    last=header;
    for(i=0;i<n;i++)
    {
        temp=createNode();
        last->next=temp;
        last=temp;
    }
    return header;
}
node *add(node*header1,node*header2,node*header3)
{
    node*p=header3;
    node*temp;
    header1=header1->next;
    header2=header2->next;
    while(header1!=NULL && header2!=NULL)
    {
        if(header1->power>header2->power)
        {
            temp=(node*)malloc(sizeof(node));
            temp->power=header1->power;
            temp->coeff=header1->coeff;
            header3->next=temp;
            header3=temp;
            header1=header1->next;
        }
        else if(header1->power<header2->power)
        {
            temp=(node*)malloc(sizeof(node));
            temp->power=header2->power;
            temp->coeff=header2->coeff;
            header3->next=temp;
            header3=temp;
            header2=header2->next;
        }
        else{
            temp=(node*)malloc(sizeof(node));
            temp->power=header1->power;
            temp->coeff=header1->coeff+header2->coeff;
            header3->next=temp;
            header3=temp;
            header2=header2->next;
            header1=header1->next;
        }
    }
    while(header1)
    {
        temp=(node*)malloc(sizeof(node));
        temp->power=header1->power;
        temp->coeff=header1->coeff;
        header3->next=temp;
        header3=temp;
        header1=header1->next;
    }
    while(header2)
    {
        temp=(node*)malloc(sizeof(node));
        temp->power=header2->power;
        temp->coeff=header2->coeff;
        header3->next=temp;
        header3=temp;
        header2=header2->next;
    }
    return p;
}
void display(node* header)
{
    header=header->next;
    while(header)
    {
        printf("%dx^%d+",header->coeff,header->power);
        header=header->next;
    }
}
int main()
{
    int m,n;
    node*header1,*header2,*header3;
    header1=(node*)malloc(sizeof(node));
    header2=(node*)malloc(sizeof(node));
    header3=(node*)malloc(sizeof(node));
    printf("Enter the no. of terms of polynomial 1:");
    scanf("%d",&m);
    printf("Enter the no. of terms of polynomial 2:");
    scanf("%d",&n);
    create(header1,m);
    create(header2,n);
    printf("\nFirst polynomial is\n");
    display(header1);
    printf("\nSecond polynomial is\n");
    display(header2);
    header3=add(header1,header2,header3);
    printf("\nAdded polynomial is\n");
    display(header3);
    return 0;
}