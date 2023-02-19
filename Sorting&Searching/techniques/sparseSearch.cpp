#include <bits/stdc++.h>

using namespace std;

//Ryan's Solution
//O(log n) - Time
//O(1) - Space
int sparseSearch1(vector<string> arr, string str){
    int start = 0;
    int end = arr.size() - 1;
    int middle = (start+end) / 2;

    while(start <= end){
        if (arr[middle] == str){
            return middle; 
        } else if (arr[middle] == ""){
            //do a linear search to both sides
            int i = middle - 1;
            int j = middle + 1;
            while (i >= start and j <= end){
                if (arr[i] != ""){
                    middle = i;
                    break;
                }
                if (arr[j] != ""){
                    middle = j;
                    break;
                }
                i--;
                j++;
            }
        } else {
            if (arr[middle] > str){
                end = middle - 1;
            }else{
                start = middle + 1;
            }
            middle = (start+end) / 2;
        }
    }
    return -1;
}

//CourseSolution
//O(log n) - Time
//O(1) - Space
int sparseSearch(vector<string> arr, string key){
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e){
        int mid = (s+e)/2;

        int midLeft = mid - 1;
        int midRight = mid + 1;
        
        if (arr[mid] == ""){
            while(1){
                if (midLeft < s and midRight > e){
                    return - 1;
                } else if (midRight <= e and arr[midRight] != ""){
                    mid = midRight;
                    break;
                } else if (midLeft >= s and arr[midLeft] != ""){
                    mid = midLeft;
                    break;
                }
                midLeft--;
                midRight++;
            }

        } if (arr[mid] == key){
            return mid;
        }else if (arr[mid] > key){
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {

    vector<string> arr = {"ai","","","bat","","","car","cat","","","dog",""};
    string wantToFind = "bat";

    cout << sparseSearch(arr,wantToFind) << endl; 

    return 0;
}