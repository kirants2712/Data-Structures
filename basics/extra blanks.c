
//prgm to edit(remove excess space) a txt file
/*
Write a program that accesses the contents of a text file say, "in.txt" , and modifies the each line in
it by replacing two or more consecutive blanks in a string by a single blank and writes the output
to a new file "out.txt".

Example:
Input: Welcome        to       CS  2094 : Data Structure Lab ("in.txt")
Output: Welcome to CS 2094 : Data Structure Lab  ("out.txt")
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *ifilep, *ofilep;
    char c;
    ifilep = fopen("in.txt", "r");
    if (ifilep == NULL)
    {
        printf("Can't open input file\n");
        exit (1);
    }
    ofilep = fopen("out.txt", "w");
    if (ifilep == NULL)
    {
        printf("Can't open output file\n");
        exit (1);
    }
    while ((c = fgetc(ifilep)) != EOF)
    {
        if(c!=' '||c!='\t')
        {
            fputc(c, ofilep);
        }
        if (c == ' ')
        {
            while ((c = getc(ifilep)) == ' '|| (c == '\t'))
            {
            }
            fputc(c, ofilep);
        }
    }
    fclose(ifilep);
    fclose(ofilep);
}
