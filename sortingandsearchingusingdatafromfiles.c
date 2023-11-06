#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct student{
    int roll;
    float marks;
}student;
int linearsearch(student s[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].roll==key)
        {
            return i;
        }
    }
    return -1;
}
int binarysearch(student s[],int n,int key)
{
    int l=0,h=n-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(s[mid].roll==key)
        return mid;
        else if(s[mid].roll>key)
        {
            h=mid-1;
        }
        else
        l=mid+1;
    }
    return -1;
}
void swap(student *s1,student *s2)
{
    student temp=*s1;
    *s1=*s2;
    *s2=temp;
}
void bubblesort(student s[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].roll>s[j+1].roll)
            swap(&s[j],&s[j+1]);
        }
    }
}
void insertionsort(student s[],int n)
{
    int i,j;
    student key;
    for(j=1;j<n;j++)
    {
        key=s[j];
        i=j-1;
        while(i>=0 && s[i].roll>key.roll)
        {
            s[i+1]=s[i];
            i--;
        }
        s[i+1]=key;
    }
}
void selectionsort(student s[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(s[j].roll<s[k].roll)
            k=j;
        }
        swap(&s[i],&s[k]);
    }
}
void cocktail(student s[],int n)
{
    int i;
    int flag=1,l=0,h=n-1;
    while(flag)
    {
        flag=0;
        for(i=l;i<h;i++)
        {
            if(s[i].roll>s[i+1].roll)
            {
                swap(&s[i],&s[i+1]);
                flag=1;
            }
        }
        if(!flag)
        {
            break;
        }
        flag=0;
        h--;
        for(i=h-1;i>=l;i--)
        {
            if(s[i].roll>s[i+1].roll)
            {
                swap(&s[i],&s[i+1]);
                flag=1;
            }
        }
        l++;
    }
}
int main()
{
    FILE *fp;
    student *s;
    int input,choice1,choice2,i=0,index,key;
    double time1,time2;
    srand(time(NULL));
    printf("\n how many input variables do you want (100/1000/10000) \n");
    scanf("%d",&input);
    printf("\n best(1),worst(2),avg(3)\n");
    scanf("%d",&choice1);
    printf("\n choose 1.linear search 2.bubblesortandbinarysearch 3.bubblesort 4.insertion sort 5.selectionsort 6.cocktail\n");
    scanf("%d",&choice2);
    if(choice2==1 || choice2==2)
    {
        printf("\nEnter key to search:");
        scanf("%d",&key);
    }
    time1=time(NULL);
    s=(student*)malloc(input*sizeof(student));

    if(input==100 && choice1==1)
    {
        fp=fopen("file1.txt","r");
    }
    else if(input==100 && choice1==2)
    {
        fp=fopen("file2.txt","r");
    }
    else if(input==100 && choice1==3)
    {
        fp=fopen("file3.txt","r");
    }
    else if(input==1000 && choice1==1)
    {
        fp=fopen("file4.txt","r");
    }
    else if(input==1000 && choice1==2)
    {
        fp=fopen("file5.txt","r");
    }
    else if(input==1000 && choice1==3)
    {
        fp=fopen("file6.txt","r");
    }
    else if(input==10000 && choice1==1)
    {
        fp=fopen("file7.txt","r");
    }
    else if(input==10000 && choice1==2){
        fp=fopen("file8.txt","r");
    }
    else{
        fp=fopen("file9.txt","r");
    }
    fscanf(fp,"%d %f",&s[i].roll,&s[i].marks);
    i++;
    while(i<input)
    {
        fscanf(fp,"%d %f",&s[i].roll,&s[i].marks);
        i++;
    }
    if(choice2==1)
    {
        index=linearsearch(s,input,key);
        printf("%d is the index",index);
    }
    else if(choice2==2)
    {
        bubblesort(s,input);
        index=binarysearch(s,input,key);
        printf("%d is the index",index);
    }
    else if(choice2==3)
    {
        bubblesort(s,input);
    }
    else if(choice2==4)
    {
        insertionsort(s,input);
    }
    else if(choice2==5)
    {
        selectionsort(s,input);
    }
    else if(choice2==6)
    {
        cocktail(s,input);
    }
    if(choice2!=1 && choice2!=2)
    {
        for(i=0;i<input;i++)
        printf("%d %f\n",s[i].roll,s[i].marks);
    }
    time2=time(NULL);
    printf("Total time is %lf",time2-time1);
    free(s);
    fclose(fp);
    return 0;
}