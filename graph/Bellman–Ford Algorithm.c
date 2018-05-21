#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node node;
int n,m,i;
struct node
{
  int u;
  int v;
  int w;
}*list;

void relax(int v1,int v2,int w,int *d)
{

  if(d[v2]>(d[v1]+w))
  {
    d[v2]=d[v1]+w;
  }
}


int bellford(node *sort,int s)
{

    int d[n],u,v,w;
    for(i=0;i<n;i++)
      d[i]=INT_MAX;
    u=sort[s].u;
    d[u]=0;
    for(i=0;i<n;i++)
      relax(sort[i].u,sort[i].v,sort[i].w,d);
    for(i=0;i<n;i++)
    {
       u=sort[i].u;
       v=sort[i].v;
       w=sort[i].w;
       if(d[v]>d[u]+w)
         return 1;
    }
    return -1;
}
int main()
{

 int val;
scanf("%d %d",&n,&m);
list=(node *)malloc(sizeof(node)*m);

for(i=0;i<m;i++)
  scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);

for(i=0;i<n;i++)
{
  val=bellford(list,i);
  if(val==1)
  {
     printf("1\n");
     return(0);
  }
}
printf("-1\n");
return(0);
}
