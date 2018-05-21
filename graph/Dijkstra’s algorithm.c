//. Write a program that implements Dijkstra’s algorithm for computing shortest paths in a directed graph with positive edge weights
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linked l;
typedef struct queue queue;

struct queue
{
    int weight;
    int u;
    int v;
    queue *next;
};

struct linked
{
    int v;
    struct linked *next;
    int weight;
};

queue* insertQ(queue *priorQ, int u, int w)
{
    if(priorQ==NULL)
    {
        queue *node=(queue*)malloc(sizeof(queue));
        node->u=u;
        node->weight=w;
        node->next=NULL;
        return node;;
    }
    else
    {
        if(priorQ->weight > w)
        {
                queue *node=(queue*)malloc(sizeof(queue));
                node->u=u;
                node->weight=w;
                node->next=NULL;
                node->next = priorQ;
                return node;
        }
        else
        {
            priorQ->next = insertQ(priorQ->next, u, w);
            return priorQ;
        }
    }
}

int n; l a[10000]; int power=0;

int check(int s[])
{
    int i;
    for(i=0;i<n;++i)
    {
    if(s[i]==0)
        return 0;
    } return 1;
}

int minimum(int t[],int s[])
{
    int min=10001;
    int i; int index=0;
    for(i=0;i<n;++i)
       {
        if(t[i]<min&&s[i]==0)
       {
        min=t[i];
        index=i;

       }
       }
       s[index]=1;
    return index;

}



void prim(int g,int h)
{ int i;
   int intern=1;
   if(h==10001)
     intern=0;
    int s[n];
    for(i=0;i<n;++i)
        s[i]=0;
     int t[n];
     int min;  power=0;
     for(i=0;i<n;++i)
        t[i]=10001;

       t[g]=0;
       queue *priorQ = NULL;
       priorQ = insertQ(priorQ, g, t[g]);

      min=minimum(t,s);
    while(priorQ != NULL)
    {
        l *temp;
        min = priorQ->u;
        priorQ = priorQ->next;

        temp=a[min].next;

        while(temp!=NULL)
        {   if(s[temp->v] != 1)
            {
                if(t[temp->v]>(t[min]+temp->weight))
                {
                    t[temp->v]=t[min]+temp->weight;
                    priorQ = insertQ(priorQ, temp->v, temp->weight);
                }
            }

            temp=temp->next;
        }

    s[min] = 1;
    }

       if(intern==0)
       {
        for(i=0;i<n;++i)
      { if(t[i]==10001)
        printf("INF ");
        else
            printf("%d ",t[i]);

      }
       }
      else
      { if(t[h]==10001)
          printf("UNREACHABLE");
          else
          printf("%d ",t[h]);
      }
        printf("\n");
}


l* insert(l *aa,int x)
{
    l *temp=(l*)malloc(sizeof(l));
    temp->v=x;
    temp->next=NULL;
    temp->weight=10001;
    if(aa==NULL)
        return temp;
    else
    {
        aa->next=insert(aa->next,x);
    }
    return aa;
}



int main()
{
    int minus; char c; char z[5];
    int i;
    int flag;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
      a[i].next=NULL;
    }
    int count;
    int x;
    count=-1;
    while(count!=n)
    {
        x=0; flag=0;
        scanf("%c",&c);
        while(c!='\n')
         {
            flag++;
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

         }
         if(flag!=0)
             a[count].next=insert(a[count].next,x);
         count++;
    }

    count=0;
    while(count!=n)
    {
        x=0; flag=0; minus=1; l* node;
        scanf("%c",&c);
        node=a[count].next;
        while(c!='\n')
         {  flag++;

            if(c==' ')
                {   x=x*minus;

                    node->weight=x;
                    node=node->next;

                    x=0;
                    minus=1;
                }
                else
                {  if(c=='-')
                     minus=-1;
                     else
                    {
                      i=c-48;
                      x=x*10+i;
                    }
                }
                scanf("%c",&c);

        } if(flag!=0)
           {  x=x*minus;
               node->weight=x;
           }
           count++;

    }
scanf("%s",z); int g,h;
minus=strcmp("stop",z);
while(minus!=0)
{
    minus=strcmp("apsp",z);
    if(minus==0)
    {
        scanf("%d",&g);
        prim(g,10001);
    }
    minus=strcmp("sssp",z);
    if(minus==0)
    {
        scanf("%d %d",&g,&h);
        prim(g,h);
    }
    scanf("%s",z);
   minus=strcmp("stop",z);
}

return 1;
}
