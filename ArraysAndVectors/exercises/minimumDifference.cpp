#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// O(m log m + n log n)
pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int minSum = INT_MAX;
    pair<int, int> minPair;

    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size() && minSum > 0)
    {
        int dif = abs(a[i] - b[j]);

        if (dif < minSum)
        {
            minSum = dif;
            minPair = {a[i], b[j]};
        }
        else if (dif > minSum)
            return minPair;

        if (a[i] > b[j])
            j++;
        else
            i++;
    }

    return minPair;
}

int main()
{
    auto sla = minDifference({23, 5, 10, 17, 30}, {26, 134, 135, 14, 19});
    cout << sla.first << ',' << sla.second << endl;
    return 0;
}