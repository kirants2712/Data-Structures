//prgm to implement caesar's cipher

/*Write a program to encrypt / decrypt a given string S of length N. Encryption of string is
performed by shifting up the letters in the string by a fixed number K. While decryption of string is
performed by shifting down the letters in the string by a fixed number K.

Input: Encrypt / Decrypt option along with string S.

Output: Shifted String

Example:
Input:
      1. Encryption 
      2. Decryption
Enter your choice   : 1
Enter String length : 11
Enter String        : middle-Outz
Enter K             : 2
Output: okffng-Qwvb*/


#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int i, choice, length, k;
    char stg[10000];
    scanf("%d", &choice);
    scanf("%d", &length);
    ++length;
    for(i = 0; i < length; ++i)
    scanf("%c", &stg[i]);
    scanf("%d", &k);
    if (choice == 1)
    {
        for (i = 0; i < length; i++)
        {
            if (isalpha(stg[i]))
            {
                if (isupper(stg[i]))
                {
                    if ((stg[i] + k) > 90)
                    {
                        stg[i] = 64 + (stg[i] + k) % 90;
                    }
                    else
                    {
                        stg[i] = stg[i] + k;
                    }
                }
                else
                {
                    if ((stg[i] + k) > 122)
                    {
                        stg[i] = 96 + (stg[i] + k) % 122;
                    }
                    else
                    {
                        stg[i] = stg[i] + k;
                    }
                }
            }
        }
    }
    else if (choice == 2)
    {
        for (i = 0; i < length; i++)
        {
            if (isalpha(stg[i]))
            {
                if (isalpha(stg[i]))
                {
                    if (isupper(stg[i]))
                    {
                        if ((stg[i] - k) < 65)
                        {
                            stg[i] = 91 - (65 - (stg[i] - k));
                        }
                        else
                        {
                            stg[i] = stg[i] - k;
                        }
                    }
                    if (islower(stg[i]))
                    {
                        if ((stg[i] - k) < 97)
                        {
                            stg[i] = 123 - (97 - (stg[i] - k));
                        }
                        else
                        {
                            stg[i] = stg[i] - k;
                        }
                    }
                }
            }
        }
    }
    printf("%s", stg);
    return 0;
}
