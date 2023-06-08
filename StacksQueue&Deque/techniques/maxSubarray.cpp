#include <bits/stdc++.h>

using namespace std;

//This solution is ungly, the most important thing is to understand the data structure of the monotonic queue
//Time - O(n)
void maxSubArrayK(vector<int> arr, int k){
    deque<int> q(k);

    // Process only the first K elements
    int i;
    for(i = 0; i < k; i++){
        while(not q.empty() and arr[i] > arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    // Remaining the elements of the array
    for(; i < arr.size(); i++){
        cout << arr[q.front()] << " ";
        //remove element from the left (contraction when an index is outside the window)
        while(not q.empty() and q.front() <= i - k){
            q.pop_front();
        }
        while(not q.empty() and arr[i] >= arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    // Print the last element
    cout << arr[q.front()];
}

int main(){
    vector<int> arr{1,2,3,1,4,5,2,3,6};

    maxSubArrayK(arr, 3);

    return 0;
}