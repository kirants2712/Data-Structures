//Write a program to implement reversal of a Singly Linked List in O(1) additional space
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

struct node
{
 long long int n;
 node* next;
};
node* head;
node* tail;
node* newnode;
node* q;
node* c_newnode(long long int a)
{
 newnode=(node*)malloc(sizeof(node));
 newnode->n=a;
 newnode->next=NULL;
 return(newnode);
}
void insertnode(long long int a)
{
 q=c_newnode(a);
 if(q==NULL)
 {
   printf("error!!!");
 }
 else if(head==NULL)
 {
   head=q;
   tail=q;
 }
 else
 {
   tail->next=q;
   tail=q; 
 }
}
void printnode()
{
 q=head;
 while(!(q->next==NULL))
 {
   printf("%lli ",q->n);
   q=q->next;
 }
 printf("%lli",q->n);
}


void reverse()
{
   if(head==NULL || head->next==NULL)
   {
      return;
   }
   else
   {
     node *r;
     q=head->next;
     head->next=NULL;
     while(q->next != NULL)
     {
       r=q->next;
       q->next=head;
       head=q;
       q=r;
     }
     q->next=head;
     head=q;
   }
}
int main()
{ 
  long long int x=0;
  int a,c;
  c=getchar(); 
  while(c!=10)
  {
     if(c=='\n')
     {
        insertnode(x);
        break;
     }
     else if (c==' ')
     {
       insertnode(x);
       x=0;
     }
     else
     {
        a=c-48;
        x=x*10+a;
     }
     c=getchar();
  }
  insertnode(x);     
  reverse();
  printnode();
  return(0);
}






















