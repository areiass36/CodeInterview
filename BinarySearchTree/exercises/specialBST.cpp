#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

Node *findInOrderSuccessor(Node *inputNode) {
    if (inputNode->right != NULL) {
        Node *temp = inputNode->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }
    Node *parent = inputNode->parent;
    Node *temp = inputNode;
    while (parent != NULL and parent->right == temp) {
        temp = parent;
        parent = temp->parent;
    }
    return parent;
}