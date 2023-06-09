#include "binaryTree.h"

using namespace std;

/*Note: This is a preorder build
Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
Tree will look like:
          1
         / \
        2   3
       / \ / \
      4  5 6  7
*/
node *buildTree(istringstream *iss = NULL){
    int data;
    if(iss == NULL)
        cin >> data;
    else
        *iss >> data;

    if(data == -1){
        return NULL;
    }
    
    node *root = new node(data);
    root->left = buildTree(iss);
    root->right = buildTree(iss);
    
    return root;
}
