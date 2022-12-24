#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/maximum-subarray/

int maxSum(int a, int b, int c);

bool isSameGroup(int groupSum, int cur);

/*
int maxSubarraySum(vector<int> arr)
{
    int sum = 0;

    vector<int> agr;
    int acc = 0;
    for (auto cur : arr)
    {
        bool isFirstGroup = acc == 0;
        bool isSameGroup = (acc > 0 && cur > 0) || (acc < 0 && cur < 0);
        if (!isFirstGroup && !isSameGroup)
        {
            agr.push_back(acc);
            acc = 0;
        }
        acc += cur;
    }

    for (int)
    {
    }

    return sum;
}*/

int maxSubarraySum(vector<int> arr)
{
    int a = 0;
    int b = 0;
    int c = 0;

    for (auto cur : arr)
    {
        if (a == 0 && cur < 0)
            continue;
        else if (a == 0 || (isSameGroup(a, cur) && b == 0))
            a += cur;
        else if (b == 0 || (isSameGroup(b, cur) && c == 0))
            b += cur;
        else if (c == 0 || isSameGroup(c, cur))
            c += cur;
        else
        {
            a = maxSum(a, b, c);
            b = cur;
            c = 0;
        }
    }

    return maxSum(a, b, c);
}

int maxSum(int a, int b, int c)
{
    int value = max(a + b + c, max(a, (max(b, c))));
    return value < 0 ? 0 : value;
}

bool isSameGroup(int groupSum, int cur)
{
    return (groupSum > 0 && cur > 0) || (groupSum < 0 && cur < 0);
}

int solution2(vector<int> arr)
{
    int currentSum = 0;
    int bestSum = 0;
    for (auto cur : arr)
    {
        currentSum = max(currentSum + cur, 0);
        bestSum = max(bestSum, currentSum);
    }
    return bestSum;
}

int main()
{
    cout << solution2({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
    return 0;
}