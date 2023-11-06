#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int *s;
    int top;
    int n;
};
typedef struct Stack Stack;
int isempty(Stack *stk)
{
    if(stk->top==-1)
    return 1;
    else
    return 0;
}
int isfull(Stack *stk)
{
    if(stk->top==stk->n-1)
    {
        return 1;
    }
    else return 0;
}
void push(Stack*stk,int ele)
{
    if(isfull(stk)==1)
    {
        printf("Oveflow!");
    }
    else{
        stk->top++;
        stk->s[stk->top]=ele;
    }
}
int pop(Stack *stk)
{
    int val;
    if(isempty(stk)==1)
    {
        printf("Underflow!");
        return -1;
    }
    else
    {
        val=stk->s[stk->top];
        stk->top--;
        return val;

    }
}
void display(Stack *stk)
{
    int i=stk->top;
    while(i>-1)
    {
        printf("%d ",stk->s[i]);
        i--;
    }
}
int main(){
    int c,val;
    Stack *stk;
    stk=(Stack*)malloc(sizeof(Stack));
    printf("Enter the no. of elements in the stack:");
    scanf("%d",&stk->n);
    stk->top=-1;
    stk->s=(int*)malloc(stk->n*sizeof(int));
    printf("Enter choice 1.push 2.pop\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("Enter element:");
                scanf("%d",&val);
                push(stk,val);
                display(stk);
                break;
            case 2:
                val=pop(stk);
                printf("%d\n",val);
                display(stk);
                break;
        }
        printf("Enter choice 1.push 2.pop\n");
        scanf("%d",&c);
    }
    free(stk->s);
    free(stk);
}