#include <bits/stdc++.h>
#include "../binaryTree.h"

//Ryan's Solution
//Time - O(n) where n is the number of nodes in the tree
void levelOrderPrint1(node *root){
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

//Course Solution
void levelOrderPrint(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(not q.empty()){
        node *temp = q.front();
        if (temp == NULL){
            cout << endl;
            q.pop();
            if (not q.empty()) q.push(NULL);
        }
        else{
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return;
}


int main() {
    string input = "1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);

    node *root = buildTree(&iss);

    levelOrderPrint(root);

    return 0;
}