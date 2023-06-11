#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <queue>
#include <sstream>

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

node *buildTree(istringstream *iss);
int heightTree(node *root);
void printTree(node *root);


#endif /* BINARYTREE_H */