#include <bits/stdc++.h>

using namespace std;


//O(n) - time
//O(n) - space
int longestBand(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;
    //Data inside the set
    for(int num : arr){
        s.insert(num);
    }

    //Iterate over the arr
    int largestLen = 1;
    for(auto element : s){
        int parent = element - 1;
        if(s.find(parent) == s.end()){
            //Find the entire band / chain starting from element
            int nextNum = element + 1;
            int cnt = 1;

            while(s.find(nextNum) != s.end()){
                nextNum++;
                cnt++;
            }

            largestLen = max(largestLen, cnt);
        }
    }
    return largestLen;
}

int main() {

    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6}; //8 - {0,1,2,3,4,5,6,7}

    cout << longestBand(arr) << endl;

    return 0;
}