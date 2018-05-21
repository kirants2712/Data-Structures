/*
/*
Write a program to implement a queue using the following:
a) Array representation
b) Linked list representation
Your program must support the following functions:
1. enqueue(element) - Puts the data specified by element at the rear end of the queue.Return -2, if the queue is full.
2. dequeue - removes and returns the element at the front of the queue. Return -1, if the queue is empty.
3. print_queue - displays the values of all the elements present in the queue.
Input format:
The input consists of multiple lines, each line of the input contains a character from {'e', 'd', 'p','s'} followed by zero or one integer. The integer, if given, is in the range 0 to 2 31 .
● The character 'e' means enqueue the next integer from the input into the queue. In this case, the next integer (>= 0) is given on the same line as the character 'e', separated by a space.
● The character 'd' means dequeue and output element from the front of the queue. Output “-1”, if the queue was originally empty.
● The character 'p' means show all elements in the queue. In this case, output all elements of the queue on a single line, separated by space, starting with the element at the front.Output “-1”, if the queue was originally empty.
● The character 's' means “stop the program” Output format:The output (if any) of each command should be printed on a separate line.

Example:
a) Array Representation: For the array implementation, the very first line of input contains an integer value c, 0 < c < 100, which is the capacity of the queue. In this case, the enqueue operation must output “-2” when an element is being enqueued into an already full queue.
Sample Input:
3
e 2
e 5
e 7
d
p
e 10
e 11
d
p
d
d
d
e 3
p
s
Sample Output:
2
5 7
-2
5
7 10
7
10
-1
3
b) Linked list representation
Sample Input:
e 2
e 5e 7
d
p
e 10
d
p
d
d
d
e 3
p
s
Sample Output:
2
5 7
5
7 10
7
10
-1
3
*/
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef long long int lli;
node *head=NULL;
node *tail=NULL;
node *newnode;
node *q;
node *temp;
long long int val;

struct node
{
  long long int data;
  node *next;
};

node* c_newnode()
{
 newnode=(node*)malloc(sizeof(node));
 newnode->data=val;
 newnode->next=NULL;
 return(newnode);
}
void enqueue()
{
   q=c_newnode();
   if(head==NULL)
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

int dequeue()
{
  int p;
  if(head==NULL)
     return -1;
  else if(head==tail)
  {
    val=head->data;
    head->next=NULL;
    head=NULL;
    tail=NULL;
    return val;
  }
  else
  {
    val=head->data;
    temp=head;
    head=head->next;
    temp->next=NULL;
    return val;
  }

}




int print()
{
  temp=head;
  if(temp==NULL)
    return -1;
  while(temp!=NULL)
  {
    printf("%lli ",temp->data);
    temp=temp->next;
  }
  return 1;
}

int main()
{

   char ch;
   
while(ch!='s')
{
  
   int v;
   scanf("%c",&ch);
   switch(ch)
   {
     case 'e':scanf("%lli",&val);
              enqueue(); 
              break;
     case 'd':v=dequeue();
              printf("%d\n",v);  
              break;
     case 'p':v=print();
              if(v==-1)
               printf("-1"); 
              printf("\n");
              break;
     case 's': 
              break;
   }
}

}
