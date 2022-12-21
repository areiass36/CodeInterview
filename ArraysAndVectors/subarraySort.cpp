#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int firstValue = INT_MIN;
    int firstIndex = -1;
    int lastIndex = -1;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        // Fix bug for first ocurrance
        bool isBiggerThanNext = arr[i] > arr[i + 1];
        bool isSmallerThanPrevious = arr[i] < arr[i - 1];
        bool isSmallerThanFirstValue = arr[i] < firstValue;
        if (firstValue == INT_MIN && isBiggerThanNext)
        {
            firstValue = arr[i];
            firstIndex = i;
        }
        else if (isSmallerThanPrevious || isSmallerThanFirstValue)
            lastIndex = i;
    }

    return {firstIndex, lastIndex};
}

int main()
{
    //{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11}
    //{2, 3, 9, 5, 7, 10, 11, 14, 12, 15, 16, 17}
    auto resp = solution({2, 3, 4, 9, 5, 7, 10, 11});

    for (auto a : resp)
    {
        cout << a << endl;
    }

    return 0;
}