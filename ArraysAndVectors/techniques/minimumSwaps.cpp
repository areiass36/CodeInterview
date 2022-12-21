#include <bits/stdc++.h>

using namespace std;

//O(n log n) - time
//O(n) - space
int countMinSwaps(vector<int> arr){
    //Know the actual positions of elemetns (sorting)
    //store the current indices
    int n = arr.size();
    pair<int, int> ap[n];
    for(int i = 0; i < n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    sort(ap,ap+n);

    int ans = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        //if element is visited or element is in right position, then skip
        int oldPosition = ap[i].second;
        if (visited[i] == true or oldPosition == i){
            continue;
        }

        int node = i;
        int cycle = 0;

        while(not visited[node]) {
            visited[node] = true;
            int nextNode = ap[node].second;
            node = nextNode;
            cycle++;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main() {
    vector<int> arr{5,4,3,2,1};
    cout << countMinSwaps(arr) << endl;

    return 0;
}