#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int result;

    for (int i = 1; i < arr.size() - 1; i++)
    {
        int curr = arr[i];

        int leftMax = 0;
        int l = i;
        while (l >= 0)
        {
            leftMax = max(leftMax, arr[l]);
            l--;
        }

        int rightMax = 0;
        int r = i;
        while (r < arr.size())
        {
            rightMax = max(rightMax, arr[r]);
            r++;
        }

        result += min(leftMax, rightMax) - arr[i];
    }
    return result;
}

int solution2(vector<int> arr)
{
    vector<int> left;
    vector<int> right;
    int result = 0;

    int currentLeftMax = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currentLeftMax = max(currentLeftMax, arr[i]);
        left.push_back(currentLeftMax);
    }

    int currentRightMax = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        currentRightMax = max(currentRightMax, arr[i]);
        right.insert(right.begin(), currentRightMax);
    }

    for (int i = 0; i < arr.size(); i++)
        result += min(left[i], right[i]) - arr[i];

    return result;
}

int main()
{
    int result = solution2({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    cout << result << endl;
    return 0;
}