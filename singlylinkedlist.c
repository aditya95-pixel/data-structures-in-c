#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int roll;
    struct student *next;
};
typedef struct student std;
std *createNode(){
    std*newNode=(std*)malloc(sizeof(std));
    newNode->next=NULL;
    printf("Enter the roll no. of the student:");
    scanf("%d",&newNode->roll);
    return newNode;
}
std*create(std*header,int n)
{
    int i;
    std*temp,*last;
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
int max(std*header)
{
    int maxo=header->next->roll;
    header=header->next;
    while(header)
    {
        if(header->roll>maxo)
        maxo=header->roll;
        header=header->next;
    }
    return maxo;
}
int min(std*header)
{
    int mino=header->next->roll;
    header=header->next;
    while(header)
    {
        if(header->roll<mino)
        mino=header->roll;
        header=header->next;
    }
    return mino;
}
void insertEnd(std*header,std*toInsert)
{
    while(header->next!=NULL)
    {
        header=header->next;
    }
    header->next=toInsert;
}
void insertBegin(std*header,std*toInsert)
{
    toInsert->next=header->next;
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
        header->next=toInsert;
    }
}
void display(std*header)
{
    std*p=header->next;
    while(p!=NULL)
    {
        printf("(%d)->",p->roll);
        p=p->next;
    }
    printf("NULL");
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
    free(header);
    p->next=NULL;
}
void deleteBegin(std*header)
{
    std*p=header->next->next;
    std*q=header->next;
    header->next=p;
    q->next=NULL;
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
        header=header->next;
        for(i=0;i<pos;i++)
        {
            p=header;
            header=header->next;
        }
        p->next=header->next;
        header->next=NULL;
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
int search(std*header,int key)
{
    int pos=0;
    header=header->next;
    while(header)
    {
        if(key==header->roll)
        {
            return pos;
        }
        header=header->next;
        pos++;
    }
    return -1;
}
void reverse(std*header)
{
    std*p=header,*q=NULL,*t=NULL;
    header=header->next;
    while(header)
    {
        t=q;
        q=header;
        header=header->next;
        q->next=t;
    }
    p->next=q;
}
int main(){
    int i,n,key;
    int pos1,pos2,pos3,pos4,c;
    std*header,*temp;
    header=(std*)malloc(sizeof(header));
    printf("Enter the no. of elements to insert:");
    scanf("%d",&n);
    header=create(header,n);
    printf("\nDisplaying list\n");
    display(header);
    printf("\nEnter choice \n1:count nodes \n2:max \n3:min \n4:search \n5:insert at end \n6:insert at begin \n7:insert before \n8:insert after \n9:delete End \n10:delete Begin \n11:delete Before \n12:delete After\n13:reverse\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("\n%d is the no. of nodes in list\n",count(header));
                break;
            case 2:
                printf("\n%d is the max roll no.\n",max(header));
                break;
            case 3:
                printf("\n%d is the min roll no.\n",min(header));
                break;
            case 4:
                printf("\nEnter the key to search for\n");
                scanf("%d",&key);
                printf("%d is the index",search(header,key));
                break;
            case 5:
                temp=createNode();
                insertEnd(header,temp);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 6:
                temp=createNode();
                insertBegin(header,temp);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 7:
                temp=createNode();
                printf("Enter the position to insert:");
                scanf("%d",&pos1);
                insertBefore(header,temp,pos1);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 8:
                temp=createNode();
                printf("Enter the position to insert:");
                scanf("%d",&pos2);
                insertAfter(header,temp,pos2);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 9:
                deleteEnd(header);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 10:
                deleteBegin(header);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 11:
                printf("Enter the position to delete:");
                scanf("%d",&pos3);
                deleteBefore(header,pos3);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 12:
                printf("Enter the position to delete:");
                scanf("%d",&pos4);
                deleteAfter(header,pos4);
                printf("\nDisplayng list\n");
                display(header);
                break;
            case 13:
                reverse(header);
                printf("\nDisplaying list\n");
                display(header);
                break;
        }
        printf("\nEnter choice \n1:count nodes \n2:max \n3:min \n4:search \n5:insert at end \n6:insert at begin \n7:insert before \n8:insert after \n9:delete End \n10:delete Begin \n11:delete Before \n12:delete After\n13:reverse\n");
        scanf("%d",&c);
    }
    destroy(header);
    display(header);
    return 0;
}