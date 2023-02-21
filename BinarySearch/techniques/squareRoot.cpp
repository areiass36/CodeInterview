#include <bits/stdc++.h>

using namespace std;

//O(log n + 9P) - Time
//O(1) - Space
float squareRoot(int n, int p){
    int start = 0;
    int end = n;
    float ans = 0;
    
    //Binary Search to get integer part
    while (start <= end){
        int mid = (start+end)/2;

        if (mid*mid == n){
            return mid;
        }else if (mid*mid < n){
            ans = mid;
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    //Linear Search to get floating part
    float floatPart = 0.1;
    for(int i = 0; i < p; i++){
        while(ans*ans <= n){
            ans += floatPart;
        }
        ans -= floatPart;
        floatPart /= 10;
    }
    return ans;
}

int main() {

    int n,p;

    cin >> n >> p;

    cout << squareRoot(n,p) << endl;

    return 0;
}