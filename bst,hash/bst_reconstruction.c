/*
Given the preorder and inorder traversal of a binary tree with unique keys, design and
implement an algorithm to create the binary tree and print it in a list (scheme like) format.
Input format
● The first line contains a positive integer, representing the number of nodes in the tree.● The second line contains ​ n space separated integers, representing a valid preorder
traversal of a tree.
● The third line contains ​ n ​ space separated integers, representing a valid inorder traversal of
the tree.
Output format
● Single line representing the binary tree in a scheme like format separated by a single
white space
Sample Input
10
43 15 8 30 20 35 60 50 82 70
8 15 20 30 35 43 50 60 70 82
Sample Output
( 43 ( 15 ( 8 ( ) ( ) ) ( 30 ( 20 ( ) ( ) ) ( 35 ( ) ( ) ) ) ) ( 60 ( 50 ( ) ( ) ) ( 82 ( 70 ( ) ( ) ) ( ) ) ) )
Sample Input
11
55 28 74 96 20 59 42 13 52 82 44
96 74 28 59 20 42 55 13 82 52 44
Sample Output
( 55 ( 28 ( 74 ( 96 ( ) ( ) ) ( ) ) ( 20 ( 59 ( ) ( ) ) ( 42 ( ) ( ) ) ) ) ( 13 ( ) ( 52 ( 82 ( ) ( ) ) ( 44 ( ) ( ) )
) ) )
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct binarysearchtree bst;
typedef long long int lli;
lli preindex = 0;

struct binarysearchtree
{
    lli key;
    struct binarysearchtree *left,*right;
};

bst *createnewnode(lli key)
{
	bst *newnode=(bst*)malloc(sizeof(bst));
	newnode->key=key;
 	newnode->left=NULL;
 	newnode->right=NULL;
	return(newnode);
}

lli search(lli arr[], lli s, lli e, lli value)
{
  int i;
  for(i = s; i <= e; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

bst* buildbst(lli io[], lli po[], lli s, lli e)
{
  
  if(s>e)
     return NULL;
  bst *Node = createnewnode(po[preindex++]);
   if(s==e)
    return Node;
  lli inindex = search(io, s, e, Node->key);
  Node->left = buildbst(io, po, s, inindex-1);
  Node->right = buildbst(io, po, inindex+1, e);
  return Node;
}

void preorder(bst *root)
{
    if(root==NULL)
     {
         return;
     }
    printf("(");
    printf(" %lli ",root->key);
    if(root->right==NULL && root->left==NULL)
        printf("() ()");
    preorder(root->left);
    if(root->right!=NULL && root->left==NULL)
        printf("()");
    preorder(root->right);
    if(root->right==NULL && root->left!=NULL)
        printf("()");
    printf(" ) ");
}
void main()
{
    lli n;
    scanf("%lli",&n);
    lli po[n],io[n],i;
    for(i=0;i<n;++i)
        scanf("%lli",&po[i]);
    for(i=0;i<n;++i)
        scanf("%lli",&io[i]);
    bst *root=buildbst(io,po,0,n-1);
    preorder(root);
    
}
