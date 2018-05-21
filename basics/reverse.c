// Write a program that reverses a string recursively without using any extra memory (inplace).
#include<stdio.h>
#include<string.h>
void recur(char val[], int llim, int ulim)
{
    if (llim >= ulim)
    {
        printf("%s",val);
        return ;
    }
    else
    {
        val[llim]+=val[ulim];
        val[ulim]=val[llim]-val[ulim];
        val[llim]=val[llim]-val[ulim];
        --ulim;
        ++llim;
        recur(val, llim,ulim);
    }
}

int main()
{
    char val[100000];
    int length;
    scanf("%s", val);
    length=strlen(val);
    --length;
    recur(val, 0, length);
}
