/*Write a C program that accepts a n × n matrix and recursively finds its transpose (in place). Print the result of the transposed matrix in spiral form (left->right, top->bottom, bottom->left and then left->up).*/
#include<stdio.h>
void spiral(int arr[][700],int a,int size)
{
    int i;
    if(a>size/2)
    {  
        return;
    }
    //right->left
    for(i=a;i<size-a;++i)
    {
        printf("%d ",arr[a][i]);
    }
    //top->down
    for(i=a+1;i<size-a;++i)
    {
        printf("%d ",arr[i][size-1-a]);
    }
    //left->right
    for(i=size-2-a;i>=a;--i)
    {
        printf("%d ",arr[size-1-a][i]);
    }
    //bottom->up
    for(i=size-2-a;i>a;--i)
    {
        printf("%d ",arr[i][a]);
    }
    spiral(arr,a+1,size);
}


void transpose(int arr[][700],int row,int column,int flag,int size)
{
    int swap;
    if(row>(size/2))
    {
        return;
    } 
    else if(column>size-1)
    {
        transpose(arr,row+1,flag+1,flag+1,size);
    }
    else
    {
        swap=arr[row][column];
        arr[row][column]=arr[column][row];
        arr[column][row]=swap;
        transpose(arr,row,column+1,flag,size);
    }
}

int main()
{
    int arr[700][700],i,j,size;
    scanf("%d",&size);
    for(i=0;i<size;++i)
    {
        for(j=0;j<size;++j)
        {
            scanf("%d",&arr[i][j]);
        }    
    }
    transpose(arr,0,0,0,size);
    spiral(arr,0,size);
}






