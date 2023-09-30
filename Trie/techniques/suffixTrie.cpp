#include <bits/stdc++.h>
#include "../suffixTrie.h"

using namespace std;

int main() {
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};
    SuffixTrie t;

    t.insert(input);

    for(auto word : suffixes) {
        if (t.search(word)) {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    

}