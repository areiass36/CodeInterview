#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/find-median-from-data-stream/

class MedianHandler {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>> rightMinHeap;
    double median;
    MedianHandler() {
        this->median = 0;
    }
    
    void push(int num) {
        if (num > this->median) {
            if (rightMinHeap.size() > leftMaxHeap.size()) {
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();
                rightMinHeap.push(num);
            } else {
                rightMinHeap.push(num);
            }
        } else {
            if (leftMaxHeap.size() > rightMinHeap.size()) {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
                leftMaxHeap.push(num);
            } else {
                leftMaxHeap.push(num);
            }
        }

        if (leftMaxHeap.size() == rightMinHeap.size()) {
            this->median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        } else if (leftMaxHeap.size() > rightMinHeap.size()) {
            this->median = leftMaxHeap.top();
        } else {
            this->median = rightMinHeap.top();
        }
    }

    double getMedian(){
        return this->median;
    }
};
