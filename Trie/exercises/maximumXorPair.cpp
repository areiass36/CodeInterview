#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};

class XorTrie {
public:
    Node *root;
    XorTrie(){
        root = new Node();
    }
    void insert(int num){
        Node *temp = root;
        for(int i = 31; i >= 0; i--){
            int value = (num >> i) & 1;
            if (value == 0){
                if (temp->left == NULL){
                    temp->left = new Node();
                }
                temp = temp->left;
            }else {
                if (temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }
    int _getMaxXor(int num){
        int currMaxXor = 0;
        Node *temp = root;
        for(int i = 31; i >= 0; i--){
            int value = (num >> i) & 1;
            if (value == 0){
                if (temp->right != NULL){
                    temp = temp->right;
                    currMaxXor += (1 << i);
                }else{
                    temp = temp->left;
                }
            }else {
                if (temp->left != NULL){
                    temp = temp->left;
                    currMaxXor += (1 << i);
                }else{
                    temp = temp->right;
                }
            }
        }
        return currMaxXor;
    }
    int getMaxXor(vector<int> input){
        int maxXor = 0;
        for(int i = 0; i < input.size(); i++){
            insert(input[i]);
            maxXor = max(maxXor,_getMaxXor(input[i]));
        }
        return maxXor;
    }
};


int max_xor_pair(vector<int> arr){
    //implement the max xor pair function 
    XorTrie t;
    return t.getMaxXor(arr);
}


