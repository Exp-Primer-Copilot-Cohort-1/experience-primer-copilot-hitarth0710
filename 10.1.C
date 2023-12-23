#include <stdio.h>
#include <stdlib.h>

struct Tree{
    struct Tree* left;
    int data;
    struct Tree* right;
};

struct Tree* constructTree(int arr[], int index, int n) {
    if(index >= n)
        return NULL;
    struct Tree* newNode = (struct Tree*) malloc(sizeof(struct Tree));
    newNode->data = arr[index];
    newNode->left = constructTree(arr, 2*index+1, n);
    newNode->right = constructTree(arr, 2*index+2, n);
    return newNode;
}

void inorder(struct Tree* root) {
    if (root == NULL)
      return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    struct Tree* root = constructTree(arr, 0, 7);

    printf("Inorder Traversal: ");
    inorder(root); printf("\n");
}