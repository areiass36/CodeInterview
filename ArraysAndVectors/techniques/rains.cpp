#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// O(n) - time
// O(n) - space
int trappedWater(vector<int> heights)
{
    int n = heights.size();
    if (n < 3)
        return 0;

    // Left max, Right Max
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }

    // calculate water
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - heights[i];
    }
    return water;
}

// Augusto's solution
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
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trappedWater(water) << endl; // 6

    return 0;
}