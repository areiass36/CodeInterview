#include <bits/stdc++.h>

using namespace std;

bool isPossibleDivide(vector<int> books, int minStudents, int minPages){
    int studentRequired = 1;
    int currStudent = 0;

    for (int pages : books){
        if (pages > minPages)
            return false;

        if (currStudent + pages > minPages){
            studentRequired++;
            currStudent = pages;

            if (studentRequired > minStudents){
                return false;
            }
        } else {
            currStudent += pages;
        }
    }
    return true;
}

int minPages(vector<int> books, int students){
    if (books.size() < students){
        return false;
    }

    int pageSum = 0;
    int pageMax = INT_MIN;
    for(int pages : books){
        pageSum += pages;
        pageMax = max(pages, pageMax);
    }

    int ans = 0;

    int start = pageMax;
    int end = pageSum;
    while (start <= end){
        int minPagesValue = (start+end)/2;
        
        if (isPossibleDivide(books, students, minPagesValue)) {
            ans = minPagesValue;
            end = minPagesValue - 1;
        }else {
            start = minPagesValue + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10,20,30,15};
    int students = 2;

    cout << minPages(arr,students) << endl;

    return 0;
}