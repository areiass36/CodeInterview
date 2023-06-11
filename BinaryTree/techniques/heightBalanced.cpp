#include <bits/stdc++.h>
#include "../binaryTree.h"

using namespace std;

const int BALANCED_CONDITION = 1;

pair<int,bool> isHeightBalanced(node *root){
    pair<int,bool> node, left, right; // {height, isBalanced}

    if (root == NULL){
        node.first = 0;
        node.second = true;
        return node;
    }

    left = isHeightBalanced(root->left);
    right = isHeightBalanced(root->right);

    node.first = max(left.first, right.first) + 1;

    int diff = abs(left.first - right.first);
    node.second = diff <= BALANCED_CONDITION and left.second and right.second;

    return node;
}

int main() {
    string input = "1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);

    node *tree1 = buildTree(&iss);

    printTree(tree1);
    cout << (isHeightBalanced(tree1).second ? "Balanced" : "Not Balanced") << endl;

    input = "1 2 4 -1 -1 5 7 8 -1 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss2(input);
    node *tree2 = buildTree(&iss2);

    printTree(tree2);
    cout << (isHeightBalanced(tree2).second ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
