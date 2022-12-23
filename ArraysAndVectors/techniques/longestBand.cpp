#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// O(n) - time
// O(n) - space
int longestBand(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;
    // Data inside the set
    for (int num : arr)
    {
        s.insert(num);
    }

    // Iterate over the arr
    int largestLen = 1;
    for (auto element : s)
    {
        int parent = element - 1;
        if (s.find(parent) == s.end())
        {
            // Find the entire band / chain starting from element
            int nextNum = element + 1;
            int cnt = 1;

            while (s.find(nextNum) != s.end())
            {
                nextNum++;
                cnt++;
            }

            largestLen = max(largestLen, cnt);
        }
    }
    return largestLen;
}

// O(N log N)
int solution(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int result = 0;
    int summation = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        bool isConsecutive = arr[i] == (arr[i - 1] + 1);
        if (isConsecutive)
            summation++;
        else
        {
            result = max(summation, result);
            summation = 1;
        }
    }

    return result;
}

// Big O (N) Augusto's solution
int solution2(vector<int> arr)
{
    unordered_set<int> set(make_move_iterator(arr.begin()), make_move_iterator(arr.end()));
    vector<int> bands;
    int result = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int expected = arr[i] - 1;
        bool isExpectedPresent = set.find(expected) != set.end();
        if (!isExpectedPresent)
            bands.push_back(arr[i]);
    }

    for (int i = 0; i < bands.size(); i++)
    {
        int element = bands[i] + 1;
        int summation = 1;
        while (set.find(element) != set.end())
        {
            summation++;
            element++;
        }
        result = max(result, summation);
    }
    return result;
}

int main()
{

    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6}; // 8 - {0,1,2,3,4,5,6,7}

    cout << longestBand(arr) << endl;

    return 0;
}