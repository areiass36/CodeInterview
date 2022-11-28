#include <bits/stdc++.h>

using namespace std;

// n2 - mine
vector<int> solve(vector<int>, int);
// n log n - mine
vector<int> solve2(vector<int>, int);

vector<int> solve(vector<int> array, int s){
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] + array[j] == s)
                return {array[i], array[j]};
        }
    }
    return {};
}

vector<int> solve2(vector<int> array, int s){
    set<int> lookupSet;
    for (int i = 0; i < array.size(); i++){
        int expected = s - array[i];
        set<int>::iterator containningElement = lookupSet.find(expected);
        if (*containningElement == expected && containningElement != lookupSet.end())
            return {array[i], *containningElement};
        lookupSet.insert(array[i]);
    }
    return {};
}

// Course implementation
vector<int> courseSolve3(vector<int> array, int s){
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++){
        int expected = s - array[i];
        if (binary_search(array.begin(), array.end(), expected))
            return {array[i], expected};
    }
    return {};
}

// O(n) - time
// O(n) - space
vector<int> pairSum(vector<int> arr, int Sum){
    unordered_set<int> s;
    vector<int> result;

    for(int i = 0; i < arr.size(); i++){
        int complement = Sum - arr[i];

        if(s.find(complement) != s.end()){
            result.push_back(complement);
            result.push_back(arr[i]);
            return result;
        }
        //insert the current num inside the set
        s.insert(arr[i]);
    }
    return {};
}

int main(){

    vector<int> arr{10,5,2,3,-6,9,11};
    int Sum = 4;

    vector<int> result = pairSum(arr, Sum);

    if(result.size() == 0){
        cout << "No such pair exists" << endl;
    } else{
        cout << result[0] << " " << result[1] << endl; //10 -6
    }
    
    return 0;
}