#include <bits/stdc++.h>
#include "../binaryTree.h"

using namespace std;

//Time - O(n)
int heigth(node *root) {
    if (root == NULL) return 0;
    int leftHeight = heigth(root->left);
    int rightHeight = heigth(root->right);
    return max(leftHeight, rightHeight) + 1;
}

//Time - O(n^2) 
int diameter(node *root){
    if (root == NULL)
        return 0;
    
    int D1 = heigth(root->left) + heigth(root->right); //O(n)
    int D2 = diameter(root->left); // To every node will recall the diameter O(n) and to every node will call the heigth O(n)
    int D3 = diameter(root->right); // So the complexity is O(n^2)

    return max({D1, D2, D3}); 
}

int main() {
    string input = "1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1";
    istringstream iss(input);

    node *root = buildTree(&iss);

    cout << diameter(root) << endl;

    return 0;
}
