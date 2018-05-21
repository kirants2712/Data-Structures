//Write a program to convert the Postfix expression to Infix expression and print the result of the evaluated expression.
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
node *newnode;
node *new;
node *top=NULL;
long long int val;
long long int ar[100000];
node *temp;


struct node
{
  long long int data;
  node *next;
};
node *c_newnode(long long int a)
{
 newnode=(node*)malloc(sizeof(node));
 newnode->data=a;
 newnode->next=NULL;
 return(newnode);
}
void push(long long int val)
{
   new=c_newnode(val);
   if(top==NULL)
     {
        top=new;
     }
   else
   {
    new->next=top;
    top=new;       
   }
}

long long int pop()
{
  int p;
  
  if(top==NULL)
     return -1;
  else
  {
    val=top->data;
    temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
    return val;
  }

}

long long int print()
{
  
  temp=top;
  if(temp==NULL)
    return -1;
  while(temp!=NULL)
  {
    printf("%lli",temp->data);
    temp=temp->next;
  }
  printf("\n");
  return 1;
}

void insert(long long int ptn,char c)
{
long long int i;
for(i=ptn-3;i!=0;i-=2)
    {
        if(ar[i]==-1)
        {
           ar[i]=(long long int)c;
           break;
        }
    }

}

int main()
{
  
char c,ch[10000];

long long int sum,t1,t2,val,ptn,pto;
int i,j,k,l,flag=0;

for(i=0;i<100000;i++)
   ar[i]=-1;

val=0;
sum=0;
ptn=0;
pto=0;
c=getchar();
while(c!='\n')
{
 
   if(c>=48 && c<=57)
   {
      k=(int)c-48;
      sum=sum*10+k;
      flag=0; 
   }
   else if(c==' ' && flag==0)
   {
     push(sum);
     ar[ptn]=sum;
     ptn=ptn+2;
     sum=0;
   }
   else if((c=='*')||(c=='/')||(c=='+')||(c=='-')||(c=='%'))
   { 
      
      switch(c)
      {
         case '*':
               
                    t2=pop();
                    t1=pop();
                    insert(ptn,c);
                    val=(t1*t2);
                    push(val);  
                    flag=-1;  
              
                    break;
          case '/':
                    t2=pop();
                    t1=pop();
                    insert(ptn,c);
                    val=(t1/t2);
                    push(val);
                    flag=-1;    
              
                    break;
          case '+' :
                
                    t2=pop();
                    t1=pop(); 
                    insert(ptn,c);
                    val=(t1+t2);  
                    push(val);
                    flag=-1;     
              
              break;
          case '-' :
                   
                   t2=pop();
                   t1=pop();
                   insert(ptn,c);
                   val=(t1-t2); 
                   push(val);
                   flag=-1; 
              
                   break;
          case '%' :
                
                   t2=pop();
                   t1=pop();
                   insert(ptn,c);
                   val=(t1%t2); 
                   push(val);
                   flag=-1; 
                   break;
    
        }
     }
   c=getchar();
   if(flag==0 && c=='\n')
    { push(sum);
      ar[ptn]=sum;
      ptn=ptn+2;
    }
}  
val=pop();
//printf("yes");
for(i=0;i<ptn-1;i++)
{
  if(i%2==0) 
    printf("%lli",ar[i]); 
  else 
    printf("%c",(char)ar[i]);

}
printf("\n%lli",val);
}
