#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string input){
    stack<char> s;
    for(char ch : input){
        switch(ch){
            case '(':
            case '[':
            case '{':
                s.push(ch);
                break;
            case ')':
                if(not s.empty() and s.top() == '(')
                    s.pop();
                else
                    return false;
                break;
            case ']':
                if(not s.empty() and s.top() == '[')
                    s.pop();
                else
                    return false;
                break;
            case '}':
                if(not s.empty() and s.top() == '{')
                    s.pop();
                else
                    return false;
                break;
            default:
                continue;
        }
    }

    if (s.empty())
        return true;
    return false;
}

int main() {
    string s = "((a+b+c)+[d])";

    if (isBalanced(s)){ //This is balanced
        cout << "Balanced!" << endl;
    }else{
        cout << "Not Balanced!" << endl;
    }

    string s2 = "((a+b+c)+[d]) }";

    if (isBalanced(s2)){ //This is not balanced
        cout << "Balanced!" << endl;
    }else{
        cout << "Not Balanced!" << endl;
    }

    return 0;
}