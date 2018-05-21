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

#include<stdio.h>
#include<stdlib.h>

long long int n,head=-1,tail=-1;
long long int queue[100000],val;


long long int deque()
{
  long long int p,ele;
  if(head==-1)
     return(-1);
  else if(head==tail)
  {
    ele=queue[head];
    head=-1;
    tail=-1;
    return(ele);
  }
  else
  {
    ele=queue[head];
    head=(head+1)%n; 
    return(ele);
  }

}

long long int enque(long long int data)
{
  if((tail+1)%n==head)
  {
    return(-2);
  }
  else if(tail==-1)
  {  
     head=0;
     tail=0;
     queue[0]=data;
     return(1);
  }
  else
  {
    queue[(tail+1)%n]=data;
    tail=(tail+1)%n;
    return(1);
  }

}



long long int print()
{
  long long int z=1;
  long long int p;
  p=head;
  if(p==-1)
  {
     return(-1);
  }
  else 
 {
  while(z!=-1)
  {

   if(p==tail)
   {
     val=queue[p];
     printf("%lli",val);
     z=-1;
   }
   else
   {
     val=queue[p];
     p=(p+1)%n;
     printf("%lli ",val);
   }
  }
  printf("\n");
  return(1);
 }

}

void main()
{

char c;
scanf("%lli",&n); 
do
{
  
   long long int v,data;
   c=getchar();
   switch(c)
   {
     case 'd':v=deque();
              printf("%lli\n",v);  
              break;
     case 'e':scanf("%lli",&data);
              v=enque(data); 
              if(v==-2)
              printf("%lli\n",v);
              break;
     
     case 'p':v=print();
              if(v==-1)
              printf("%lli\n",v); 
              break;
     case 's': break;
   }
}while(c!='s');

}
