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
std* enqueue1(std*front,std*rear,std*toInsert)
{
    std*p;
    if(front->next==rear)
    {
        toInsert->next=rear;
        toInsert->prev=front;
        front->next=toInsert;
        rear->prev=toInsert;
        return front;
    }
    p=rear->prev;
    toInsert->next=p->next;
    toInsert->prev=p;
    p->next=toInsert;
    rear->prev=toInsert;
    return front;
}
std* enqueue2(std*front,std*rear,std*toInsert)
{
    std*p;
    if(front->next==rear)
    {
        toInsert->next=rear;
        toInsert->prev=front;
        front->next=toInsert;
        rear->prev=toInsert;
        return front;
    }
    toInsert->next=front->next;
    toInsert->prev=front;
    front->next->prev=toInsert;
    front->next=toInsert;
    return front;
}
void display(std*front,std*rear)
{
    std*p=front->next;
    printf("\nDeque\n");
    while(p!=rear)
    {
        printf("(%d) ",p->roll);
        p=p->next;
    }
}
std* dequeue2(std*front,std*rear)
{
    std*p,*q;
    if(front->next==rear)
    {
        printf("Underflow\n");
        return front;
    }
    p=rear->prev;
    q=rear->prev->prev;
    q->next=rear;
    rear->prev=q;
    printf("%d\n",p->roll);
    free(p);
    return front;
}
std* dequeue1(std*front,std*rear)
{
    std*p,*q;
    if(front->next==rear)
    {
        printf("Underflow\n");
        return front;
    }
    p=front->next;
    q=front->next->next;
    front->next=q;
    q->prev=front;
    printf("%d\n",p->roll);
    free(p);
    return front;
}
int main(){
    std*front,*rear,*temp;
    int c,c1;
    front=(std*)malloc(sizeof(std));
    rear=(std*)malloc(sizeof(std));
    front->next=rear;
    rear->prev=front;
    printf("Do you want \n1.Non-restricted queue \n2.Input-restricted queue \n3.Output-restricted queue");
    scanf("%d",&c1);
    if (c1==1){
        printf("choices 1.enqueueback \n2.enqueuefront \n3.dequeuefront \n4.dequeuerear\n");
        scanf("%d",&c);
        while(c!=-1)
        {
            switch(c)
            {
                case 1:
                    temp=createNode();
                    front=enqueue1(front,rear,temp);
                    display(front,rear);
                    break;
                case 2:
                    temp=createNode();
                    front=enqueue2(front,rear,temp);
                    display(front,rear);
                    break;
                case 3:
                    front=dequeue1(front,rear);
                    display(front,rear);
                    break;
                case 4:
                    front=dequeue2(front,rear);
                    display(front,rear);
                    break;
            }
        printf("choices 1.enqueueback \n2.enqueuefront \n3.dequeuefront \n4.dequeuerear\n");
        scanf("%d",&c);
        }
    }
    else if(c1==2)
    {
        printf("choices 1.enqueueback\n2.dequeuefront\n3.dequeuerear\n");
        scanf("%d",&c);
        while(c!=-1)
        {
            switch(c)
            {
                case 1:
                    temp=createNode();
                    front=enqueue1(front,rear,temp);
                    display(front,rear);
                    break;
                case 2:
                    front=dequeue1(front,rear);
                    display(front,rear);
                    break;
                case 3:
                    front=dequeue2(front,rear);
                    display(front,rear);
                    break;
            }
            printf("choices 1.enqueueback\n2.dequeuefront\n3.dequeuerear\n");
            scanf("%d",&c);
        }
    }
    else if(c1==3)
    {
        printf("choices 1.enqueueback\n2.enqueuefront\n3.dequeuefront\n");
        scanf("%d",&c);
        while(c!=-1)
        {
            switch(c)
            {
                case 1:
                    temp=createNode();
                    front=enqueue1(front,rear,temp);
                    display(front,rear);
                    break;
                case 2:
                    temp=createNode();
                    front=enqueue2(front,rear,temp);
                    display(front,rear);
                    break;
                case 3:
                    front=dequeue1(front,rear);
                    display(front,rear);
                    break;
            }
        printf("choices 1.enqueueback\n2.enqueuefront\n3.dequeuefront\n");
        scanf("%d",&c);
        }
    }
    display(front,rear);
    return 0;
}