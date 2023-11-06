#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node node;
node *insert_nrec(node *root, int ikey );
void nrec_pre(node *root);
void nrec_in(node *root);
void nrec_post(node *root);
void display(node *ptr,int level);
node *queue[MAX];
int front=-1,rear=-1;
void insert_queue(node *item);
node *del_queue();
int queue_empty();
node *stack[MAX];
int top=-1;
void push_stack(node *item);
node *pop_stack();
int stack_empty();
int main( )
{
    struct node *root=NULL, *ptr;
    int choice,k;
    while(1)
    {
        printf("\n");
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Preorder Traversal\n");
        printf("4.Inorder Traversal\n");
        printf("5.Postorder Traversal\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the key to be inserted : ");
                scanf("%d",&k);
                root = insert_nrec(root, k);
                break;
            case 2:
                printf("\n");
                display(root,0);
                printf("\n");
                break;
            case 3:
                nrec_pre(root);
                break;
            case 4:
                nrec_in(root);
                break;
            case 5:
                nrec_post(root);
                break;
            case 6:
                exit(1);
            default:
                printf("\nWrong choice\n");
        }
    }
    return 0;
}
node *insert_nrec(node *root, int ikey)
{
    node *tmp,*par,*ptr;
    ptr = root;
    par = NULL;
    while( ptr!=NULL)
    {
        par = ptr;
        if(ikey < ptr->data)
            ptr = ptr->left;
        else if( ikey > ptr->data)
            ptr = ptr->right;
        else
        {
            printf("\nDuplicate key");
            return root;
        }
    }
    tmp=(node *)malloc(sizeof(node));
    tmp->data=ikey;
    tmp->left=NULL;
    tmp->right=NULL;
    if(par==NULL)
        root=tmp;
    else if( ikey < par->data)
        par->left=tmp;
    else
        par->right=tmp;
    return root;
}
void nrec_pre(node *root)
{
    node *ptr = root;
    if( ptr==NULL )
    {
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while( !stack_empty() )
    {
        ptr = pop_stack();
        printf("%d  ",ptr->data);
        if(ptr->right!=NULL)
            push_stack(ptr->right);
        if(ptr->left!=NULL)
            push_stack(ptr->left);
    }
    printf("\n");
}
void nrec_in(node *root)
{
    node *ptr=root;
    if( ptr==NULL )
    {
        printf("Tree is empty\n");
        return;
    }
    while(1)
    {
        while(ptr->left!=NULL )
        {
            push_stack(ptr);
            ptr = ptr->left;
        }
        while( ptr->right==NULL )
        {
            printf("%d  ",ptr->data);
            if(stack_empty())
                return;
            ptr = pop_stack();
        }
        printf("%d  ",ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}
void nrec_post(node *root)
{
    node *ptr = root;
    node *q;
    if( ptr==NULL )
    {
        printf("Tree is empty\n");
        return;
    }
    q = root;
    while(1)
    {
        while(ptr->left!=NULL)
        {
            push_stack(ptr);
            ptr=ptr->left;
        }
        while( ptr->right==NULL || ptr->right==q )
        {
            printf("%d  ",ptr->data);
            q = ptr;
            if( stack_empty() )
                return;
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->right;
    }
    printf("\n");
}
void insert_queue(node *item)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1) 
        front=0;
    rear=rear+1;
    queue[rear]=item ;
}
node *del_queue()
{
    node *item;
    if(front==-1 || front==rear+1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    item=queue[front];
    front=front+1;
    return item;
}
int queue_empty()
{
    if(front==-1 || front==rear+1)
        return 1;
    else
        return 0;
}
void push_stack(node *item)
{
    if(top==(MAX-1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=item;
}
node *pop_stack()
{
    node *item;
    if(top==-1)
    {
        printf("Stack Underflow....\n");
        exit(1);
    }
    item=stack[top];
    top=top-1;
    return item;
}
int stack_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void display(node *ptr,int level)
{
    int i;
    if(ptr == NULL )
        return;
    else
    {
        display(ptr->right,level+1);
        printf("\n");
        for(i=0;i<level;i++)
        printf(" ");
        printf("%d", ptr->data);
        display(ptr->left, level+1);
    }
}