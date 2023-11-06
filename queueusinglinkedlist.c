#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student{
    int roll;
    char name[10];
    int marks;
    struct Student*next;
};
typedef struct Student std;
std* enqueue(std*front,std*rear,int roll,char name[10],int marks)
{
    std*t=(std*)malloc(sizeof(std));
    t->roll=roll;
    t->marks=marks;
    strcpy(t->name,name);
    t->next=NULL;
    if(front==NULL)
    {
        front=rear=t;
        return front;
    }
    else{
        rear->next=t;
        rear=t;
        return rear;
    }
}
std* dequeue(std*front)
{
    std*t;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("dequeued value is (%d,%s,%d) \n",front->roll,front->name,front->marks);
        t=front;
        front=front->next;
        free(t);
    }
    return front;
}
void display(std *front)
{
    std*p=front;
    while(p)
    {
        printf("(%d,%s,%d) ",p->roll,p->name,p->marks);
        p=p->next;
    }
    printf("\n");
}
int main(){
    int c,val;
    int roll,marks;
    char name[10];
    std*front=NULL,*rear=NULL;
    printf("Enter the choice 1.enqueue 2.dequeue");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("Enter roll no.:");
                scanf("%d",&roll);
                printf("Enter name:");
                scanf("%s",name);
                printf("Enter marks:");
                scanf("%d",&marks);
                if(front==rear && front==NULL){
                front=rear=enqueue(front,rear,roll,name,marks);
                }
                else{
                    rear=enqueue(front,rear,roll,name,marks);
                }
                display(front);
                break;
            case 2:
                front=dequeue(front);
                display(front);
                break;
        }
        printf("\nEnter the choice 1.enqueue 2.dequeue");
        scanf("%d",&c);
    }
}