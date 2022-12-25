#include <iostream>
#include <vector>

#define printArray(arr) for(int num : arr) cout << num << " ";

using namespace std;

//https://leetcode.com/problems/product-of-array-except-self/


// TODO - finish this exercise
vector<int> productArray(vector<int> arr)
{
    vector<int> output(arr.size(), 1);
    int prod = 1;
    for (auto e : arr)
        prod *= e;

    return output;
}

//Bad Solution - Using Divison
//O(n) - time
//O(1) - space (excluding output)
vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    
    vector<int> output(n,0);

    int product = 1;
    int hasZero = 0;
    for(int num : nums){
        if (num){
            product *= num;
        }else{
            hasZero++;
        }
    }

    for(int i = 0; i < n; i++){
        if (nums[i] == 0 and hasZero == 1){
            output[i] = product;
        } else if (hasZero){
            output[i] = 0;
        } else {
            output[i] = product / nums[i];
        }
    }

    return output;
}

//Parcial Solution - Without Division but on O(n) space 
//O(n) - time
//O(n) - space (excluding output)
//TODO - finish this exercise
vector<int> productArray1(vector<int> arr) {
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    vector<int> temp(n,1);
    
    int fullProduct = 1;
    for(int i = 0; i < n; i++){
        output[i] = fullProduct;
        fullProduct *= arr[i];
    }
    
    fullProduct = 1;
    for(int i = n-1; i >= 0; i--){
        temp[i] = fullProduct;
        fullProduct *= arr[i];
    }

    /* printArray(output);
    cout << endl;
    printArray(temp);
    cout << endl; */

    for(int i = 0; i < n; i++){
        output[i] *= temp[i];
    }

    return output;
}

//Best Solution
//O(n) - time
//O(1) - space (excluding output)
//TODO - finish this exercise
vector<int> productArray2(vector<int> arr) {
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    int fullProduct = 1;
    for(int i = 0; i < n; i++){
        output[i] = fullProduct;
        fullProduct *= arr[i];
    }
    
    fullProduct = 1;
    for(int i = n-1; i >= 0; i--){
        output[i] *= fullProduct;
        fullProduct *= arr[i];
    }

    /* printArray(output);
    cout << endl;
    */
    
    return output;
}

int main(){
    //Some Test Cases
    vector<int> arr1 = {1,2,3,4}; //[24,12,8,6]
    vector<int> arr2 = {1,2,3,4,5}; //[120,60,40,30,24]
    vector<int> arr3 = {-1,1,0,-3,3}; //[0,0,9,0,0]
    vector<int> arr4 = {0,0,0,0,0}; //[0,0,0,0,0]
    vector<int> arr5 = {1,0,3,0,0}; //[0,0,0,0,0]

    auto testCases = {arr1, arr2, arr3, arr4, arr5};

    // pointer to function
    vector<int> (*solve)(vector<int>);
    solve = &productArray1; // Change this to the function you want to test

    for(auto arr : testCases){
        auto output = (*solve)(arr);
        for(auto e : output)
            cout << e << " ";
        cout << endl;
    }
}