#include <bits/stdc++.h>
#include "../bst.h"

class linkedList {
public:
    int data;
    linkedList *next;

    linkedList(int data){
        this->data = data;
        next = NULL;
    }
};

void printList(linkedList *head) {
    while(head != NULL){
        cout<<head->data<< "-->";
        head = head->next;
    }
    cout<<endl;
}

struct nodeHeadTail {
    linkedList *head;
    linkedList *tail;
};

nodeHeadTail _treeToLinkedList(node *root) {
    nodeHeadTail headTail;
    if(root == NULL) {
        headTail.head = NULL;
        headTail.tail = NULL;
        return headTail;
    }

    nodeHeadTail leftLL = _treeToLinkedList(root->left);
    nodeHeadTail rightLL = _treeToLinkedList(root->right);

    linkedList *newNode = new linkedList(root->data);

    //Current node is inserted between left and right linked list
    if(leftLL.tail != NULL) {
        leftLL.tail->next = newNode;
    }
    newNode->next = rightLL.head;

    //If left linked list is empty, then head is current node
    if(leftLL.head != NULL) {
        headTail.head = leftLL.head;
    } else {
        headTail.head = newNode;
    }

    //If right linked list is empty, then tail is current node
    if(rightLL.tail != NULL) {
        headTail.tail = rightLL.tail;
    } else {
        headTail.tail = newNode;
    }

    return headTail;
}

// Ryan's Solution
// Time - O(n)
// Space - O(n)
linkedList *treeToLinkedList(node *root) {
    return _treeToLinkedList(root).head;
}

//Course Solution - Doesn't Work
// class LinkedList {
// public:
//     node *head;
//     node *tail;
// };

// LinkedList tree2LL(node *root){
//     LinkedList l;
    
//     //base case
//     if (root == NULL){
//         l.head = l.tail = NULL;
//         return l;
//     }

//     // 4 cases
//     if (root->left == NULL and root->right == NULL){
//         l.head = l.tail = root;
//         return l;
//     }else if (root->left != NULL and root->right == NULL){
//         LinkedList leftLL = tree2LL(root->left);
//         leftLL.tail->next = root;

//         l.head = leftLL.head;
//         l.tail = root;
//     }else if (root->left == NULL and root->right != NULL){
//         LinkedList rightLL = tree2LL(root->right);
//         root->next = rightLL.head;

//         l.tail = rightLL.tail;
//         l.head = root;
//     }else {
//         LinkedList leftLL = tree2LL(root->left);
//         LinkedList rightLL = tree2LL(root->right);

//         leftLL.tail->next = root;
//         root->next = rightLL.head;

//         l.head = leftLL.head;
//         l.tail = rightLL.tail;
//     }

//     return l; 
// }

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,10,13,14};

    node* root = constructMinimumHeightBST(arr, 0, arr.size() - 1);

    printTree(root);

    linkedList* flatTree = treeToLinkedList(root);

    printList(flatTree);

    // LinkedList flatTree2 = tree2LL(root).head;

    // printList(flatTree2);
}