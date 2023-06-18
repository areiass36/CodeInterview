#include <bits/stdc++.h>
#include "../binaryTree.h"

map<int, vector<int>> m;

void verticalOrderPrint(node *root, int dist = 0){
    if (root == NULL) return;
    m[dist].push_back(root->data);
    verticalOrderPrint(root->left,dist-1);
    verticalOrderPrint(root->right,dist+1);
}

int main() {
    string input = "1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1";
    istringstream iss(input);

    node *tree = buildTree(&iss);
    verticalOrderPrint(tree);
    int lvl = 1;
    for(auto [key, vec] : m){
        cout << "lv " << lvl++ << ": ";
        for(int num : vec){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
