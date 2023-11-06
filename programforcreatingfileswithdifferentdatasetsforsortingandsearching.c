#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    FILE*fp;
    float marks;
    int i,roll;
    fp=fopen("file1.txt","w");
    srand(time(NULL));
    for(i=1;i<=100;i++)
    {
        roll=i;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file2.txt","w");
    for(i=100;i>=1;i--)
    {
        roll=i;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file3.txt","w");
    for(i=1;i<=100;i++)
    {
        roll=rand()%101+1;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file4.txt","w");
    for(i=1;i<=1000;i++)
    {
        roll=i;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file5.txt","w");
    for(i=1000;i>=1;i--)
    {
        roll=i;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file6.txt","w");
    for(i=1;i<=1000;i++)
    {
        roll=rand()%1001+1;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file7.txt","w");
    for(i=1;i<=10000;i++)
    {
        roll=i;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file8.txt","w");
    for(i=10000;i>=1;i--)
    {
        roll=i;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
    fp=fopen("file9.txt","w");
    for(i=1;i<=10000;i++)
    {
        roll=rand()%10001+1;
        marks=((float)rand()/RAND_MAX)*59+40;
        fprintf(fp,"%d %f\n",roll,marks);
    }
    fclose(fp);
}