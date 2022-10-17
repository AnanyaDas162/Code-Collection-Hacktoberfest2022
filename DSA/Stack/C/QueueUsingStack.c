#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int s1[MAX],s2[MAX],top1=-1,top2=-1;
//making insertion operation costly
void enqueue(int x)
{
while(top1!=-1)
{
  //shifting from s1 to s2
top2++;
s2[top2]=s1[top1];
top1--;
}
//push element to s1
s1[top1++]=x;
while(top2!=-1)
{
  //shifting from s2 to s1
top1++;
s1[top1]=s2[top2];
top2--;
}
}
void dequeue()
{
if(top1==-1)
{
printf("Queue is empty");
}
else
{
int x;
x=s1[top1];
top1--;
printf("Data is deleted");
}
}
int main()
{
int ch=1;
while(ch)
{
printf("Enter the operation i want to perform::");
printf("Enter choice:1.Enqueue\n2.Dequque\n3.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:{int x;
          printf("Enter data:");
         scanf("%d",&x);
         if(top1==MAX-1)
        {
        printf("Queue is Full");
        break;
        }
        else
        {
        enqueue(x);
        printf("Data added");
         }
}
break;
case 2:dequeue();
break;
case 3:exit(0);
break;
default:printf("wrong choice");
break;
}
}
return 0;
}
