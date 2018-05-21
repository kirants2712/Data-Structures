//Given an input binary file "in" of integers, sort it using 3-way merge sort and write the output to file “out”.
#include<stdio.h>
#include<limits.h>
#include<ctype.h>
typedef long int dtype;
void merge(dtype *a,dtype p,dtype q,dtype r)
{
    dtype x[100000],y[100000],z[100000],i;
    dtype j=0;
    for(i=p;i<p+r+1;++i,++j)
    {
      x[j]=a[i];
    }
    x[j]=INT_MAX;
    j=0;
    for(i=p+r+1;i<p+(2*r)+2;++i,++j)
    {
      y[j]=a[i];
    }
    y[j]=INT_MAX;
    j=0;
    for(i=p+(2*r)+2;i<q+1;++i,++j)
    {
      z[j]=a[i];
    }
    z[j]=INT_MAX;

    dtype ax,ay,az;
    ax=ay=az=0;
    for(i=p;i<=q;i++)
    {
       if(x[ax]<=y[ay] && x[ax]<=z[az])
       {
          a[i]=x[ax];
          ++ax;
       }
       else if(y[ay]<=z[az])
       {
          a[i]=y[ay];
          ++ay;
       }
       else
       {
          a[i]=z[az];
          ++az;
       }
    }
}

void merge_sort(dtype *arr,dtype p,dtype q)
{
 dtype m;
 if(p<q)
 {
   m=(q-p)/3;
   merge_sort(arr,p,p+m);
   merge_sort(arr,p+m+1,p+(2*m)+1);
   merge_sort(arr,p+(2*m)+2,q);
   merge(arr,p,q,m);
 }
}


int main()
{
    dtype arr[100000],num;
    dtype length;
    FILE *ofile,*ifile;
    ifile=fopen("in","rb");
    if(ifile==NULL)
    { 
        printf("cannot open inputfile\n");
        return 0;
    }
    ofile=fopen("out","wb");
    if(ofile==NULL)
    { 
        printf("cannot open outputfile\n");
        return 0;
    }
    dtype i=0;
    fread(&num,sizeof(dtype),1,ifile);
    while(!feof(ifile ))
    {
        arr[i]=num;
        //printf("%li-",num);
        ++i;
        fread(&num,sizeof(dtype),1,ifile);
    }
    length=i;
    printf("\n");
    merge_sort(arr,0,length-1);
    for(i=0;i<length;i++)
    {
        num=arr[i];
        //printf("%li-",num);
        fwrite(&num,sizeof(dtype),1,ofile);
    }
    fclose(ifile);
    fclose(ofile);
}


