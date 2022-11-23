#include <iostream>
#include <vector>
#include <set>

using namespace std;

//
// n2 - mine
vector<int> solve(vector<int>, int);
// n log n - mine
vector<int> solve2(vector<int>, int);

vector<int> solve(vector<int> array, int s)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] + array[j] == s)
                return {array[i], array[j]};
        }
    }
    return {};
}

vector<int> solve2(vector<int> array, int s)
{
    set<int> lookupSet;
    for (int i = 0; i < array.size(); i++)
    {
        int expected = s - array[i];
        set<int>::iterator containningElement = lookupSet.find(expected);
        if (*containningElement == expected && containningElement != lookupSet.end())
            return {array[i], *containningElement};
        lookupSet.insert(array[i]);
    }
    return {};
}

// Course implementation
vector<int> courseSolve3(vector<int> array, int s)
{
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++)
    {
        int expected = s - array[i];
        if (binary_search(array.begin(), array.end(), expected))
            return {array[i], expected};
    }
    return {};
}

int main()
{
    cout << "Hello world 2" << endl;
    return 0;
}