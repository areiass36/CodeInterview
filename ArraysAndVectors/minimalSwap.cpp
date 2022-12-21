#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool isMissplaced(vector<int> &arr, unordered_map<int, int> &map, int i)
{
    return i != map[arr[i]];
}

int solution(vector<int> arr)
{
    unordered_map<int, int> map;
    int result = 0;
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < sorted.size(); i++)
        map.insert({sorted[i], i});

    for (int i = 0; i < arr.size(); i++)
    {
        int cur = arr[i];
        while (isMissplaced(arr, map, i))
        {
            swap(arr, i, map[cur]);
            cur = arr[i];
            result++;
        }
    }

    return result;
}

int main()
{
    //{10, 11, 5, 4, 3, 2, 1}
    cout << solution({2, 4, 5, 1, 3}) << endl;
    return 0;
}