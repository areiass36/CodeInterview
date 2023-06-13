#include <bits/stdc++.h>
#include "../binaryTree.h"

//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

//-------------------Ryan's Solution---------------------

//ATENTION: DOESN'T WORK :(

vector<node*> ancestors;
vector<int> ans;

void getNodesDownBelow(node *root, int k, int currLevel = 0){
    if (root == NULL) return;
    if (currLevel == k){
        ans.push_back(root->data);
        return;
    }
    getNodesDownBelow(root->left, k, currLevel+1);
    getNodesDownBelow(root->right, k, currLevel+1);
}

void getNodesUpBelow(node *root, int k, int d){
    if (root == NULL) return;
    if (d == k){
        ans.push_back(root->data);
        return;
    }
    getNodesUpBelow(root->left, k, d+1);
    getNodesUpBelow(root->right, k, d+1);
}

void _nodesAtDistanceK(node *root, node *target, int k){
    ancestors.push_back(root);
    if (root == NULL){
        return;
    }

    if (root->data == target->data){
        // get nodes down below
        getNodesDownBelow(root, k);
        int ancestorsDistance = 1;
        ancestors.pop_back(); //remove current target node as ancestors

        for(int i = ancestors.size() - 1; i >= 0; i--){
            getNodesUpBelow(ancestors[i], k, ancestorsDistance);
            ancestorsDistance++;
        }
    }

    _nodesAtDistanceK(root->left, target, k);
    _nodesAtDistanceK(root->right, target, k);
    ancestors.pop_back();
}

vector<int> nodesAtDistanceK1(node *root, node *target, int k){
    _nodesAtDistanceK(root, target, k);

    return ans;
}

//----------------------Course Solution------------------------

void printAtLevelK(node *root, int k){
    if (root == NULL) return;
    if (k == 0){
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int printNodesAtDistanceK(node *root, node *target, int k){
    if (root == NULL )return -1;

    //Reach the target node
    if (root->data == target->data){ //Adapted with ->Data to test cases
        printAtLevelK(root, k);
        return 0;
    }

    int DL = printNodesAtDistanceK(root->left, target, k);
    if (DL != -1){
        //2 cases
        // Print the current node
        if (DL + 1 == k){
            cout << root->data << " ";
        }else{ //or print somenodes in the rightsubtree
            printAtLevelK(root->right, k-2-DL);
        }
        return 1+DL;
    }
    int DR = printNodesAtDistanceK(root->right, target, k);
    if (DR != -1){
        // 2 cases
        //print current node
        if (DR + 1 == k){
            cout << root->data << " ";
        }else{
            printAtLevelK(root->left, k-2-DR);
        }
        return 1+DR;
    }

    return -1;
}

int main() {
    string input = "3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1";
    istringstream iss(input);

    node *tree = buildTree(&iss);

    //printTree(tree);

    node *target = new node(5);

    //Course Solution
    printNodesAtDistanceK(tree, target, 2);
    
    //cout << "\n\n\n";

    //Ryan's Solution - doesn't work
    // auto ans = nodesAtDistanceK1(tree, target, 2);

    // for(int num : ans){
    //     cout << num << " ";
    // }
    // cout << endl;

    return 0;
}
