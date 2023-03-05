#include <bits/stdc++.h>

using namespace std;

//Aproach 1 without DP
//O(3^n) - Time
//O(3^n) - Space
int climbLadder(int n){
    if (n < 0){
        return 0;
    }
    if (n == 0){
        return 1;
    }

    int way1 = climbLadder(n-3);
    int way2 = climbLadder(n-2);
    int way3 = climbLadder(n-1);

    return way1 + way2 + way3;
}

int _climbLadderDP(int n, unordered_map<int,int> &cache){
    if (cache[n] != 0){
        return cache[n];
    }
    if (n < 0){
        return 0;
    }
    if (n == 0){
        return 1;
    }

    int way1 = _climbLadderDP(n-3, cache);
    int way2 = _climbLadderDP(n-2, cache);
    int way3 = _climbLadderDP(n-1, cache);

    int ans = way1+way2+way3;
    cache[n] = ans;

    return ans;
}

//Approach 2 with DP
//O(n) - Time
//O(n) - Space
int climbLadderDP(int n){
    unordered_map<int,int> cache(n);
    return _climbLadderDP(n, cache);
}

int main() {

    cout << climbLadderDP(35) << endl;

    return 0;
}