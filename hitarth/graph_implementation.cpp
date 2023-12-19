#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct graph{
    int vertex;
    struct node** adjlist;
};

struct node* createNode(int data){

    struct node* ptr = new node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;   
}

struct graph* createGraph(int vertex){

    struct graph* ptr = new graph;
    ptr->vertex = vertex;
    ptr->adjlist = new node*[vertex];
    for(int i=0;i<vertex;i++)
    {
        ptr->adjlist[i] = NULL;
    }
    return ptr;
}

