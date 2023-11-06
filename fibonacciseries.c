#include<stdio.h>
#include<stdlib.h>
int fibiterative(int n)
{
    int num1=0,num2=1,nexterm;
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    else{
        for(int i=2;i<n;i++)
        {
            nexterm=num1+num2;
            num1=num2;
            num2=nexterm;
        }
        return nexterm;
    }
}
int fibrecursive1(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2) 
    return 1;
    else
    return fibrecursive1(n-1)+fibrecursive1(n-2);
}
int helper(int n,int i,int k,int *stack)
{
    int t;
    if(i>0)
    {
        t=stack[1];
        stack[1]=stack[0]+stack[1];
        stack[0]=t;
    }
    if(i<n)
    {
        return helper(n,i+1,stack[1],stack);
    }
    else{
        return k;
    }
}
int fibrecursive2(int n,int*stack){
    return helper(n,0,0,stack);
}
int main(){
    int n;
    int *stack;
    stack=(int*)malloc(2*sizeof(int));
    stack[0]=0;
    stack[1]=1;
    printf("Enter the term to find:");
    scanf("%d",&n);
    printf("%d term using iterative function\n",fibiterative(n));
    printf("%d term using traditional recursive method\n",fibrecursive1(n));
    printf("%d using optimized recursion",fibrecursive2(n-1,stack));
    return 0;
}