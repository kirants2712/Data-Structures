//Write programs that compute the minimum spanning tree of a connected undirected graph using Kruskal’s algorithm
#include<stdio.h>
#include<stdlib.h>
typedef struct vertex vertex;
typedef struct edge edge;
struct vertex
{
	int key;
	struct vertex *parent;
}*v[10000];

struct edge
{
	int u,v,w;
	struct edge *next;
}edge_array[100000];

int n,ctr=0,sum=0;
void makeset(int x)
{	vertex *ptr=(vertex*)malloc(sizeof(vertex));
	ptr->key=x;
	ptr->parent=ptr;
	v[x]=ptr;
}
vertex* find(int x)
{	if(v[x]==NULL)
		return NULL;
	vertex *ptr=v[x];
	while(ptr!=NULL)
	{	if(ptr->parent==ptr)
			return ptr;
		ptr=ptr->parent;
	}
}
void union1(int x,int y)
{

	if(find(x)==NULL||find(y)==NULL)
		{
		printf("ERROR\n");
		return;
		}

	if(find(x)==find(y))
		return;


	find(y)->parent=find(x);
	return;
}


void sort()
{	int i,j;
	for(i=0;i<ctr-1;i++)
		for(j=0;j<ctr-1;j++)
			if(edge_array[j].w>edge_array[j+1].w)
			{
				edge temp=edge_array[j];
				edge_array[j]=edge_array[j+1];
				edge_array[j+1]=temp;
			}
}

void kruskal()
{	int i;
	for(i=0;i<n;i++)
		makeset(i);
	sort();

	for(i=0;i<ctr;i++)
	{
		if(find(edge_array[i].u)!=find(edge_array[i].v))
		{	union1(edge_array[i].u,edge_array[i].v);
			sum+=edge_array[i].w;
		}

	}


}

int main()
{	int i,x;
	char ch;
	for(i=0;i<10000;i++)
	{
		v[i]=NULL;
	}

	scanf("%d",&n);

	i=0;
	while(i<n)
	{
		scanf("%d",&x);
		edge_array[ctr].u=i;
		edge_array[ctr].v=x;
		ch=getchar();
		ctr++;
		if(ch=='\n')
			i++;
	}

	i=0;int j=0;
	while(i<n)
	{
		scanf("%d",&x);
		edge_array[j].w=x;
		ch=getchar();
		j++;
		if(ch=='\n')
			i++;
	}


	kruskal();
	printf("%d",sum);

return 0;}












