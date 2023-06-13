#include <bits/stdc++.h>
#include "../binaryTree.h"

void _printLevelK(node *root, int k, int currLevel){
    if (root == NULL) return;
    if (currLevel == k){
        cout << root->data << " ";
        return;
    }
    _printLevelK(root->left, k, currLevel+1);
    _printLevelK(root->right, k, currLevel+1);
}

void printLevelK(node *root, int k){
    _printLevelK(root, k, 0);
    cout << endl;
}

int main() {
    string input = "1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);

    node *tree = buildTree(&iss);

    printLevelK(tree, 2);

    return 0;
}
