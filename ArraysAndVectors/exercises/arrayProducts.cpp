#include <iostream>
#include <vector>

using namespace std;

// TODO - finish this exercise
vector<int> productArray(vector<int> arr)
{
    vector<int> output(arr.size(), 1);
    int prod = 1;
    for (auto e : arr)
        prod *= e;

    return output;
}

int main()
{
}