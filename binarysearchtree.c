#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node node;
node* createNode(node*p,int val)
{
    p=(node*)malloc(sizeof(node));
    p->left=p->right=NULL;
    p->data=val;
    return p;
}
node* insert(node*p,int key)
{
    node*t;
    if(p==NULL)
    {
        t=(node*)malloc(sizeof(node));
        t->data=key;
        t->left=t->right=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->left=insert(p->left,key);
    }
    else{
        p->right=insert(p->right,key);
    }
    return p;
}
node* search(node*p,int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    else if(key>p->data)
    {
        return search(p->right,key);
    }
    else if(key<p->data){
        return search(p->left,key);
    }
    else{
        return p;
    }
}
int Height(node*p)
{
    int x,y;
    if(p==NULL)
    {
        return 0; 
    }
    x=Height(p->left);
    y=Height(p->right);
    if(x>y)
    {
        return x+1;        
    }
    else{
        return y+1;
    }
}
node* inpre(node*p)
{
    while(p&&p->right!=NULL)
    {
        p=p->right;
    }
    return p;
}
node* insucc(node*p)
{
    while(p&&p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}
node *delete(node*p,int key,node*root)
{
    node*q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p->left=delete(p->left,key,root);
    }
    else if(key>p->data)
    {
        p->right=delete(p->right,key,root);
    }
    else{
        if(Height(p->left)>Height(p->right))
        {
            q=inpre(p->left);
            p->data=q->data;
            p->left=delete(p->left,q->data,root);
        }
        else{
            q=insucc(p->right);
            p->data=q->data;
            p->right=delete(p->right,q->data,root);
        }
    }
    return p;
}
void Inorder(node*p)
{
    if(p==NULL)
    {
        return ;
    }
    else{
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}
void Preorder(node*p)
{
    if(p==NULL)
    {
        return ;
    }
    else{
        printf("%d ",p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}
void Postorder(node *p)
{
    if(p==NULL)
    {
        return ;
    }
    else{
        Postorder(p->left);
        Postorder(p->right);
        printf("%d ",p->data);
    }

}
int main()
{
    node*root,*t,*p;
    int val,c;
    printf("Enter the value at root:");
    scanf("%d",&val);
    root=createNode(root,val);
    printf("Enter the choice 1.insert 2.delete 3.search 4.inorder 5.preorder 6.postorder\n");
    scanf("%d",&c);
    while(c!=-1)
    {
        switch(c)
        {
            case 1:
                printf("Enter the value:");
                scanf("%d",&val);
                root=insert(root,val);
                Inorder(root);
                break;
            case 2:
                printf("Enter the value to delete:");
                scanf("%d",&val);
                root=delete(root,val,root);
                Inorder(root);
                break;
            case 3:
                printf("Enter the value to search:");
                scanf("%d",&val);
                p=search(root,val);
                printf("%d is the value found\n",p->data);
                Inorder(root);
                break;
            case 4:
                printf("recursive inorder\n");
                Inorder(root);
                break;
            case 5:
                printf("recursive preorder\n");
                Preorder(root);
                break;
            case 6:
                printf("recursive postorder\n");
                Postorder(root);
        }
        printf("Enter the choice 1.insert 2.delete 3.search 4.inorder 5.preorder 6.postorder\n");
        scanf("%d",&c);
    }
}