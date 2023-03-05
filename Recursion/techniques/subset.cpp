#include <bits/stdc++.h>

using namespace std;

//Generating all subsets with strings
//O(2^n) - Time
//
void subsetWithString(string str, string ch, vector<string> &ans){
    if (str.length() == 0){
        ans.push_back(ch);
        return;
    }

    char currentChar = str[0];

    string currentString = ch;

    //Include
    subsetWithString(str.substr(1),currentString+currentChar,ans);

    //Exclude
    subsetWithString(str.substr(1),currentString,ans);
}

void subsetWithNumbers(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int index){
    if(index == nums.size()){
        ans.push_back(curr);
        return;
    }
    
    //Include
    curr.push_back(nums[index]);
    subsetWithNumbers(nums, curr, ans, index+1);
    
    //Exclude
    curr.pop_back();
    subsetWithNumbers(nums, curr, ans, index+1);
}

int main() {

    vector<string> ansString;

    subsetWithString("abc","",ansString);

    for(string str : ansString){
        cout << str << ",";
    }
    cout << endl;

    vector<int> nums = {1,2,3};
    vector<vector<int>> ansNumbers;
    vector<int> curr;

    subsetWithNumbers(nums, curr, ansNumbers, 0);

    for (auto vec : ansNumbers){
        cout << "[";
        for (int num : vec){
            cout << num << ",";
        }
        cout << "]-";
    }
    cout << endl;

    return 0;
}