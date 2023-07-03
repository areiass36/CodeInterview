#include <bits/stdc++.h>
#include "../bst.h"

//Time - O(n)
//Space - O(log n)
node* constructMinimumHeightBST(vector<int> arr, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);

    root->left = constructMinimumHeightBST(arr, start, mid - 1);
    root->right = constructMinimumHeightBST(arr, mid + 1, end);

    return root;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};

    node* root = constructMinimumHeightBST(arr, 0, arr.size() - 1);

    printTree(root);
}