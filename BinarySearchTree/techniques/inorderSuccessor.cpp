#include <bits/stdc++.h>
#include "../bst.h"

// Time - O(log n)
// Space - O(log n)
// Ryan's Solution
int inorderSuccessor(node *root, int target, int &successor) {
    if(root == NULL) {
        return successor;
    }

    if (root->data > target) 
        successor = root->data; 
    
    if (root->data == target) {
        if (root->right == NULL){
            return successor;
        }
        node *temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp->data;
    }else if (root->data > target) {
        return inorderSuccessor(root->left, target, successor);
    }else{
        return inorderSuccessor(root->right, target, successor);
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,10,13,14};

    node* root = constructMinimumHeightBST(arr, 0, arr.size() - 1);

    printTree(root);
    
    int max = -1;
    cout << inorderSuccessor(root, 7, max) << endl;
}