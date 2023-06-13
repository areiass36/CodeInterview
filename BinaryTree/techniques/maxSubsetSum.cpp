#include <bits/stdc++.h>
#include "../binaryTree.h"

//Ryan's solution - Maybe not correct
//Time - O(n)
int maxSubsetSum1(node *root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL and root->right == NULL){
        return root->data;
    }

    //include root
    int inc = root->data;
    if (root->left != NULL){
        inc += maxSubsetSum1(root->left->left);
        inc += maxSubsetSum1(root->left->right);
    }
    if (root->right != NULL){
        inc += maxSubsetSum1(root->right->left);
        inc += maxSubsetSum1(root->right->right);
    }

    //exclude root
    int exc = maxSubsetSum1(root->left) + maxSubsetSum1(root->right);

    return max(inc, exc);
}

//Course's solution
//Time - O(n)
pair<int,int> maxSubsetSum(node *root){
    pair<int,int> node, left, right; // {include, exclude}

    if (root == NULL){
        node.first = node.second = 0;
        return node;
    }

    left = maxSubsetSum(root->left);
    right = maxSubsetSum(root->right);

    //include root
    node.first = root->data + left.second + right.second;

    //exclude root
    node.second = max(left.first, left.second) + max(right.first, right.second);

    return node;
}

int main() {
    string input = "1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);

    node *tree = buildTree(&iss);

    cout << maxSubsetSum1(tree) << endl;

    auto [inc, exc] = maxSubsetSum(tree);
    cout << max(inc, exc) << endl;



    return 0;
}
