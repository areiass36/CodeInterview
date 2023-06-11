#include <bits/stdc++.h>
#include "../binaryTree.h"


int _replaceDescedantSum(node *root){
    if (root == NULL) return 0;
    
    int leftVal = _replaceDescedantSum(root->left);
    int rightVal = _replaceDescedantSum(root->right);
    int currVal = root->data;

    int descedantSum = leftVal + rightVal;
    
    if (descedantSum) root->data = descedantSum;
    
    return descedantSum ? root->data + currVal : currVal;
}

//Ryan's Solution
//Time - O(n)
void replaceDescedantSum1(node *root){
    _replaceDescedantSum(root);
    return;
}

//Course Solution
//Time - O(n)
int replaceDescedantSum(node *root){
    // base case
    if (root == NULL) return 0;
    // leaf node
    if (root->left == NULL and root->right == NULL) return root->data;

    int leftVal = replaceDescedantSum(root->left);
    int rightVal = replaceDescedantSum(root->right);
    int temp = root->data;

    root->data = leftVal + rightVal;

    return root->data + temp;
}

void levelOrderPrint(node *root);
int main() {
    string input = "1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);
    node *root = buildTree(&iss);
    levelOrderPrint(root);

    replaceDescedantSum(root);

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