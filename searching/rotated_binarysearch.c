/*
Given a sorted rotated array of N distinct integers, search a given element in this array in O(logN). If found then print the index (starting
from 0) otherwise print -1.
*/
#include<stdio.h>

int bsearch(int *arr,int first,int last,int ele) 
 {
  int el,eu,em;
  el=first;
  eu=last-1;
  while(el<=eu)
  {
   em=el+((eu-el)/2);
   if(arr[em]==ele)
   {
    return(em);
    }
   else if(arr[el]<arr[em])
   {
    if((arr[el]<=ele)&&(ele<=arr[em]))
    {
       eu=em-1;
    }
    else
    {
       el=em+1;
    }
   }
   else
   { 
    if((arr[em]<=ele)&&(ele<=arr[eu]))
    {
       el=em+1;
    }
    else
    {
       eu=em-1;
    } 
   }
  }
  return(-1);
}

int main()
{
 int i,ele,n,arr[100000];
 int flag;
 scanf("%d",&n);
 for (i=0;i<n;++i)
 {
   scanf("%d",&arr[i]);
 }
 scanf("%d",&ele);
 flag=bsearch(arr,0,n,ele);
 i=0;
 if(flag!=-1)
 {
   while (i<=flag)
   {
     printf("%d ",i);
     ++i;
   }
 }
 else
 {
   printf("-1");
 }
 return (0);
}

