/*
Write a program to implement a priority queue using heap. Your program must support the
following functions:
1. insert(pq, elem, pr) - inserts the data specified by element elem into the priority queue
pq with priority pr.
2. extract_min(pq) - removes and prints the element with the lowest priority from the
priority queue pq; prints “EMPTY” if the priority queue is empty. (Strictly follow the
output format. It should be EMPTY not empty or anything else.)
3. get_min(pq) - prints the element with the lowest priority from the priority queue pq,
without actually removing it from the priority queue; prints “EMPTY” if the priority
queue is empty. (Strictly follow the output format. It should be EMPTY not empty or
anything else.)4. decrease_priority(pq, elem, newpr) - changes the priority of element elem in the
priority queue specified by pq, by assigning it the new priority newpr. It is guaranteed
that elem will be present in the priority queue, and that newpr will be lower (in the sense
of priority) than the original priority of elem.
Input format:
● The input consists of multiple lines, each line of the input contains a character from {'a',
'e', 'g', 'd', 's'} followed by zero or two integers. The integers, if given, are in the range -2 30
to 2 30 .
● The character 'a' means insert the next integer from the input into the priority queue. In
this case, two more integers follow the character 'a', each separated by space. The first
integer (>= 0) is the data to be inserted. The second integer (>= 1) is the priority of this
data item (1 being the lowest priority). Assign the priority to the data, and then insert this
data into the priority queue.
● The character 'e' means remove and output the element with the lowest priority from the
priority queue (Output the priority of the element in parenthesis, separated by a space).
Output “EMPTY”, if the priority queue was originally empty. (Strictly follow the output
format. It should be EMPTY not empty or anything else.)
● The character 'g' means output the element with the lowest priority from the priority
queue without actually removing it (Output the priority of the element in parenthesis,
separated by a space). Output “EMPTY”, if the priority queue was originally empty.
(Strictly follow the output format. It should be EMPTY not empty or anything else.)
● The character 'd' means decrease the priority of a datum in the priority queue. In this case,
two more integers follow 'd', each separated by space. The first integer (>= 0) is the data
(which will be present in the priority queue). The second integer (>= 1) is the new
decreased priority. After this operation, the priority of this data should be the one
specified in this input.
● The character 's' means “stop the program”.
Output format:
The output (if any) of each command should be printed on a separate line.
Sample Input:
a 2 100
a 5 110
a 7 95
ee
a 10 120
e
a 6 30
g
d 10 25
g
e
e
e
a 1 30
a 2 15
e
s
Sample Output:
7 (95)
2 (100)
5 (110)
6 (30)
10 (25)
10 (25)
6 (30)
EMPTY
2 (15)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

struct node
{
    long long int data;
    long long int p;
}pqueue[1000];


void swapdata(long long int i,long long int j)
{
   long long int t;
   t=pqueue[i].data;
   pqueue[i].data=pqueue[j].data;
   pqueue[j].data=t;
}
void swappriority(long long int i,long long int j)
{
   long long int t;
   t=pqueue[i].p;
   pqueue[i].p=pqueue[j].p;
   pqueue[j].p=t;
}
void swap(long long int i,long long int j)
{ 
    swapdata(i,j);
    swappriority(i,j);
}
long long int hsize=0;
void insert(long long int value,long long int priority)
  {   
      long long int i,j;
      hsize++;
      pqueue[hsize-1].data=value;
      pqueue[hsize-1].p=priority;
      i=hsize-1;
      while(i>0&&(pqueue[i/2].p>pqueue[i].p))
      { 
        j=i/2;
        swap(i,j);
        i=j;
      }
  }



void get_min()
{
    if(hsize==0)
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("%lli (%lli)\n",pqueue[0].data,pqueue[0].p);
    }
}
long long int left(long long int i)
{
   long long int x;
   x=2*i+1;
   return(x);
}
long long int right(long long int i)
{
   long long int x;
   x=2*i+2;
   return(x);
}
void minheapify(long long int i)
{
   long long int l=left(i);
   long long int r=right(i);
   long long int small=i;
   if (l<hsize && pqueue[l].p<pqueue[small].p)
   {	
 	small=l;
   }
   if (r<hsize && pqueue[r].p<pqueue[small].p)
   {
 	small=r;
   }
   if (small!=i)
   {
        swap(i,small);
        minheapify(small);
   }
}

void decrease_priority(long long int value,long long int key)
{

   long long int i,k,j;
   for(i=0;i<hsize;i++)
   {
      if(pqueue[i].data==value)
      {
         k=i;
         break;
      }
   }
   if(pqueue[k].p<= key)
   {
      return;
   }
   else
   {
       pqueue[k].p=key;
       while(k>0 && (pqueue[k/2].p)>(pqueue[k].p))
       {
          j=k/2;
          swap(k,j);
          k=j;
       }
   }
}

void extract_min()
{
   if(hsize==0)
   printf("EMPTY\n");
   else
   {
      printf("%lli (%lli)\n",(pqueue[0].data),(pqueue[0].p));
      pqueue[0].data=pqueue[hsize-1].data;
      pqueue[0].p=pqueue[hsize-1].p;
      hsize--;
      minheapify(0);
   }
}





int main()
{
 char ch;
 long long int value,priority;
 scanf("%c",&ch);
 while(ch!='s')
 {
    switch(ch)
    {
      case 'a':scanf("%lli %lli",&value,&priority);
               insert(value,priority); 
               break;
      case 'g':get_min(); 
               break;
      case 'd':scanf("%lli %lli",&value,&priority);
               decrease_priority(value,priority);
               break;
      case 'e':extract_min();
               break;
      case 's': 
               break;
    }
    scanf("%c",&ch);
 }
}

