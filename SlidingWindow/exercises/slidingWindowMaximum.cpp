#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/sliding-window-maximum/

//Further reading to get the data structure of the monotonic queue: shorturl.at/inN01 (Minimum Stack/Queue/Deque)

//Neetcode Solution - https://youtu.be/DfljaUwZsOk
//O(n) - time
//O(1) - space
vector<int> maxInWindow(vector<int> input,int k){
    deque<int> dq;

    int leftPtr = 0;
    int rightPtr = 0;

    vector<int> ans;
    while(rightPtr < input.size()){
        int rNum = input[rightPtr];
        
        while(!dq.empty() and dq.back() < rNum){
            dq.pop_back();
        }
        dq.push_back(rNum);
        
        int windowSize = rightPtr - leftPtr + 1;
        if(windowSize == k){
            ans.push_back(dq.front());
            if (!dq.empty() and dq.front() == input[leftPtr])
                dq.pop_front();
            leftPtr++;
        }
        rightPtr++;
    }
    return ans;
}

int main() {
    //vector<int> input = {8,7,6,9};
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    auto output = maxInWindow(input, 3);

    for(int num : output){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}