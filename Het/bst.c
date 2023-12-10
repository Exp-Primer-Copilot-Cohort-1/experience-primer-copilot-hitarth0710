#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst * createnode(int data)
{
struct bst *newnode=(struct node*) malloc(sizeof(struct bst));
newnode ->data =data;
newnode ->left =NULL;
newnode ->right=NULL;
return newnode;
};

struct bst * insert(struct bst *root,int data)
{
    struct bst *node;
    if(node=NULL)
    {
        return createnode(data);
    }
    if(data< node -> data){
        node ->left =insert(node ->left,data);
    }
    else if (data> node->data){
        node->right=insert(node ->right,data);
    }
    return node;
};


int main()
{
    struct bst * createnode(int data);
    struct bst * insert(struct bst *root,int data);


    struct bst *root=NULL;
    root=insertnode(root,50);
    insert(root,30);
    insert(root,50);
    insert(root,70);
    insert(root,60);
    insert(root,20);
    return 0;
}
  
