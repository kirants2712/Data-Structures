/*
. Create a Binary Search Tree (BST) which supports the following operations:
● insert(tree, element) – adds the node specified by element (which contains the data) into
the BST specified by tree.
● search(tree, key) – searches for the data specified by key in the BST specified by tree.
● findMin(tree) – retrieves the smallest data in the BST specified by tree.
● findMax(tree) – retrieves the largest data in the BST specified by tree.
● predecessor(tree, element) – retrieves the inorder-predecessor of the node specified by
element in the BST specified by tree.
● successor(tree, element) – retrieves the inorder-successor of the node specified by
element in the BST specified by tree.
● delete(tree, element) – removes the node specified by element from the BST specified by
tree.
● inorder(tree) – To do a recursive inorder traversal of the BST.
● preorder(tree) – To do a recursive preorder traversal of the BST.
● postorder(tree) – To do a recursive postorder traversal of the BST.
Input format
The input consists of multiple lines, each containing a four letter string followed by zero or one
integer. The meaning of each line is given below:● String “stop” means stop the program.
● String “insr” means, create a node which contains the next integer(>= 0) from the input
as the data part, and then, insert this node into the BST. In this case, the data is given on
the same line as the string “insr”, separated by a space.
● String “srch” means, search for the key specified by the next integer(>= 0) from the
input, in the BST. In this case, the key is given on the same line as the string “srch”,
separated by a space. If the search is successful, output “FOUND”. Otherwise, output
“NOT FOUND”.
● String “minm” means find and output the minimum value in the BST. Print “NIL” if the
BST is empty.
● String “maxm” means find and output the maximum value in the BST. Print “NIL” if the
BST is empty.
● String “pred” means find and output the inorder-predecessor of the data specified by the
next integer(>= 0) from the input. In this case, the data is given on the same line as the
string “pred”, separated by a space. Output “NIL”, if the data exists in the tree, but there
is no inorder-predecessor for the data. Output “NOT FOUND”, if the data is not present
in the tree.
● String “succ” means find and output the inorder-successor of the data specified by the
next integer(>= 0) from the input. In this case, the data is given on the same line as the
string “succ”, separated by a space. Output “NIL”, if the data exists in the tree, but there
is no inorder-successor for the data. Output “NOT FOUND”, if the data is not present in
the tree.
● String “delt” means delete the data specified by the next integer(&gt;= 0) in the input
from the BST, if present. In this case, the data is given on the same line as the string
“delt”, separated by a space. (Here, the data to be deleted is guaranteed to be present in
the BST).
● String “inor” means output the in-order traversal of the BST.
● String “prer” means output the pre-order traversal of the BST.
● String “post” means output the post-order traversal of the BST.Output format
● The output (if any) of each command should be printed on a separate line.
Note
● Strictly follow the output format​ . It should be NIL, NOT FOUND, FOUND
Sample Input Sample Output
srch 25 NOT FOUND
minm NIL
maxm NIL
pred 25 NOT FOUND
succ 25 NOT FOUND
insr 25
srch 25 FOUND
minm 25
maxm 25
pred 25 NIL
succ 25 NIL
insr 13
insr 50
insr 45
insr 55
insr 18
srch 10 NOT FOUND
srch 13 FOUND
srch 35 NOT FOUND
srch 55 FOUND
srch 80 NOT FOUNDinor 13 18 25 45 50 55
prer 25 13 18 50 45 55
post 18 13 45 55 50 25
minm 13
maxm 55
pred 13 NIL
succ 13 18
pred 18 13
succ 18 25
pred 25 18
succ 25 45
pred 45 25
succ 45 50
pred 50 45
succ 50 55
pred 55 50
succ 55 NIL
delt 55
delt 13
delt 25
minm 18
maxm 50
pred 18 NIL
succ 18 45
pred 45 18
succ 45 50
pred 50 45
succ 50 NIL
delt 45delt 50
delt 18
minm NIL
maxm NIL
insr 90
minm 90
maxm 90
stop
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct binarysearchtree bst;
typedef long long int lli;

struct binarysearchtree
{
    lli key;
    struct binarysearchtree *left,*right;
};
bst *root=NULL,*temp=NULL;
bst *createnewnode(lli key)
{
	bst *newnode=(bst*)malloc(sizeof(bst));
	newnode->key=key;
 	newnode->left=NULL;
 	newnode->right=NULL;
	return(newnode);
}
bst* insert(bst *root,lli key)
{
 if(root==NULL)
    return(createnewnode(key));
 else
    {
        if(key<=(root->key))
        {
          root->left=insert(root->left,key);
        }
        else
        {
          root->right=insert(root->right,key);
        }
    }
   return(root);
}

void inorder(bst *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    printf("%lli ",root->key);
    inorder(root->right);
}

void preorder(bst *root)
{
    if(root==NULL)
     return;
    printf("%lli ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(bst *root)
{
    if(root==NULL)
     return;
    postorder(root->left);
    postorder(root->right);
    printf("%lli ",root->key);
}

bst* min(bst *root)
{
    if(root==NULL)
        return root;
    else
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
}

bst* search(bst *root,lli key)
{
    if(root==NULL)
       {
        printf("NOT FOUND\n");
        return root;
       }
    if(root->key==key)
     {
         printf("FOUND\n");
         return root;
     }
    if(root->key<key)
        return(search(root->right,key));
    if(root->key>key)
        return(search(root->left,key));
}
bst* isearch(bst *root,lli key)
{
    if(root==NULL)
       {
        //printf("NOT FOUND\n");
        return root;
       }
    if(root->key==key)
     {
         //printf("FOUND\n");
         return root;
     }
    if(root->key<key)
        return(isearch(root->right,key));
    if(root->key>key)
        return(isearch(root->left,key));
}

bst* max(bst *root)
{
    if(root==NULL)
        return root;
    else
    {
        while(root->right!=NULL)
        {
            root=root->right;
        }
       return root;
    }
}

void succ(bst *root,int key)
{
    //bst *temp1=NULL;
    temp=isearch(root,key);
    if(temp==NULL)
        {
            printf("NOT FOUND\n");
            return;
        }
    if(temp->right!=NULL)
        {
            printf("%lli\n",min(temp->right)->key);
            return;
        }
    if(temp->right==NULL)
        {
          bst *parent,*last=NULL;
          parent=root;
          if(parent->key<=temp->key)
          {
              parent=parent->right;
          }
          else
          {
            last=parent;
            parent=parent->left;
          }
          while(parent!= temp && parent!=NULL)
          {
           if(temp->key<=parent->key)
            {
                last=parent;
                parent=parent->left;
            }
           else
           {
            parent=parent->right;
           }
          }
          if(last==NULL)
            printf("NIL\n");
          else
          printf("%lli\n",last->key);
        }
     return;
}


void pred(bst *root,lli key)
{
    
    temp=isearch(root,key);
    if(temp==NULL)
        {
            printf("NOT FOUND\n");
            return;
        }
    if(temp->left!=NULL)
        {
            printf("%lli\n",max(temp->left)->key);
            return;
        }
    if(temp->left==NULL)
        {
          bst *parent,*last=NULL;
          parent=root;
          if(parent->key<temp->key)
          {
              last=parent;
              parent=parent->right;
          }
          else
            parent=parent->left;
          while(parent!= temp && parent!=NULL)
          {
           if(temp->key<=parent->key)
            parent=parent->left;
           else
           {
            last=parent;
            parent=parent->right;
           }
          }
          if(last==NULL)
            printf("NIL\n");
          else
          printf("%lli\n",last->key);
        }
    return;
}

bst* delt(bst* root, lli key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = delt(root->left, key);
    else if (key > root->key)
        root->right = delt(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            //free(root);
            return temp;
        }
        temp = min(root->right);
        root->key = temp->key;
        root->right = delt(root->right, temp->key);
    }
    return root;
}

void main()
{
   lli k,i=0;
    
   char opt[100];
   for(;i<1;)
   {
    scanf("%s",opt);
    
    if(strcmp(opt,"insr")==0)
    {
        scanf("%lli",&k);
        root=insert(root,k);
    }
    if(strcmp(opt,"srch")==0)
    {
        scanf("%lli",&k);
        temp=search(root,k);
        temp=NULL;
    }
    if(strcmp(opt,"inor")==0)
    {
        inorder(root);
        printf("\n");
    }
    if(strcmp(opt,"prer")==0)
    {
        preorder(root);
        printf("\n");
    }
    if(strcmp(opt,"post")==0)
    {
        postorder(root);
        printf("\n");
    }
    if(strcmp(opt,"stop")==0)
    {
        break;
    }
    if(strcmp(opt,"minm")==0)
    {
           temp=min(root);
           if(temp==NULL)
            printf("NIL\n");
           else
           printf("%lli\n",temp->key);
    }
    if(strcmp(opt,"maxm")==0)
    {
           temp=max(root);
           if(temp==NULL)
            printf("NIL\n");
           else
           printf("%lli\n",temp->key);
    }
    if(strcmp(opt,"pred")==0)
    {
      
        scanf("%lli",&k);
        pred(root,k);
    }
    if(strcmp(opt,"succ")==0)
    {
      
        scanf("%lli",&k);
        succ(root,k);
    }
    if(strcmp(opt,"delt")==0)
    {
        scanf("%lli",&k);
        root=delt(root,k);
    }
   
   }
    
}
