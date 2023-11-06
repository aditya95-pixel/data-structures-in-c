#include<stdio.h>
#include<stdlib.h>
struct student{
    int roll;
    struct student *next;
    struct student *prev;
};
typedef struct student std;
std *createNode(){
    std*newNode=(std*)malloc(sizeof(std));
    printf("Enter the roll no. of the student:");
    scanf("%d",&newNode->roll);
    return newNode;
}
std*create(std*header,int n)
{
    int i;
    std*temp,*last;
    header->next=header->prev=header;
    last=header;
    for(i=1;i<n;i++)
    {
        temp=createNode(header);
        temp->next=last->next;
        temp->prev=last;
        last->next=temp;
        header->prev=temp;
        last=temp;
    }
    return header;
}
int count(std*header)
{
    int c=0;
    std*p=header;
    do
    {
        p=p->next;
        c++;
    }while(p!=header);
    return c;
}
void insertEnd(std*header,std*toInsert)
{
    std*p=header;
    while(header->next!=p)
    header=header->next;
    toInsert->next=p;
    p->prev=toInsert;
    header->next=toInsert;
    toInsert->prev=header;
}
std* insertBegin(std*header,std*toInsert)
{
    std*p=header;
    while(header->next!=p)
    {
        header=header->next;
    }
    toInsert->next=p;
    p->prev=toInsert;
    header->next=toInsert;
    toInsert->prev=header;
    return toInsert;
}
void insertBefore(std*header,std*toInsert,int pos)
{
    int i;
    if(pos<0 || pos>count(header))
    {
        return;
    }
    else{
        for(i=0;i<pos-2;i++)
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
void display(std*header)
{
    printf("\nPrinting in forward direction\n");
    std*p=header;
    do
    {
        printf("(%d)->",p->roll);
        p=p->next;
    }
    while(p!=header);
    printf("(%d)",header->roll);
}
void deleteEnd(std*header)
{
    std*p=NULL,*q=header;
    while(header->next!=q)
    {
        p=header;
        header=header->next;
    }
    p->next=q;
    q->prev=p;
    header->next=header->prev=NULL;
    free(header);
}
std* deleteBegin(std*header)
{
    std*p=NULL,*q=header,*t=q->next;
    while(header->next!=q)
    {
        header=header->next;
    }
    header->next=t;
    t->prev=header;
    free(q);
    return t;  
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
        for(i=0;i<pos-1;i++)
        {
            p=header;
            header=header->next;
        }
        p->next=header->next;
        header->next->prev=p;
        header->next=NULL;
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
        for(i=0;i<pos;i++)
        {
            p=header;
            header=header->next;
        }
        p->next=header->next;
        header->next->prev=p;
        header->next=NULL;
        free(header);
    }
}
void destroy(std*header)
{
    std*p=NULL,*q=header;
    while(p!=header)
    {
        p=q;
        q=q->next;
        p->next=NULL;
        free(p);
    }
}
void displayreverse(std*header)
{
    std*p=header;
    printf("\nDisplaying in reverse direction\n");
    do{
        printf("(%d)->",p->roll);
        p=p->prev;
    }while(p!=header);
    printf("(%d)",header->roll);
}
int main(){
    int i,n,key;
    int pos1,pos2,pos3,pos4,c;
    std*header,*temp;
    header=createNode();
    printf("Enter the no. of elements to insert:");
    scanf("%d",&n);
    header=create(header,n);
    display(header);
    displayreverse(header);
    printf("\nEnter choice \n1:count nodes \n2:insert at end \n3:insert at begin \n4:insert before \n5:insert after \n6:delete end\n7:delete Begin\n8:delete Before\n9:delete After\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("\n%d is the no. of nodes in list\n",count(header));
                break;
            case 2:
                temp=createNode(header);
                insertEnd(header,temp);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 3:
                temp=createNode(header);
                header=insertBegin(header,temp);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 4:
                temp=createNode(header);
                printf("Enter the position to insert:");
                scanf("%d",&pos1);
                insertBefore(header,temp,pos1);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 5:
                temp=createNode(header);
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
                header=deleteBegin(header);
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
        printf("\nEnter choice \n1:count nodes \n2:insert at end \n3:insert at begin \n4:insert before \n5:insert after \n6:delete end\n7:delete Begin\n8:delete Before\n9:delete After\n");
        scanf("%d",&c);
    }
    displayreverse(header);
    destroy(header);
    return 0;
}
