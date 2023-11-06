#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student{
    int roll;
    char name[10];
    int marks;
    struct Student* next;
};
typedef struct Student std;
std* createNode(int roll,char name[10],int marks)
{
    std* temp=(std*)malloc(sizeof(std));
    temp->roll=roll;
    temp->marks=marks;
    strcpy(temp->name,name);
    temp->next=NULL;
    return temp;
}
void push(std*top,std*toInsert)
{
    toInsert->next=top->next;
    top->next=toInsert;
}
void pop(std*top)
{
    std*p;
    if(top->next==NULL)
    {
        printf("Underflow\n");
        return ;
    }
    p=top->next;
    top->next=p->next;
    p->next=NULL;
    printf("\nPopped value is (%d,%s,%d) \n",p->roll,p->name,p->marks);
    free(p);
}
void display(std*top)
{
    std*p=top->next;
    printf("top->");
    while(p!=NULL)
    {
        printf("(%d,%s,%d) ",p->roll,p->name,p->marks);
        p=p->next;
    }
}
int main()
{
    std*top,*temp;
    int c,roll,marks;
    char name[10];
    top=(std*)malloc(sizeof(std));
    top->next=NULL;
    printf("Enter the choice 1.push 2.pop");
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
                temp=createNode(roll,name,marks);
                push(top,temp);
                display(top);
                break;
            case 2:
                pop(top);
                display(top);
                break;
        }
        printf("\nEnter the choice 1.push 2.pop");
        scanf("%d",&c);
    }
}