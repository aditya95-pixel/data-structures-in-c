#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int roll;
    struct student *next;
    struct student *prev;
};
typedef struct student std;
std *createNode(){
    std*newNode=(std*)malloc(sizeof(std));
    newNode->next=NULL;
    newNode->prev=NULL;
    printf("Enter the roll no. of the student:");
    scanf("%d",&newNode->roll);
    return newNode;
}
std*create(std*header,int n)
{
    int i;
    std*temp,*last;
    header->next=header->prev=NULL;
    last=header;
    for(i=0;i<n;i++)
    {
        temp=createNode();
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
    return header;
}
int count(std*header)
{
    int c=0;
    std*p=header->next;
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}
void insertEnd(std*header,std*toInsert)
{
    while(header->next!=NULL)
    {
        header=header->next;
    }
    header->next=toInsert;
    toInsert->prev=header;
}
void insertBegin(std*header,std*toInsert)
{
    toInsert->next=header->next;
    toInsert->prev=header;
    header->next->prev=toInsert;
    header->next=toInsert;
}
void insertBefore(std*header,std*toInsert,int pos)
{
    int i;
    if(pos<0 || pos>count(header))
    {
        return;
    }
    else{
        for(i=0;i<pos-1;i++)
        {
            header=header->next;
        }
        toInsert->next=header->next;
        toInsert->prev=header;
        header->next->prev=toInsert;
        header->next=toInsert;
    }
}
void insertAfter(std*header,std*toInsert,int pos)
{
    int i;
    if(pos<0 || pos>count(header))
    {
        return;
    }
    else{
        for(i=0;i<pos;i++)
        {
            header=header->next;
        }
        toInsert->next=header->next;
        toInsert->prev=header;
        header->next->prev=toInsert;
        header->next=toInsert;
    }
}
void display(std*header)
{
    std*p=header->next;
    printf("\nDisplaying in forward direction\n");
    while(p!=NULL)
    {
        printf("(%d)->",p->roll);
        p=p->next;
    }
    printf("NULL");
}
void displayreverse(std*header)
{
    std*p=header;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("\nDisplaying list in backward direction\nNULL->");
    while(p->prev!=header)
    {
        printf("(%d)->",p->roll);
        p=p->prev;
    }
    printf("(%d)",p->roll);
}
void deleteEnd(std*header)
{
    std*p=NULL;
    while(header->next!=NULL)
    {
        p=header;
        header=header->next;
    }
    header->next=NULL;
    header->prev=NULL;
    free(header);
    p->next=NULL;
}
void deleteBegin(std*header)
{
    std*p=header->next->next;
    std*q=header->next;
    header->next=p;
    p->prev=header;
    q->next=NULL;
    q->prev=NULL;
    free(q);
}
void deleteBefore(std*header,int pos)
{
    std*p=NULL;
    int i;
    if(pos<1 || pos>count(header))
    {
        return ;
    }
    else{
        header=header->next;
        for(i=0;i<pos-1;i++)
        {
            p=header;
            header=header->next;
        }
        p->next=header->next;
        header->next->prev=p;
        header->next=header->prev=NULL;
        free(header);
    }
}
void deleteAfter(std*header,int pos)
{
    std*p=NULL;
    int i;
    if(pos<1 || pos>count(header))
    {
        return ;
    }
    else{
        header=header->next;
        for(i=0;i<pos;i++)
        {
            p=header;
            header=header->next;
        }
        p->next=header->next;
        header->next->prev=p;
        header->next=header->prev=NULL;
        free(header);
    }
}
void destroy(std*header)
{
    std*p=NULL,*q=header;
    header=header->next;
    while(header!=NULL)
    {
        p=header;
        header=header->next;
        p->next=NULL;
        free(p);
    }
    q->next=NULL;
}
int main(){
    int i,n,key;
    int pos1,pos2,pos3,pos4,c;
    std*header,*temp;
    header=(std*)malloc(sizeof(header));
    printf("Enter the no. of elements to insert:");
    scanf("%d",&n);
    header=create(header,n);
    display(header);
    displayreverse(header);
    printf("\nEnter choice \n1:count nodes\n2:insert at end\n3:insert at begin\n4:insert before\n5:insert after\n6:delete End\n7:delete Begin\n8:delete Before\n9:delete After\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("\n%d is the no. of nodes in list\n",count(header));
                break;
            case 2:
                temp=createNode();
                insertEnd(header,temp);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 3:
                temp=createNode();
                insertBegin(header,temp);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 4:
                temp=createNode();
                printf("Enter the position to insert:");
                scanf("%d",&pos1);
                insertBefore(header,temp,pos1);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 5:
                temp=createNode();
                printf("Enter the position to insert:");
                scanf("%d",&pos2);
                insertAfter(header,temp,pos2);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 6:
                deleteEnd(header);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 7:
                deleteBegin(header);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 8:
                printf("Enter the position to delete:");
                scanf("%d",&pos3);
                deleteBefore(header,pos3);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 9:
                printf("Enter the position to delete:");
                scanf("%d",&pos4);
                deleteAfter(header,pos4);
                printf("\nDisplayng list\n");
                display(header);
                break;
        }
        printf("\nEnter choice \n1:count nodes\n2:insert at end\n3:insert at begin\n4:insert before\n5:insert after\n6:delete End\n7:delete Begin\n8:delete Before\n9:delete After\n");
        scanf("%d",&c);
    }
    destroy(header);
    display(header);
    return 0;
}