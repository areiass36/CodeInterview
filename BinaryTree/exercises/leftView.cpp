#include <bits/stdc++.h>
#include "../binaryTree.h"

//Little different on Leetcode
//https://leetcode.com/problems/binary-tree-right-side-view/description/

//Ryan's Solution - based on level order print technique
vector<int> leftView1(node *root){
    vector<int> ans;
    ans.push_back(root->data);
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    bool endOfLevel = false;
    while(not q.empty()){
        node *temp = q.front();
        q.pop();
        if (temp == NULL){
            if (not q.empty()) q.push(NULL);
            endOfLevel = true;
        } else {
            if (endOfLevel){
                ans.push_back(temp->data); 
                endOfLevel = false;
            }
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ans;
}

//Course Solution
void _leftView(vector<int>& vec, node* root, int level, int &max) {
    if (root == NULL) return;

    if (level > max) {
        vec.push_back(root->data);
        max = level;
    }

    _leftView(vec, root->left, level + 1, max);
    _leftView(vec, root->right, level + 1, max);
}

vector<int> leftView(node *root){
    vector<int> ans;
    int max = INT_MIN;
    _leftView(ans,root,0,max);
    return ans;
}

int main() {
    string input = "1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1";
    string input2 = "1 2 -1 4 -1 5 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);

    node *tree = buildTree(&iss);
    iss.clear();
    iss.str(input2);
    node *tree2 = buildTree(&iss);
    
    auto vec = leftView(tree);
    for(int num : vec){
        cout << num << " ";
    }
    cout << endl;

    auto vec2 = leftView(tree2);
    for(int num : vec2){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
