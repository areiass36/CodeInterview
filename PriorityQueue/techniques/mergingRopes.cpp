#include<bits/stdc++.h>

using namespace std;

// Time - O(n log n)
// Space - O(n)
int mergingRopes(vector<int> ropes){
    priority_queue<int,vector<int>,greater<int>> pq(ropes.begin(),ropes.end());

    int cost = 0;
    while(pq.size() > 1){
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();
        int newRope = rope1+rope2;
        cost += newRope;
        pq.push(newRope);
    }

    return cost;
}

int main(){

    vector<int> ropes = {4,3,2,6};
    cout << mergingRopes(ropes) << endl;
}