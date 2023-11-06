#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student{
    int roll;
    char name[10];
    int marks;
};
struct Queue{
    struct Student *s;
    int front;
    int rear;
    int n;
};
typedef struct Student std;
typedef struct Queue Queue;
int isempty(Queue*q)
{
    if(q->front==q->rear)
    return 1;
    else
    return 0;
}
int isfull(Queue*q)
{
    if((q->rear+1)%q->n==q->front)
    return 1;
    return 0;
}
void enqueue(Queue*q,int roll,char name[10],int marks)
{
    if(isfull(q)==1){
        printf("Queue is full\n");
        return ;
    }
    else{
        q->rear=(q->rear+1)%q->n;
        q->s[q->rear].roll=roll;
        q->s[q->rear].marks=marks;
        strcpy(q->s[q->rear].name,name);
    }
}
void dequeue(Queue*q)
{
    int val;
    if(isempty(q)==1){
    return ;
    }
    else{
        q->front=(q->front+1)%q->n;
        printf("\ndequeued value is (%d,%s,%d)\n",q->s[q->front].roll,q->s[q->front].name,q->s[q->front].marks);
    }
}
void display(Queue *q)
{
    int i=(q->front+1)%q->n;
    do{
        printf("(%d,%s,%d) ",q->s[i].roll,q->s[i].name,q->s[i].marks);
        i=(i+1)%q->n;
    }while(i!=(q->rear+1)%q->n);

}
int main()
{
    int c,val;
    int roll,marks;
    char name[10];
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=0;
    printf("Enter the no. of elements:");
    scanf("%d",&q->n);
    q->n+=1;
    q->s=(std*)malloc((q->n+1)*sizeof(std));
    printf("Enter choice 1.enqueue 2.dequeue\n");
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
                enqueue(q,roll,name,marks);
                display(q);
                printf("\n%d:front %d:rear",q->front,q->rear);
                break;
            case 2:
                dequeue(q);
                if(q->front!=q->rear){
                    display(q);
                    printf("\n%d:front %d:rear",q->front,q->rear);
                }
                else
                printf("Queue empty\n");
                break;
        }
        printf("\nEnter choice 1.enqueue 2.dequeue\n");
        scanf("%d",&c);
    }
    free(q->s);
    free(q);
}