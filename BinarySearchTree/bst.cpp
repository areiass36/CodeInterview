#include "bst.h"

using namespace std;

node *insert(node *root, int data){
    if(root == NULL) root = new node(data);
    else if(data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

node* constructMinimumHeightBST(vector<int> arr, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);

    root->left = constructMinimumHeightBST(arr, start, mid - 1);
    root->right = constructMinimumHeightBST(arr, mid + 1, end);

    return root;
}

void preorder(node *root){
    if(root == NULL) return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL) return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root){
    if(root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool search(node *root, int data){
    if(root == NULL) return false;
    if(root->data == data) return true;
    if(data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

int heightTree(node *root){
    if(root == NULL) return 0;
    
    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

void printTree(node *root){
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}