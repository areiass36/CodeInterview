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

// O(n log n + m log m) - time
// O(1) - space
pair<int,int> minDifference2(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int aSize = a.size();
    int bSize = b.size();
    
    int pointerA = 0;
    int pointerB = 0;
    int minDiff = abs(a[0] - b[0]);
    pair<int,int> ans(a[0],b[0]);
    while(pointerA != (aSize-1) and pointerB != (bSize-1)){
        int numA = a[pointerA];
        int numB = b[pointerB];
        
        int diff = abs(numA - numB);
        
        if (diff == 0){
            return make_pair(numA,numB);
        }
        if(diff < minDiff){
            ans = make_pair(numA,numB);
            minDiff = diff;
        }
        
        if(pointerA < aSize and numA < numB){
            pointerA++;
        }else if (pointerB < bSize and numA > numB){
            pointerB++;
        }
    }
    return ans;
    
}



int main()
{
    auto sla = minDifference({23, 5, 10, 17, 30}, {26, 134, 135, 14, 19});
    cout << sla.first << ',' << sla.second << endl;
    return 0;
}