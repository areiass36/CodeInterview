#include <vector>
#include <iostream>

using namespace std;

// O(n log n) - time
// O(1) - space
vector<vector<int>> triplets(vector<int> arr, int sum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;

    int n = arr.size();
    // Pick every a[i], pair sum for remaining array
    for (int i = 0; i <= n - 3; i++)
    {
        int start = i + 1;
        int end = n - 1;

        // Two pointer approach
        while (start < end)
        {
            int currentSum = arr[i] + arr[start] + arr[end];
            if (currentSum == sum)
            {
                result.push_back({arr[i], arr[start], arr[end]});
                start++;
                end--;
            }
            else if (currentSum > sum)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};

    int S = 18;

    auto result = triplets(arr, S);

    for (auto v : result)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}