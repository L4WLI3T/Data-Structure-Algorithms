#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *left,*right;
}treenode;
void insert(treenode **root,int x)
{
 treenode *ptr,*prev,*p;
 ptr=(treenode *)malloc(sizeof(treenode));
 ptr->data=x;
 ptr->right=ptr->left=NULL;
 p=*root;
 prev=NULL;
 while(p!=NULL)
 {
  prev=p;
  if(x<p->data)
   p=p->left;
  else
   p=p->right;
 }
 if(prev==NULL)
  *root=ptr;
 else
 {
  if(x<prev->data)
   prev->left=ptr;
  else
   prev->right=ptr;
 }
}
void inorder(treenode *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%d",root->data);
  inorder(root->right);
 }
}
void preorder(treenode *root)
{
 if(root!=NULL)
 {
  printf("%d",root->data);
  preorder(root->left);
  preorder(root->right);
 }
}
void postorder(treenode *root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%d",root->data);
 }
}
void main()
{
 treenode *root;
 root=NULL;
 int c,n,x;
 clrscr();
 while(1)
 {
  printf("----MENU---\n1.INSERT\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.EXIT\n");
  scanf("%d",&c);
  switch(c)
  {
   case 1:
    printf("Enter the element.\n");
    scanf("%d",&x);
    insert(&root,x);
    break;
   case 2:
    inorder(root);
    break;
   case 3:
    preorder(root);
    break;
   case 4:
    postorder(root);
    break;
   case 5:
    exit(0);
    break;
   default:
    printf("Enter valid choice.\n");
  }
 }
 getch();
}
