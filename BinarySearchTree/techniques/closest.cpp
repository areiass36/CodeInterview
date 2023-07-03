#include <bits/stdc++.h>
#include "../bst.h"

//Recursive
//Time - O(log n)
//Space - O(log n)
int closestBST(node *root, int target, int closestVal, int minDiff) {
    if (root == NULL) return closestVal;
    int diff = abs(target - root->data);
    if (diff < minDiff) {
        minDiff = diff;
        closestVal = root->data;
    }
    if (target < root->data){
        closestVal = closestBST(root->left, target, closestVal, minDiff);
    } else {
        closestVal = closestBST(root->right, target, closestVal, minDiff);
    }

    return closestVal;
}

//Course solution
//Iterative
//Time - O(log n)
int findClosestInBST(node *root, int target){
    int closest = root->data;
    int minDiff = INT_MAX;

    node *temp = root;

    while(temp != NULL){
        int diff = abs(target - temp->data);
        if (diff == 0) return temp->data;
        if (diff < minDiff){
            minDiff = diff;
            closest = temp->data;
        }
        if (target < temp->data){
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return closest;
}

int main() {
    vector<int> arr = {1,3,4,6,7,8,10,13,14};

    node* root = constructMinimumHeightBST(arr, 0, arr.size() - 1);

    printTree(root);

    cout << closestBST(root, 16, INT_MAX, INT_MAX) << endl;

    cout << findClosestInBST(root, 16) << endl;
}