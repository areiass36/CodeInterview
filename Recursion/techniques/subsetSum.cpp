#include <bits/stdc++.h>

using namespace std;


//Ryan Solution
//O(2^n) - Time
//O(2^n) - Space due the recursive call
bool subsetSum(vector<int> &arr, int index, int sum){
    if (index == arr.size()){
        return sum == 0; //corner case, when the last element is the answer to complet the sum 
    }
    if (sum == 0){
        return true;
    }
    if (sum < 0){
        return false;
    }

    int currNum = arr[index];
    
    //Include Num
    bool isSubsetSum1 = subsetSum(arr,index+1,sum-currNum);    

    //here could be verified if isSubsetSum is true

    //Exclude Num
    bool isSubsetSum2 = subsetSum(arr,index+1,sum);

    return isSubsetSum1 or isSubsetSum2;

    //Best way to return the same thing above
    //return subsetSum(arr,index+1,sum-currNum) or subsetSum(arr,index+1,sum);
}

//Course Solution
//O(2^n) - Time
//O(2^n) - Space
int countSubsetsSum(vector<int> arr, int idx, int sum){
    //base case
    if (idx == arr.size()){
        return sum == 0;
    }

    //recursive case
    int inc = countSubsetsSum(arr,idx+1, sum - arr[idx]);
    int exc = countSubsetsSum(arr,idx+1, sum);

    return inc + exc;

    
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};

    cout << subsetSum(arr, 0, 36) << endl;

    cout << countSubsetsSum(arr,0,9) << endl;
    return 0;
}