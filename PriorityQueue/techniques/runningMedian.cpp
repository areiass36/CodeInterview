#include <bits/stdc++.h>

using namespace std;

// Time - O(n log n)
// Space - O(n)
// Course Solution
void runningMedianCourse(vector<int> arr){
    priority_queue<int> leftHeap;
    priority_queue<int,vector<int>,greater<int>> rightHeap;

    leftHeap.push(arr[0]);

    float med = arr[0];
    cout << med << " ";
    for (int i = 1; i < arr.size(); i++){
        int num = arr[i];

        if (leftHeap.size() > rightHeap.size()){
            if (num < med){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }else {
                rightHeap.push(num);
            }
            med = (leftHeap.top() + rightHeap.top())/2.0;
        }else if (leftHeap.size() == rightHeap.size()){
            if (num < med){
                leftHeap.push(num);
                med = leftHeap.top();
            }else {
                rightHeap.push(num);
                med = rightHeap.top();
            }
        }else {
            if (num < med){
                leftHeap.push(num);
            }else {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }
            med = (leftHeap.top() + rightHeap.top())/2.0;
        }
        cout << med << " ";
    }
}

// Time - O(n log n)
// Space - O(n)
// Ryan's Solution
void runningMedian(vector<int> arr){
    float median = INT_MIN;

    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>> rightMinHeap;

    for(int num : arr){
        if (num > median){
            rightMinHeap.push(num);
        }else {
            leftMaxHeap.push(num);
        }

        if (leftMaxHeap.size() == rightMinHeap.size() + 2){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }else if (leftMaxHeap.size() + 2 == rightMinHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }

        if (rightMinHeap.size() == leftMaxHeap.size()){
            median = (rightMinHeap.top() + leftMaxHeap.top()) / 2.0;
        }else if (rightMinHeap.size() > leftMaxHeap.size()){
            median = rightMinHeap.top();
        }else{
            median = leftMaxHeap.top();
        }
        cout << median << " ";
    }

}

int main() {
    vector<int> arr = {10,5,2,3,0,12,18,20,22};

    runningMedian(arr);
    cout << endl;
    runningMedianCourse(arr);
    cout << endl;
}