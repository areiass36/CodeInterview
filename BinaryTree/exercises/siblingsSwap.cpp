#include <bits/stdc++.h>
#include "../binaryTree.h"

//https://leetcode.com/problems/flip-equivalent-binary-trees/

//Ryan's Solution
bool equal(node *root1, node *root2) {
    if (root1 == NULL and root2 == NULL) return true;
    if (root1 == NULL or root2 == NULL) return false;
    
    bool left = equal(root1->left, root2->left);
    bool right = equal(root1->right, root2->right);
    //trying convert
    bool swap = equal(root1->left, root2->right) and equal(root1->right, root2->left);
    return root1->data == root2->data and ((left and right) or swap);
}

int main() {
    string input = "6 3 1 -1 -1 7 -1 -1 8 4 7 -1 -1 1 -1 -1 2 -1 3 -1 -1";
    string input2 = "6 8 2 3 -1 -1 -1 4 1 -1 -1 7 -1 -1 3 7 -1 -1 1 -1 -1";
    istringstream iss(input);

    node *tree = buildTree(&iss);
    iss.clear();
    istringstream iss2(input2);
    node *tree2 = buildTree(&iss2);

    cout << equal(tree, tree2) << endl;

    return 0;
}
