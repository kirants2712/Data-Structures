/*
Write a program to implement modified quick sort. A modified quick sort uses a modifies partition method which always chooses median element of
an array as a pivot in O(n) time. Print the median values for ​ first 3 iterations​ before printing the final sorted array.
*/
#include<stdio.h>
int partitionmid(int *arr,int first,int last)
{
 int swap,j;
 int pivot=arr[last];
 int i=first-1;
 for(j=first;j<last;++j)
 {
   if(arr[j]<=pivot)
   {
     ++i;
     swap=arr[i];
     arr[i]=arr[j];
     arr[j]=swap;
   }
 }
 swap=arr[i+1];
 arr[i+1]=arr[last];
 arr[last]=swap;
 return(i+1);
}
 
int pivot(int *arr,int first,int last,int midpos) 
{
 int mid,i;
 mid=partitionmid(arr,first,last);
 if(mid==midpos)
 {
   return(mid);
 }
 else if(mid>midpos)
 {
   mid=pivot(arr,first,mid-1,midpos);
   return(mid);
 }
 else 
 {
   mid=pivot(arr,mid+1,last,midpos);
   return(mid);
 }
 
}
void quicksort(int *arr,int first,int last,int times)
{
int middle;
int mid=first+(last-first)/2;
if(first<last)
{
 middle=pivot(arr,first,last,mid);
 if(times>0)
 {
 printf("%d\n",arr[middle]);
 }
 --times;
 quicksort(arr,first,middle-1,times);
 --times;
 quicksort(arr,middle+1,last,times);
}
}
int main()
{
 int n,i,arr[100000];
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 quicksort(arr,0,n-1,3);
 for(i=0;i<n;i++)
 {
  printf("%d ",arr[i]);
 }
 return(0);
}
