#include <bits/stdc++.h>

using namespace std;

//O(n!) - Time
//O(1) - Space (answer vector doesn't count)
void findPermutations(string str, int fixed, set<string> &ans){
    if (fixed == str.length()){
        ans.insert(str);
        return;
    }

    for(int i = fixed; i < str.length(); i++){
        //swap to get the permutation
        swap(str[fixed], str[i]);
        findPermutations(str,fixed+1,ans);
        //backtracking - if the string is passed by reference, this is needed
        //swap(str[fixed], str[i]);
    }
}

int main() {

    set<string> ans;

    findPermutations("aacd", 0, ans);
    
    vector<string> arr(ans.begin(), ans.end());

    for(string str : arr){
        cout << str << " ";
    }
    cout << endl;

    return 0;
}