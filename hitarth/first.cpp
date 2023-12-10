#include<iostream>
using namespace std;

class BinaryTree {
int *arr;
int capacity;
  int lastUsedIndex;
    public:
    BinaryTree(int size) {
        arr = new int[size+1];
        capacity = size;
 lastUsedIndex = 0;
                                            } 
                                            void insert(int data) {
 if(lastUsedIndex == capacity) {
                                                 cout << "Array is full. Can't insert more elements\n";
                                     return;
                                                                                        }
                                         arr[++lastUsedIndex] = data;
                                                                                                    }

                                                                          void printTree() {
                                                                             for(int i=1; i<=lastUsedIndex; i++) {
                                                                                    cout << arr[i] << " ";
                                                                                                                                    }
                                                                                                                                            cout << "\n";
                                                                                                                                                }
                                                                                                };
                        int main() {
                                                                                                                                                 BinaryTree bt(10);
                                                                                 for(int i=1; i<=10; i++) {
                                                                                                bt.insert(i*10);
                                                                                                                                                                    }
                                                                                                                      bt.printTree();
                                                                          return 0;
                                                                                                                                                                            } 