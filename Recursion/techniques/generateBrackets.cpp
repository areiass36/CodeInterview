#include <bits/stdc++.h>

using namespace std;

void generateBrackets(int n, string brackets, vector<string> &ans, int open, int close){
    //Base Case
    if (brackets.length() == (n*2)){
        if (open == close)
            ans.push_back(brackets);
        return;
    }

    if (open < n){
        generateBrackets(n, brackets + "(", ans, open + 1, close);
    }
    if (close < n and open > close){
        generateBrackets(n, brackets + ")", ans, open, close + 1);
    }
}

int main() {

    vector<string> ans;

    generateBrackets(3, "", ans, 0, 0);

    for (string bracket : ans){
        cout << bracket << endl;
    }

    return 0;
}