#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int *s;
    int front;
    int rear;
    int n;
};
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
    if(q->rear==q->n-1)
    return 1;
    return 0;
}
void enqueue(Queue*q,int val)
{
    if(isfull(q)==1)
    return ;
    else{
        q->rear++;
        q->s[q->rear]=val;
    }
}
int dequeue(Queue*q)
{
    int val;
    if(isempty(q)==1)
    return -1;
    else{
        q->front++;
        val=q->s[q->front];
        return val;
    }
}
void display(Queue *q)
{
    int i;
    for(i=q->front+1;i<=q->rear;i++)
    {
        printf("%d ",q->s[i]);
    }
}
int main()
{
    int c,val;
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=-1;
    printf("Enter the no. of elements:");
    scanf("%d",&q->n);
    q->s=(int*)malloc(q->n*sizeof(int));
    printf("Enter choice 1.enqueue 2.dequeue\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("Enter element:");
                scanf("%d",&val);
                enqueue(q,val);
                display(q);
                break;
            case 2:
                val=dequeue(q);
                printf("%d\n",val);
                display(q);
                break;
        }
        printf("Enter choice 1.enqueue 2.dequeue\n");
        scanf("%d",&c);
    }
    free(q->s);
    free(q);
}