#include <bits/stdc++.h>

using namespace std;

//Parcial Solution - Ryan
//O(n) - time
//O(n) - space
string space20(string str){
    int n = str.size();
    string newString;
    for(int i = 0; i < n; i++){
        if (str[i] == ' '){
            newString.push_back('%');
            newString.push_back('2');
            newString.push_back('0');
        }else {
            newString.push_back(str[i]);
        }
    }

    return newString;
}

//Great Solution - In Place Solution
//O(n) - time
//O(1) - space
void replace_string(char *str){
    //1. calc spaces
    int spaces = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            spaces++;
        }
    }

    int idx = strlen(str) + 2*spaces;
    str[idx] = '\0';

    for(int i = strlen(str) - 1; i >= 0; i--){
        if (str[i] == ' '){
            str[idx-3] = '%';
            str[idx-2] = '2';
            str[idx-1] = '0';
            idx -= 3;
        } else {
            str[idx-1] = str[i];
            idx--;
        }
    }
}

int main() {
    //cout << space20("hello world, how are you?") << endl; // Ryan

    char input[10000];
    cin.getline(input, 1000); //this cause it's a char array

    /* If input was a string
    string input;
    getline(cin,input);
    */

    replace_string(input);

    cout << input << endl;

    return 0;
}