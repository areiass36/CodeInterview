#include <bits/stdc++.h>
#include "../binaryTree.h"

//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

//-------------------Ryan's Solution---------------------

vector<int> ans;

void getNodesAtLevelK(node *root, int k){
    if (root == NULL) return;
    if (k == 0){
        ans.push_back(root->data);
        return;
    }
    getNodesAtLevelK(root->left, k-1);
    getNodesAtLevelK(root->right, k-1);
    return;
}

int _nodesAtDistanceK(node *root, node *target, int k){
    if (root == NULL){
        return -1;
    }

    if (root->data == target->data){
        // get nodes down below
        getNodesAtLevelK(root, k);
        return 0; // return 0 to indicate that the target was found
    }

    int targetOnLeft = _nodesAtDistanceK(root->left, target, k);
    if(targetOnLeft != -1){
        // If the target was found on the left subtree, get nodes on the right subtree
        if (targetOnLeft + 1 == k) // if the first ancestor is at distance k
            ans.push_back(root->data);
        else
            getNodesAtLevelK(root->right, k-2-targetOnLeft); // - 2 
        return 1 + targetOnLeft; // return 1 to indicate that the target was found
    }
    int targetOnRight = _nodesAtDistanceK(root->right, target, k);
    if (targetOnRight != -1){
        // If the target was found on the right subtree, get nodes on the left subtree
        if (targetOnRight + 1 == k) // if the first ancestor is at distance k
            ans.push_back(root->data);
        else
            getNodesAtLevelK(root->left, k-2-targetOnRight);
        return 1 + targetOnRight; // return 1 to indicate that the target was found
    }
    return -1; // return -1 to indicate that the target was not found
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
    
    cout << "\n\n\n";

    //Ryan's Solution - doesn't work
    auto ans = nodesAtDistanceK1(tree, target, 2);

    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
