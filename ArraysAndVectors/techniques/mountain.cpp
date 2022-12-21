#include <iostream>
#include <vector>

using namespace std;

// O(n) - time
// O(1) - space
// Course solution
int highest_mountain(vector<int> arr)
{
    int n = arr.size();

    int largest = 0;

    int i = 1;
    while (i <= n - 2)
    {
        // check arr[i] is peak or not
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            // arr[i] is peak
            // expand to left and right
            int cnt = 1;
            int j = i;
            // expand to left
            while (j >= 1 && arr[j] > arr[j - 1])
            {
                j--;
                cnt++;
            }
            // expand to right
            while (i <= n - 2 && arr[i] > arr[i + 1])
            {
                i++;
                cnt++;
            }
            largest = max(largest, cnt);
        }
        else
        {
            i++;
        }
    }
    return largest;
}

// Augusto's solution
int solution(vector<int> arr)
{
    if (arr.size() < 3)
        return 0;
    int result = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        bool isPeek = arr[i] > arr[i + 1] && arr[i] > arr[i - 1];
        if (!isPeek)
            continue;
        // Considere the three values in the peek
        int possibleResult = 3;
        int j = i - 1;
        while (j > 0 && arr[j] > arr[--j])
            possibleResult++;

        int k = i + 1;
        while (k < arr.size() - 1 && arr[k] > arr[++k])
            possibleResult++;

        result = max(possibleResult, result);
        i = k - 1;
    }
    return result;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << solution(arr) << endl; // 9
    return 0;
}