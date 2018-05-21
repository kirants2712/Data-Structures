/*
An n-digit (where, 1 <= n <= 10000) positive integer is represented by a singly linked list (SLL) of length n in the following way: Each digit of the number is stored in a node of SLL so that the most significant digit is at the node pointed to by the head pointer of the linked list and the least significant digit is at the tail of SLL. For example, the number 673924 is represented as 6 -> 7 -> 3 -> 9 -> 2 -> 4. Write a recursive function difference_of_digits() that takes as input two SLLs representing two n-digit numbers as arguments and subtracts the smallest SLL from the largest SLL and stores the difference between both the input SLLs in the largest SLL. The function should only use O(1)
additional space and should run in O(n) time.
Input format :
First two lines contain n-digit positive integers.
Output format :
An n or <n digit number, containing the difference of the input numbers
Sample Input :
654321
532187
Sample Output :
122134
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
    long long int data;
    node *next;
};

node* head;

node* tail;

node* head1;

node* tail1;

node* newnode;
node* q;
node* c_newnode(long long int a)
{
 newnode=(node*)malloc(sizeof(node));
 newnode->data=a;
 newnode->next=NULL;
 return(newnode);
}
long long int count,count1;

long long int largest(node *head,node *head1)
   {  long long int a,b;
       if(head==NULL)
        return 1;
       else
       {  a=head->data;
          b=head1->data;
          if(a>b)
            return 1;
           else
           {
               if(a==b)
                largest(head->next,head1->next);
               else
                return 0;
           }

       }
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
void insertnode1(long long int a)
{
 q=c_newnode(a);
 if(q==NULL)
 {
   printf("error!!!");
 }
 else if(head1==NULL)
 {
   head1=q;
   tail1=q;
 }
 else
 {
   tail1->next=q;
   tail1=q; 
 }
}
void reverse()
 {
      node *n,*t,*temp;
       n=NULL;
       tail=head;
       t=head;
       while(t!=NULL)
       {
          temp=t->next;
           t->next=n;
           n=t;
           t=temp;
       }
      head=n;
 }
void reverse1()
 {
      node *m,*r,*temp1;
       m=NULL;
       tail1=head1;
       r=head1;
       while(r!=NULL)
       {
          temp1=r->next;
           r->next=m;
           m=r;
           r=temp1;
       } 
       head1=m;
 }
 void difference_of_digits(node* head,node* head1)
 {
      int d1,d2;
      if(head==NULL)
        return;
      else
        { 
          d1=head->data;
          d2=head1->data;
          if(d1>=d2)
          {
              d1=d1-d2;
              head->data=d1;
          }
          else
          { 
              d1=d1-d2+10;
              head->data=d1;
              (head->next)->data=(head->next)->data-1;
          }
          head=head->next;
          head1=head1->next;
          difference_of_digits(head,head1);
        }

 }

 void equal1(node **head1,node **tail1)
   {   
        reverse1();
        while(count!=count1)
       {
          insertnode1(0);
          count1++;
        }
       reverse1();


   }
 void equal(node **head,node **tail)
   {   
       reverse();
       tail=head;
       while(count!=count1)
      {
        insertnode(0);
         count++;
      }
        reverse();
   }

 


void print(node *head)
  { int count=0;
       node *new;
       new=head;
       while(new!=NULL)
       {    if(new->data==0)
            {
              if(count!=0)
            printf("%lli",(new->data));
            }
            else
            printf("%lli",(new->data));
            if(new->data!=0)
            count++;
           new=new->next;
       } if(count==0)
          printf("0");
  }
int main()
{
     node *temp;
     long long int w,s;
     char a;
     head=NULL;
     tail=NULL;
     head1=NULL;
     tail1=NULL;
     scanf("%c",&a);
     while(a!='\n')
     { 
         w=a-48;
         count++;
         insertnode(w);
         scanf("%c",&a);

      } 
     
      scanf("%c",&a);
      while(a!='\n')
      { 
           w=a-48;
           count1++;
           insertnode1(w);
           scanf("%c",&a);
      }
       
      if(head==NULL)
      {
            return 1;
       }
      if(count1!=count)
      {
           if(count>count1)
           {
               equal1(&head1,&tail1);
           }
           else
           {
                equal(&head,&tail);
           }
      }
      count=largest(head,head1);
      reverse();
      reverse1();
      if(head==NULL)
            return 1;
      else
        {
           if(count==1)
           difference_of_digits(head,head1);

           else
           { 
             temp=head;
             head=head1;
             head1=temp;
             difference_of_digits(head,head1);
           }
           reverse(&head,&tail);
           print(head);

        }

    //return 1;
}




