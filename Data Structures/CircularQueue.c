#include<stdio.h>
#include<conio.h>
#define MAX 10
int front=-1;
int rear=-1;
int q[MAX];
void insert (int val)
{
 if((front==0&&rear==MAX-1)||(front==rear+1))
  printf("Queue overflow.\n");
 else if(front==-1&&rear==-1)
  {
   front=0;
   rear=0;
   q[rear]=val;
  }
 else if(rear==MAX-1&&front!=0)
  {
   rear=0;
   q[rear]=val;
  }
 else
 {
  rear++;
  q[rear]=val;
 }
}
void remove()
{
 if(front==-1&&rear==-1)
  printf("Queue is empty.\n");
 else
  {
   if(front==MAX-1)
    front=0;
   else
    front++;
  }
}
void traverse()
{
 int i;
 if(front==-1&&rear==-1)
  printf("Queue is empty.\n");
 else if(front>rear)
    {
     for(i=front;i<MAX;i++)
      printf("%d\n",q[i]);
     for(i=0;i<=rear;i++)
      printf("%d\n",q[i]);
    }
 else
  for(i=front;i<=rear;i++)
   printf("%d\n",q[i]);
}
void main()
{
 int n,val;
 clrscr();
 do{
  printf("----MENU----\n1.Insert\n2.Remove\n3.Traverse\n4.EXIT\nEnter the choice.\n");
  scanf("%d",&n);
  switch(n)
  {
   case 1:printf("Enter element to be inserted.\n");
	  scanf("%d",&val);
	  insert(val);
	  break;
   case 2:
	  remove();
	  break;
   case 3:
	  traverse();
	  break;
   case 4: printf("Exit.\n");
	  break;
  default:printf("Enter a valid operation.\n");
  }
  }
  while(n!=4);
  getch();
}