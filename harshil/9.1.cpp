#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node* getnode(strucut node *n,int data,int a)
{
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    return n;
}















int main()
{
    struct node n;
    int x,i;
    printf("Enter the nodes you want to enter: \n");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        printf("Enter the node: ");
        scanf("%d",&data);
        getnode(n,data,i);
    }

}