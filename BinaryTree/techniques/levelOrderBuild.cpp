#include <bits/stdc++.h>
#include "../binaryTree.h"

node *levelOrderBuild(istringstream *iss = NULL){
    int rootNode;
    if (iss == NULL) cin >> rootNode;
    else *iss >> rootNode;

    node *root = new node(rootNode);

    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        node *current = q.front();
        q.pop();
        int left, right;
        if (iss != NULL) *iss >> left >> right;
        else cin >> left >> right;
        if (left != -1){
            current->left = new node(left);
            q.push(current->left);
        }
        if (right != -1){
            current->right = new node(right);
            q.push(current->right);
        }
    }

    return root;
}

void levelOrderPrint(node *root);
int main() {
    string input = "1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1";
    istringstream iss(input);
    node *root = levelOrderBuild(&iss);
    levelOrderPrint(root);

    return 0;
}

void levelOrderPrint(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(not q.empty()){
        while(q.front() != NULL){
            node *temp = q.front();
            cout << temp->data << " ";
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
            q.pop();
        }
        cout << endl;
        q.pop(); // remove the NULL
        if (not q.empty()) // if there are nodes to print
            q.push(NULL);
    }
    return;
}