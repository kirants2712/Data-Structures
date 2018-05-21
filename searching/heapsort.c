//Write a program to find Kth largest element in an unsorted array of size N in O(N + K log(N) ) time.

#include<stdio.h>
#include<stdlib.h>

int lefti(int i)
{
  return((i*2)+1);
}
int righti(int i)
{
  return((i*2)+2);
}
void max_heapify(int *arr,int i,int n)
{
 int l,r,largest,swap;
 largest=i;
 l=lefti(i);
 r=righti(i);
 if((l<n)&&(arr[l]>arr[largest]))
 {
  largest=l;
 }
 if((r<n)&&(arr[r]>arr[largest]))
 {
  largest=r;
 }
 if(largest!=i)
 {
  //printf("\narr[largest]=%d\narr[i]=%d\n",arr[largest],arr[i]);
  swap=arr[i];
  arr[i]=arr[largest];
  arr[largest]=swap;
  //printf("\narr[largest]=%d\narr[i]=%d\n",arr[largest],arr[i]);
  max_heapify(arr,largest,n);
 }
}
int hsort(int *arr,int n,int k)
{
 int i,swap;
 for(i=n/2-1;i>=0;i--)
 {
  max_heapify(arr,i,n);
 }
 int j;
 for(i=n-1,j=1;i>=0;i--,j++)
 {
  //printf("arr[%d]=%d",j,arr[0]);
  if(j==k)
  {
    return arr[0];
  }
  //printf("\narr[0]=%d\narr[i]=%d\n",arr[0],arr[i]);
  swap=arr[0];
  arr[0]=arr[i];
  arr[i]=swap;
  //printf("\narr[0]=%d\narr[i]=%d\n",arr[0],arr[i]);
  max_heapify(arr,0,i);
 }
}
int main()
{
 int arr[100000],k,size,i,ele;
 scanf("%d",&size);
 for(i=0;i<size;++i)
 {
  scanf("%d",&arr[i]);
 }
 scanf("%d",&k);
 if(k>size||k==0)
 {
  printf("error\n");
  exit(0);
 }
 ele=hsort(arr,size,k);
 printf("%d",ele);
 return(0);
}
