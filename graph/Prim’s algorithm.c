//Write programs that compute the minimum spanning tree of a connected undirected graph using Prim’s algorithm
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct adjlist adjlist;
typedef struct edge edge;

struct adjlist
{
    int key,d;
    struct adjlist* parent;
    struct adjlist* next;
 };

 adjlist* adj[10000];
 int n;
 int n2;
 int e;
 int sum=0;
 int head=0;

struct edge
 {
     int src,dest,w;
 };

edge edg[10000];

 void printedg()
{
    int i;
    for(i=0;i<e;++i)
  {
      printf("\n %d %d %d",edg[i].src,edg[i].w,edg[i].dest);
  }
}

void sort()
{
    int i,j=0;
    adjlist* temp[n];
    for(i=head;i<n;++i)
        temp[j++]=adj[i];
    n2=j;
    for( i=0;i<n2-1;++i)
    {
       for(j=0;j<n2-i-1;++j)
       {
         if(temp[j]->d > temp[j+1]->d)
         {
             adjlist* t=temp[j];
             temp[j]=temp[j+1];
             temp[j+1]=t;
        }
       }
    }
    for( i=head;i<n;++i)
    {
        adj[i]=temp[i-head];
    }

}
void insert(adjlist** head,long int k)
{struct adjlist* p= (adjlist*)malloc(sizeof(adjlist));
struct adjlist* l= (adjlist*)malloc(sizeof(adjlist));
struct adjlist* prev= (adjlist*)malloc(sizeof(adjlist));
    p->next=NULL;
    p->key=k;
 l=*head;
 prev=*head;
 l=l->next;
if (l==NULL)
 {
  (*head)->next=p;}
 else
{while(l!=NULL && l->key<p->key)
   {prev=l;
   l=l->next;}
   prev->next=p;
   p->next=l;
    }
}


 int checkbelong(int x)
 {
     int i;
     for(i=head;i<n;++i)
        if(adj[i]->key==x)
          return 1;
     return 0;
 }

 adjlist* extract_min()
 { if(head==n-1)
   {head=-1;
    return adj[n-1];
    }
   else
    {++head;
     return adj[head-1];
     }
  }

int getweight(int x,int y)
{
    int i;
    for(i=0;i<e;++i)
    {
        if(edg[i].src==x && edg[i].dest==y)
           {return edg[i].w;}
    }
    return(0);
 }

 void mst()
 {adj[0]->d=0;

  int i,j;

  while(head!=n-1)
  {
   adjlist* l=extract_min();


   for(i=0;i<n;++i)
    {if(l->key==adj[i]->key)
      break;
     }
   l=adj[i]->next;
  // printf("\nkey: %d d: %d",adj[i]->key,adj[i]->d);

   while(l!=NULL)
   {int f=checkbelong(l->key);
    int w=getweight(adj[i]->key,l->key);

    for(j=0;j<n;++j)
       {if(l->key==adj[j]->key)
          break;
        }
    if(f==1 && w<adj[j]->d)
     {
      adj[j]->d=w;
      sort();
     }
    l=l->next;
    }
   }
 }


 int main()
{
    int i,d;
    char ch=0;
    scanf("%d",&n);
    ch=getchar();
    for(i=0;i<n;++i)
    {
        adjlist* temp=(adjlist*)malloc(sizeof(adjlist));
        temp->key=i;
        temp->next=NULL;
        temp->d=32567;
        adj[i]=temp;
        ch=getchar();
        while(ch!='\n')
        {
            d=0;
            while(ch!='\n' && ch!=' ')
            {
                d=10*d+ch-48;
                ch=getchar();
            }
            insert(&adj[i],d);
            if(ch!='\n')
                ch=getchar();
        }

    }
    adjlist* l;
    for(i=0;i<n;++i)
    {
        l=adj[i]->next;
        while(l!=NULL)
        {
            scanf("%d",&d);
            edg[e].src=i;
            edg[e].w=d;
            edg[e].dest=l->key;
            l=l->next;
            ++e;
        }
    }
    n2=n;
    mst();
    for(i=0;i<n;++i)
        sum=sum+adj[i]->d;
    printf("%d",sum);
    return(0);
  }
