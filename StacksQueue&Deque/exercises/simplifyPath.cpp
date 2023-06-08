#include <bits/stdc++.h>

//https://leetcode.com/problems/simplify-path/

using namespace std;

//Ryan's Solution
//Time - O(n)
string simplifyPath1(string path){
    deque<string> dirs;
    string ans = "";

    stringstream ss(path);
    string dir;
    while(getline(ss, dir, '/')){
        if (dir == "" or dir == ".") 
            continue;
        else if (dir == ".." and not dirs.empty()) 
            dirs.pop_back();
        else 
            dirs.push_back(dir);
    }

    while(not dirs.empty()){
        ans += "/" + dirs.front();
        dirs.pop_front();
    }

    return ans == "" ? "/" : ans;
}

//Course Solution - this doesn't make sense to me
string simplifyPath(string path){
    istringstream iss(path);
    vector<string> tokens;

    string token;
    while(getline(iss, token, '/')){
        if (token == "." or token == "")
            continue;
        tokens.push_back(token);
    }

    vector<string> stack;

    if (path[0] == '/'){
        stack.push_back("");
    }

    for(string token : tokens){
        if (token == ".."){
            // 2 cases -> Abs path or relative path
            if (stack.size() == 0 or stack[stack.size()-1] == ".."){
                stack.push_back("..");
            }else if(stack[stack.size()-1] != ""){
                stack.pop_back();
            }
        }else{
            //x,y,z...
            stack.push_back(token);
        }
    }

    //single element
    if (stack.size()==1 and stack[0] == ""){
        return "/";
    }

    //combine all elements in stack to get the answer
    ostringstream oss;
    int i = 0;
    for(auto token : stack){
        if(i != 0){
            oss << "/";
        }
        oss << token << "/";
    }

    return oss.str();
}

int main(){
    cout << simplifyPath("/home/") << endl; // /home
    cout << simplifyPath("/../") << endl; // /
    cout << simplifyPath("/home//foo/") << endl; // /home/foo
    cout << simplifyPath("/a/./b/../../c/") << endl; // /c
    cout << simplifyPath("/a//b////c/d//././/..") << endl; // /a/b/c
    return 0;
}