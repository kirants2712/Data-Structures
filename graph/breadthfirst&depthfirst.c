//Write a program to perform depth-first and breadth-first searching on a directed graph.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct graph node;

struct graph
{
    int v;
    struct graph *next;
};

 int n;
 node a[10000];

 node *head=NULL;
 node *head1=NULL;
 node *end1=NULL;

void push(int x)
{
   node *newnode;
   newnode=(node*)malloc(sizeof(node));
   newnode->v=x;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

int pop()
{
 int i;
    if(head==NULL)
        return -1;
    else
    {
        i=head->v;
        head=head->next;
        return i;
    }
}

void enqueue(int x)
{
   node *newnode;
   newnode=(node*)malloc(sizeof(node));
   newnode->v=x;
   newnode->next=NULL;
   if(head1==NULL)
   {
     head1=newnode;
     end1=newnode;
   }
   else
   {
       end1->next=newnode;
   }

}

int dequeue()
{
    int i;
    if(head1==NULL)
    {
        return -1;
    }
    if(head1->next==NULL)
    {
        i=head1->v;
        head1=end1=NULL;
        return i;
    }
    else
    {
        i=head1->v;
        head1=head1->next;
        return i;
    }
}


void depth(int start,int key,int s[])
{
   int i;
   node *temp;
   push(start);
   s[start]=1;
   while(head!=NULL)
   {
      i=pop();
      printf("%d ",i);
      if(i==key)
      {
          return;
      }
      temp=(a[i].next);
      while(temp!=NULL)
      {
          if(s[temp->v]==0)
          {
              push(temp->v);
              s[temp->v]=1;


          }
            temp=temp->next;
      }

  }
}


void breadth(int start,int key,int s[])
{
   int i;
   node *temp;
   enqueue(start);
   s[start]=1;

  while(head1!=NULL)
  {
      i=dequeue();
      printf("%d ",i);
      if(i==key)
      {
          return;
      }
      temp=(a[i].next);
      while(temp!=NULL)
      {
          if(s[temp->v]==0)
          {
              enqueue(temp->v);
              s[temp->v]=1;


          }
            temp=temp->next;
      }

  }
}




node* insert(node *a,int x)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->v=x;
    temp->next=NULL;
    if(a==NULL)
        return temp;
    else
    {
        a->next=insert(a->next,x);
    }
    return a;
}

int main()
{
    char b[4]; char c;
     int i; int start,key; int flag;
    scanf("%d",&n);
    int visit[n];


     for(i=0;i<n;++i)
        a[i].next=NULL;

    int count;
    count=-1;
    while(count!=n)
    {  int x=0; flag=0;
        scanf("%c",&c);
        while(c!='\n')
         {  flag++;
            if(c==' ')
                {
                    a[count].next=insert(a[count].next,x);
                    x=0;
                }
                else
                {
                    i=c-48;
                    x=x*10+i;
                }
                scanf("%c",&c);

        } if(flag!=0)
          a[count].next=insert(a[count].next,x);

           count++;
    } scanf("%s",b);
      flag=strcmp("stp",b);
      while(flag!=0)

        {  flag=strcmp("bfs",b);
         if(flag==0)
         {    for(i=0;i<n;++i)
                   visit[i]=0;
                scanf("%d %d",&start,&key);
                breadth(start,key,visit);
                printf("\n");
                head1=NULL;
                end1=NULL;
         }
         flag=strcmp("dfs",b);
         if(flag==0)
         {       for(i=0;i<n;++i)
                   visit[i]=0;
                scanf("%d %d",&start,&key);
                depth(start,key,visit);
                printf("\n");
                head=NULL;
         }
         scanf("%s",b);
      flag=strcmp("stp",b);


      }
     return 1;
}
