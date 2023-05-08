#include <bits/stdc++.h>

//This actually is a DP problem, further reading: https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
//Greed solution aparently is not the best solution if we don't start pick the coins

using namespace std;

int _MaxValue(int n, vector<int> &v, int i, int j){
    if (i > j or i >= n or j < 0)
        return 0;

    int option1 = v[i] + min(_MaxValue(n,v,i+2,j), _MaxValue(n,v,i+1,j-1));
    int option2 = v[j] + min(_MaxValue(n,v,i+1,j-1), _MaxValue(n,v,i,j-2));

    return max(option1, option2);
}

int MaxValue(int n, vector<int> v){
    return _MaxValue(n, v, 0, v.size()-1);
}

int main() {
    vector<int> arr = {1,2,3,4};
    cout << MaxValue(4,arr) << endl;
    return 0;
}