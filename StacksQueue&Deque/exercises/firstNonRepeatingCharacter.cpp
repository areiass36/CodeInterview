#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S){
    int map[27] = {0};
    queue<char> q;
    vector<char> ans;
    for(char ch : S){
        int letterPos = ch - 'a'; 
        map[letterPos] += 1;
        q.push(ch);
        while(not q.empty()){
            if (map[q.front() - 'a'] > 1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty()){
            ans.push_back('0');
        }
    }
    return ans;
}

int main(){
    auto ans = FindFirstNonRepeatingCharacter("aabcbcd");
    auto ans2 = FindFirstNonRepeatingCharacter("geeksforgeeksandgeeksquizfor");
    for(char ch : ans){
        cout << ch << " ";
    }
    cout << endl;
    for(char ch : ans2){
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}