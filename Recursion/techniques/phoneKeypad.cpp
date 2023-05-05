#include <bits/stdc++.h>

using namespace std;

//Ryan Solution
unordered_map<int,string> keypad2 = {
    {0,""},
    {1,""},
    {2,"ABC"},
    {3,"DEF"},
    {4,"GHI"},
    {5,"JKL"},
    {6,"MNO"},
    {7,"PQRS"},
    {8,"TUV"},
    {9,"WXYZ"}
};

//O(4^n) - Time (Where "n" is the length of num input)
//O(4^n) - Space due recursive call stack
void generateCombination(string num, string comb, vector<string> &ans){
    if (num.length() == 0){
        ans.push_back(comb);
        return;
    }
    
    int currentDigit = num[0] - '0';

    //skip 0 and 1
    if (currentDigit == 0 or currentDigit == 1){
        generateCombination(num.substr(1), comb, ans);
    }

    for(char ch : keypad2[currentDigit]){
        generateCombination(num.substr(1), comb + ch, ans);
        
        //it's not necessary the exclude case because the exercise only want the **combinations** and not subsets 
        //generateCombination(num.substr(1), comb, ans);
    }
}

//Course Solution
string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input, string output, int i = 0){
    if (input[i] == '\0'){
        cout << output << ',';
        return;
    }

    //rec case
    // if the input is 0 or 1 them we skip it
    int currentDigit = input[i] - '0';
    if (currentDigit == 0 or currentDigit == 1){
        printKeypadOutput(input, output, i + 1);
    }

    //keypad
    for(int k = 0; k < keypad[currentDigit].size(); k++){
        printKeypadOutput(input, output + keypad[currentDigit][k], i + 1);
    }
}

int main() {
    vector<string> ans;
    generateCombination(to_string(351), "", ans);
    
    for(string comb : ans){
        cout << comb << ",";
    }
    cout << endl;

    printKeypadOutput("351", "");

    return 0;
}