#include <bits/stdc++.h>

using namespace std;

unordered_map<int,string> keypad = {
    {1,""},
    {2,"ABC"},
    {3,"DEF"},
    {4,"GHI"},
    {5,"JKL"},
    {6,"MNO"},
    {7,"PQRS"},
    {6,"TUV"},
    {6,"WXYZ"}
};

//O(4^n) - Time (Where "n" is the length of num input)
//O(4^n) - Space due recursive call stack
void generateCombination(string num, string comb, vector<string> &ans){
    if (num.length() == 0){
        ans.push_back(comb);
        return;
    }
    
    int currentDigit = num[0] - '0';

    for(char ch : keypad[currentDigit]){
        generateCombination(num.substr(1), comb + ch, ans);
        
        //it's not necessary the exclude case because the exercise only want the **combinations** and not subsets 
        //generateCombination(num.substr(1), comb, ans);
    }
}

int main() {
    vector<string> ans;
    generateCombination(to_string(23), "", ans);

    for(string comb : ans){
        cout << comb << ",";
    }
    cout << endl;

    return 0;
}