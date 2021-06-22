#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 20
char st[MAX];
int top=-1;
void push(char val)
{
 if(top==MAX-1)
  printf("Overflow.\n");
 else
  st[++top]=val;
}
char pop()
{
 char val=' ';
 if(top==-1)
  printf("Underflow.\n");
 else
  val=st[top--];
 return(val);
}
int getpriority(char op)
{
 return (op=='/'||op=='*'||op=='%')?1:0 ;
}
void intopost(char source[],char target[])
{
 int i=0,j=0;
 strcpy(target," ");
 while(source[i]!='\0')
 {
  if(source[i]=='(')
   push(source[i++]);
  else if(source[i]==')')
  {
   while(top!=-1||st[top]!='(')
    target[j++]=pop();
   if(top==-1)
    printf("Incorrect Expression.\n");
    exit(1);
   pop();
   i++;
  }
  else if(isdigit(source[i])||isalpha(source[i]))
   target[j++]=source[i++];
  else if(source[i]=='+'||source[i]=='-'||
  source[i]=='/'||source[i]=='%'||source[i]=='*')
  {
   while((top!=-1)&&(st[top]!='(')&&(getpriority(st[top])>getpriority(source[i])))
    target[j++]=pop();
   push(source[i++]);
  }
  else
  {
   printf("Incorrect expression.\n");
   exit(1);
  }
 }
 while((top!=-1)&&st[top]!='(')
  target[j++]=pop();
 target[j]='\0';
}
void main()
{
 char infix[20],postfix[20];
 clrscr();
 printf("Enter the infix expression.\n");
 gets(infix);
 strcpy(postfix," ");
 intopost(infix,postfix);
 printf("Postfix expression is:");
 puts(postfix);
 getch();
}
