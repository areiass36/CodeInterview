#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution3(vector<int> arr)
{
    unordered_set<int> set(make_move_iterator(arr.begin()), make_move_iterator(arr.end()));
    int result = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int expected = arr[i] - 1;
        bool hasExpected = set.find(expected) != set.end();
        if (hasExpected)
            continue;

        int nextElement = arr[i] + 1;
        int summation = 1;
        while (set.find(nextElement++) != set.end())
            summation++;
        result = max(result, summation);
    }

    return result;
}

// Big O (N)
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

// Big O (N log N)
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

int main()
{
    int result = solution3({1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6});
    cout << result << endl;
    return 0;
}