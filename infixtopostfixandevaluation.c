#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
    int n;
    char *s;
    int top;
};
struct Stack2{
    int n;
    int *s;
    int top;
};
typedef struct Stack Stack;
typedef struct Stack2 Stack2;
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
void push(Stack*stk,char ele)
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
char pop(Stack *stk)
{
    char val;
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
int isempty2(Stack2 *stk)
{
    if(stk->top==-1)
    return 1;
    else
    return 0;
}
int isfull2(Stack2 *stk)
{
    if(stk->top==stk->n-1)
    {
        return 1;
    }
    else return 0;
}
void push2(Stack2*stk,int ele)
{
    if(isfull2(stk)==1)
    {
        printf("Oveflow!");
    }
    else{
        stk->top++;
        stk->s[stk->top]=ele;
    }
}
int pop2(Stack2 *stk)
{
    int val;
    if(isempty2(stk)==1)
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
int prec(char op)
{
    if(op=='+' || op=='-')
    {
        return 1;
    }
    else if(op=='*' || op=='/')
    return 2;
    else if(op=='^')
    return 3;
    return -1;
}
int isop(char a)
{
    if (a=='+' || a=='*' || a=='-' || a=='/' || a=='^')
    {
        return 1;
    }
    else return 0;
}
char * intopost(char *in)
{
    int i,j=0;
    int len=strlen(in);
    char *post=(char*)malloc(sizeof(char)*(len+2));
    Stack *stk=(Stack*)malloc(sizeof(Stack));
    stk->top=-1;
    stk->n=100;
    stk->s=(char*)malloc(stk->n*sizeof(char));
    for(i=0;i<len;i++)
    {
        if(in[i]==' ' || in[i]=='\t')
        {
            continue;
        }
        if('a'<=in[i] && in[i]<='z' || 'A'<=in[i] && in[i]<='Z' || '0'<=in[i] && in[i]<='9')
        {
            post[j++]=in[i];
        }
        else if(in[i]=='(')
        {
            push(stk,in[i]);
        }
        else if(in[i]==')'){
            while(stk->top>-1 && stk->s[stk->top]!='(')
            {
                post[j++]=pop(stk);
            }
            if(stk->top>-1 && stk->s[stk->top]!='('){
                return "Invalid";
            }
            else{
                pop(stk);
            }
        }

        if(isop(in[i])==1)
        {
            while(stk->top>-1 && prec(stk->s[stk->top])>=prec(in[i]))
            {
                post[j++]=pop(stk);
            }
            push(stk,in[i]);
        }
    }
    
    while(stk->top>-1){
        if(stk->s[stk->top]=='('){
            return "Invalid";
        }
        post[j++]=pop(stk);
    }
    post[j]='\0';
    free(stk->s);
    free(stk);
    return post;
}
int evaluate(char *post)
{
    int i,num1,num2;
    Stack2 *stk=(Stack2*)malloc(sizeof(Stack2));
    stk->top=-1;
    stk->n=100;
    stk->s=(int*)malloc(stk->n*sizeof(int));
    for(i=0;i<strlen(post);i++)
    {
        if(post[i]<='9' && post[i]>='0')
        {
            push2(stk,post[i]-'0');
        }
        if(isop(post[i])==1)
        {
            num2=pop2(stk);
            num1=pop2(stk);
            
            if(post[i]=='+')
            {
                push2(stk,num1+num2);
            }
            if(post[i]=='-')
            {
                push2(stk,num1-num2);
            }if(post[i]=='*')
            {
                push2(stk,num1*num2);
            }if(post[i]=='/')
            {
                push2(stk,num1/num2);
            }
            if(post[i]=='^')
            {
                push2(stk,num1^num2);
            }
        }
    }
    num1=pop2(stk);
    free(stk->s);
    free(stk);
    return num1;
}
int main(){
    char in[100];
    char *post;
    int num;
    printf("Enter infix to convert into postfix and evaluate:");
    scanf("%[^\n]s",in);
    post=intopost(in);
    printf("%s\n",post);
    num=evaluate(post);
    printf("%d\n",num);
    free(post);
}