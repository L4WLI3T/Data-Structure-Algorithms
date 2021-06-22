#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
struct node
{
 int data;
 struct node*next;
};
struct node *p,*q,*temp,*link,*list=NULL;
struct node *getnode()
{
 struct node*p;
 p=(struct node*)malloc(sizeof(struct node));
 return p;
}
void freenode(struct node*p)
{
 free(p);
}
void addbegin()
{
 int x;
 p=getnode();
 printf("Enter element to be inserted.\n");
 scanf("%d",&x);
 //temp=list;
 //temp->data=x
 p->data=x;
 if(list==NULL)
 {
   list=p;
   p->next=list;
 }
 else
 {
  temp=list;
  while(temp->next!=list)
  {
    temp=temp->next;
    p->next=list;
    temp->next=p;
    list=p;
  }
 }
 
 //p->next=list;
 //list=p;
 
}
void addend()
{
 int x;
 temp=list;
 p=getnode();
 printf("Enter element to be inserted.\n");
 scanf("%d",&x);
 if(temp==NULL)
  list=p;
 else
  {
  while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=p;
  }
 p->data=x;
 p->next=list;
}
void addmid()
{
 int i,x,pos;
 p=getnode();
 temp=list;
 printf("Enter element to be inserted & it's location.\n");
 scanf("%d %d",&x,&pos);
 p->data=x;
 for(i=0;i<pos-2;i++)
  {
   temp=temp->next;
   if(temp==NULL)
   {
    printf("Enter valid position.\n");
    return;
   }
  }
   p->next=temp->next;
   temp->next=p;
}
void delbegin()
{
 int x;
 if(list==NULL)
  printf("The list is empty.\n");
 else
 {
  p=list;
  x=p->data;
  printf("Deleted element is: %d \n", x);
  list=list->next;
  freenode(p);
 }
}
void delend()
{
 int x;
 if(list==NULL)
  printf("The list is empty.\n");
 else
 {
  q=NULL;
  p=list;
  while(p->next!=NULL)
  {
   q=p;
   p=p->next;
  }
  if(q==NULL)
   list=NULL;
  else
   q->next=list;
  x=p->data;
  printf("Deleted element is: %d \n",x);
  freenode(p);
 }
}
void delmid()
{
 int i,pos;
 if(list==NULL)
  printf("The list is empty.\n");
 else
 {
  q=NULL;
  p=list;
  printf("Enter position to be deleted.\n");
  scanf("%d",&pos);
  for(i=0;i<pos-1;i++)
  {
   q=p;
   p=p->next;
   if(p==NULL)
   {
    printf("Enter a valid position.\n");
    return;
   }
  }
 // q->next=p->next;
  printf("The deleted element is: %d\n",p->data);
  q->next=p->next;
  freenode(p);
 }
}
void display()
{
 p=list;
 if(p==NULL)
 {
  printf("The list is empty.\n");
  return;
 }
 printf("The list:\n");
 while(p->next!=list)
 {
  printf("%d ",p->data);
  p=p->next;
 }
 printf("\n");
}
int main()
{
 int ch;
 while(1)
 {
  printf("****MENU****\n1.ADD START\n2.ADD END\n3.ADD MID\n4.DELETE START\n5.DELETE END\n6.DELETE MID\n7.DISPLAY\n8.EXIT\n");
  scanf("%d",&ch);
  switch (ch)
  {
   case 1:addbegin();
    break;
   case 2:addend();
    break;
   case 3:addmid();
    break;
   case 4:delbegin();
    break;
   case 5:delend();
    break;
   case 6:delmid();
    break;
   case 7:display();
    break;
   case 8:exit(0);
    break;
   default:
    printf("Enter valid choice.\n");
  }
 }
 return 0;
}

1


