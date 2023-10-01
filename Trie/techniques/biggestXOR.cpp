#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    Node *left;
    Node *right;
};

class BitwiseTrie {
    Node *root;
public:
    BitwiseTrie(){
        root = new Node();
    }

    void insert(int n){
        Node *temp = root;
        for(int i = 31; i >= 0; i--){
            int bit = (n>>i) & 1;
            if (bit == 0){
                if(temp->left == NULL){
                    temp->left = new Node();
                }
                temp = temp->left;
            }else{
                if(temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    int _getMaxXOR(int value){
        int currAns = 0;
        Node *temp = root;

        for(int i = 31; i >= 0; i--){
            int bit = (value>>i) & 1;
            if (bit == 0){
                if (temp->right != NULL){
                    temp = temp->right;
                    currAns += (1 << i);
                }else{
                    temp = temp->left;
                }
            } else {
                if (temp->left != NULL){
                    temp = temp->left;
                    currAns += (1 << i);
                }else{
                    temp = temp->right;
                }
            }
        }
        return currAns;
    }

    //Time - O(n)
    int getMaxXOR(vector<int> input){
        int maxXor = 0;
        for(int i = 0; i < input.size(); i++){
            int value = input[i];
            insert(value);
            int currXor = _getMaxXOR(value);
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};

int main(){
    vector<int> input = {3,10,5,25,9,2};
    BitwiseTrie t;
    cout << t.getMaxXOR(input) << endl;
}

