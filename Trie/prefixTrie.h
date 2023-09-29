#ifndef PREFIXTRIE_H
#define PREFIXTRIE_H
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node(char data) {
        this->data = data;
        isTerminal = false;
    }
};

class Trie  {
public:
    Node *root;

    Trie() {
        root = new Node('\0');
    }

    void insert(string word){
        Node *temp = root;
        for(char ch : word){
            if (temp->m.count(ch) == 0){
                Node *newNode = new Node(ch);
                temp->m[ch] = newNode;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word){
        Node *temp = root;
        for(char ch : word){
            if (temp->m.count(ch) == 0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};


#endif /* PREFIXTRIE_H */