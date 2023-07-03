#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *constructMinimumHeightBST(vector<int> arr, int start, int end);
node *insert(node *root, int data);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
bool search(node *root, int data);
int heightTree(node *root);
void printTree(node *root);


#endif /* BST_H */