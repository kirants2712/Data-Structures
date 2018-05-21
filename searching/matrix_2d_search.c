/*
​ Given an M x N matrix in which every row and column is sorted in increasing order. Write a program to find whether a given element K is
present in matrix or not in O(M+N). Print 1 if K is present in the matrix,otherwise print -1.
*/

#include<stdio.h>

int main()
{

int i,j,row,column,a[700][700];
int found=-1;
scanf("%d %d",&row,&column);
for(i=0;i<row;i++)
{
  for(j=0;j<column;j++)
  {
     scanf("%d",&a[i][j]);
  }
}
int ele;
scanf("%d",&ele);

i=0;
j=column-1;
while(j>=0 && i!=row)
{  
  if(a[i][j]==ele)
  {
    found=1;
    break;
  }
  else if(a[i][j]>ele)
  {  
    j--;
  }
  else
  {
    i++; 
  } 
}

printf("%d",found);
return 0;
} 
