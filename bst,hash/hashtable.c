/*
Write a C program to implement hash table data structure to store student’s information with
roll number as key. The Hash table should support the following operations :-
● hashTable(int m)​ - create a hash table of size m
● insert(int k)​ - insert element into hash table having key value as k
● search(int k)​ - find whether element with key ‘k’ is present in hash table or not
● delete(int k) ​ - delete the element with key ‘k’
Input Format:
The first line contains a character from { ‘a’, ‘b’, ‘c’, ‘d’} denoting
● a​ - Collision resolution by Linear probing with hash function
h(k,i) = ( h​ 1​ (k) + i) mod m
where
h​ 1​ (k) = k mod m
● b​ - Collision resolution by Quadratic probing with hash function
h(k,i) = ( h​ 1​ (k) + i​ 2​ ) mod m
where
h​ 1​ (k) = k mod m
● c ​ - Collision resolution by Double Hashing with hash functions
h(k,i) = ( h​ 1​ (k) + i*h​ 2​ (k) ) mod m
where,
h​ 1​ (k) = k mod m ,
h​ 2​ (k) = R - (k mod R ) { R = Prime number just smaller than size of table }
● d ​ - Collision resolution by Chaining with hash functionh(k) = k mod m
Where,
k = Key,
m = size of hash table
Next line contains an integer, m, denoting the size of hash table.
Next lines contains a character from { ‘i’, ‘s’, ‘d’, ‘p’, ‘t’ } followed by zero or one integer.
● i x - insert the element with key x into hash table
● s x - search the element with key x in hash table. ​ Print 1 if present otherwise print -1
● d x - delete the element with key x from hash table.
● p - ​ print the hash table in “index (key values)” pattern​ . See sample output for
explanation
● t - terminate the program
Note
● In case of Linear probing, quadratic probing and Double hashing, total elements (n) to be
inserted into hash table will be lesser than or equal to size of hash table (m) i.e. ​ n<=m
● deletion operation will always be a valid operation
● While printing the hash, multiple key values must be separated by a single white space.
Sample Input
a
7
i 76
i 93
i 40
i 47
i 10
i 55
ps 35
s 47
d 47
s 55
t
Sample Output
0 (47)
1 (55)
2 (93)
3 (10)
4 ()
5 (40)
6 (76)
-1
1
1
Sample Input
b
7
i 76
i 40
i 48
i 5
s 5
i 55
p
s 62
d 55s 40
s 55
t
Sample Output
1
0 (47)
1 ()
2 (5)
3 (55)
4 ()
5 (40)
6 (76)
-1
1
-1
Sample Input
c
7
i 76
i 93
i 40
i 47
i 10
i 55
p
d 40
s 47
s 76s 40
t
Sample Output
0 ()
1 (47)
2 (93)
3 (10)
4 (55)
5 (40)
6 (76)
1
1
-1
Sample Input:
d
5
i 25
i 11
i 10
i 21
i 15
p
s 26
s 15
d 10
s 10
t
Sample Output0 (25 10 15)
1 (11 21)
2 ()
3 ()
4 ()
-1
1
-1
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct hashtable hash;
typedef long long int lli;
char ht;
struct hashtable
{   
    
    lli data;
    struct hashtable *next;
}*newnode,*temp,*a;

lli m,r;
void primenumber()
{
    lli i,j,o;
    lli k=1;
    for(j=m-1;j>1;--j)
    {  
        for(o=2;o<j/2;++o)
        {
		if(j%o==0)
	        {
		   k=0;
	        }
	}
	if(k)
        {
            r=j;
            return;
        }
    }
}
void hashTable(lli m)
{ 
    lli i;
    a=(hash*)malloc(m*(sizeof(hash)));
    for(i=0;i<m;++i)
    {   
        a[i].data=0;
       
    }
}
void insert(lli key)
{ 
   lli j,i,k,l;
   j=key%m;
   if(ht=='a')
   { 
      i=0;
      k=(i+j)%m;
      while(a[k].data!=0)
      {
          i++;
          k=(i+j)%m;
      } 
      a[k].data=key;
   }

   if(ht=='b')
   { 
      i=0;
      l=i*i;
      k=(j+l)%m;
      while(a[k].data!=0)
       {
           i++;
           l=i*i;
           k=(j+l)%m;

       }
      a[k].data=key;
    }
    if(ht=='c')
    { 
        lli l;
        i=0;
        primenumber();
        k=r-(key%r);
        l=(j+i*k)%m;
        while(a[l].data!=0)
        {
           i++;
           l=(j+i*k)%m;
        }
        a[l].data=key;
     }
    if(ht=='d')
    {
        
        newnode=(hash*)malloc(sizeof(hash));
        newnode->data=key;

        if(a[j].data==0)
        { 
           a[j].data=-1;
           newnode->next=NULL;
           a[j].next=newnode;
        }
        else
        {
            temp=a[j].next;
            {
                while(temp->next!=NULL)
                {
                   temp=temp->next;
                } 
                temp->next=newnode;
                newnode->next=NULL;
            }
        }
    }
}
void search(lli key)
{
    lli i;
    lli n=key%m;
   if(ht=='a'||ht=='b'||ht=='c')
   {
      for(i=0;i<m;++i)
      {
        if(a[i].data==key)
        {
           printf("1\n");
           return;
        }
      }
      printf("-1\n");
   }
   else
   {
	 if(a[n].data!=0)
        {
           newnode=a[n].next;
           while(newnode!=NULL)
           {
             if(newnode->data==key)
             {
                printf("1\n");
                return;
             }
             newnode=newnode->next;    
           }
        } 
       
       printf("-1\n");
   }
}

void delete(lli key)
{
    lli i;
    if(ht=='a'||ht=='b'||ht=='c')

    {
        for(i=0;i<m;++i)
        {
           if((a[i].data!=0)&&(a[i].data==key))
            {
     		a[i].data=0;
            }
 	}
    }
    else
    { 
      i=key%m;
      {
          if(a[i].data==0)
            printf("-1\n");
          else
          {
              if((a[i].next)->data==key)
              {   
                 if((a[i].next)->next!=NULL)
            	 { 
                	a[i].next=(a[i].next)->next;
                	 return;
              	 }
		 else
                 {
                   a[i].data=0;
                   return;
                 }
              }
              newnode=a[i].next;
              while(((newnode->next)->data)!=key)
              {
                  newnode=newnode->next;
               }
		 newnode->next=(newnode->next)->next;
          }
      }

    }
}
void print()
{ 
  lli i;
   if(ht=='a'||ht=='b'||ht=='c')
  {
    for(i=0;i<m;++i)
    {
        if(a[i].data==0)
            printf("%lli ()\n",i);
        else
            printf("%lli (%lli)\n",i,a[i].data);
    }
  }
  else
  { 
      for(i=0;i<m;++i)
      {
          if(a[i].data==0)
          {
              printf("%lli ()\n",i);

          }
          else
          {
              printf("%lli (",i);
              newnode=a[i].next;
              while(newnode->next!=NULL)
              {
                  printf("%lli ",newnode->data);
                  newnode=newnode->next;
              } printf("%lli)\n",newnode->data);

          }
      }
  }
}

void main()
{
  char c;
  lli key;
  scanf("%c",&ht);
  scanf("%lli",&m);
  hashTable(m);
  
  scanf("%c",&c);
  do 
  {
      if(c=='i')
      {
          scanf("%lli",&key);
          insert(key);
      }
      if(c=='s')
      {
          scanf("%lli",&key);
          search(key);
      }
      if(c=='d')
      {
          scanf("%lli",&key);
          delete(key);
      }
      if(c=='p')
      {
        print();
      }
      if(c=='t')
      {
         break;
      }
      scanf("%c",&c);
   }while(c!='t');

}
