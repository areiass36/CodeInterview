#include <bits/stdc++.h>

using namespace std;

bool checkRedundant(string str){
    stack<char> s;

    for(char ch : str){
        if (ch != ')'){
            s.push(ch); //Push all characters except ')'
        }else{
            bool operatorFound = false;
            while(!s.empty() and s.top() != '('){
                char top = s.top();
                if (top == '+' or top == '-' or top == '*' or top == '/'){
                    operatorFound = true;
                }
                s.pop();
            }
            s.pop(); //Pop the '('

            if (not operatorFound){
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s = "((a+b+c)+(d*c))";

    if (checkRedundant(s)){ //This is redundant
        cout << "Contains Redundant Parenthesis" << endl;
    }else{
        cout << "Doesn't contain Redundant Parenthesis" << endl;
    }

    string s2 = "((a+b+c)+((d*c)))";

    if (checkRedundant(s2)){ //This is not redundant
        cout << "Contains Redundant Parenthesis" << endl;
    }else{
        cout << "Doesn't contain Redundant Parenthesis" << endl;
    }

    return 0;
}