#include<bits/stdc++.h>
#include "../prefixTrie.h"

using namespace std;

void _documentSearch(Trie t, string document, int i, unordered_map<string,bool> &m){
    Node *temp = t.root;
    for(int j = i; j < document.length(); j++){
        char ch = document[j];
        if (temp->m.count(ch) == 0){
            return;
        }
        temp = temp->m[ch];
        if (temp->isTerminal){
            string out = document.substr(i,j-i+1);
            m[out] = true;
        }
    }
    return;
}

// Time - O(n w + d w)
// Space - O(nw)
void documentSearch(string document, vector<string> words) {
    Trie t;
    for(auto w : words){
        t.insert(w);
    }

    unordered_map<string,bool> m;
    for(int i = 0; i < document.length(); i++){
        _documentSearch(t,document, i, m);
    }

    for(auto w : words){
        if (m[w]){
            cout << w << ": True" << endl;
        }else{
            cout << w << ": False" << endl;
        }
    }
}

int main(){
    string document = "litte cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cutest", "cat", "quick", "big"};

    documentSearch(document, words);

}