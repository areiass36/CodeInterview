#include <bits/stdc++.h>
#include "../prefixTrie.h"

using namespace std;

int main() {
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;
    for(auto w : words){
        t.insert(w);
    }

    int q; cin>>q;
    string searchWord;
    while(q--){
        cin>>searchWord;
        if(t.search(searchWord)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

}