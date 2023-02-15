#include <bits/stdc++.h>

using namespace std;

int _inversionCount(vector<int> &arr, int s, int e){
    int i = s;
    int m = (s+e)/2;
    int j = m+1;
    
    int inversions = 0;

    vector<int> temp;
    while(i <= m and j <= e){
        if (arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }else{
            inversions += (m - i + 1);
            temp.push_back(arr[j++]);
        }
    }

    while(i <= m){
        temp.push_back(arr[i++]);
    }

    while(j <= e){
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for(int idx = s; idx <= e; idx++){
        arr[idx] = temp[k++];
    }

    return inversions;
}

int inversionCount(vector<int> &arr, int s, int e){
    if (s >= e)
        return 0;
    
    int m = (s+e)/2;
    int C1 = inversionCount(arr,s,m);
    int C2 = inversionCount(arr,m+1,e);

    int CI = _inversionCount(arr,s,e);
    
    return C1 + C2 + CI;
}


int main() {
    vector<int> arr = {0,5,2,3,1};

    cout << inversionCount(arr,0,arr.size() - 1) << endl;

    return 0;
}