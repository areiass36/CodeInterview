#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


node *lca(node *root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }

    if (root->key == a or root->key == b) {
        return root;
    }

    // search in left and right subtrees
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if (leftans != NULL and rightans != NULL) {
        return root;
    }

    if (leftans != NULL) {
        return leftans;
    }
    return rightans;
}

int findDistance(node *root, int target,int dist = 0){
    if (root == NULL){
        return -1;
    }
    if (root->key == target){
        return dist;
    }
    int left = findDistance(root->left,target,dist+1);
    if (left != -1){
        return left;
    }
    return findDistance(root->right,target,dist+1);
}

//here nodes a and b are the inputs
int shortestDist(node *root,int a,int b){
    node *commonParent = lca(root,a,b);

    int leftDist = findDistance(commonParent,a);
    int rightDist = findDistance(commonParent,b);

    return leftDist + rightDist;
}