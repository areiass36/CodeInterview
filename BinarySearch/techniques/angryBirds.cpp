#include <bits/stdc++.h>

using namespace std;

bool canPlaceBirds(int B, int N, vector<int> nests, int sep){
    int birds = 1;
    int location = nests[0];

    for(int i = 1; i <= N-1; i++){
        int currentLocation = nests[i];
        if (currentLocation - location >= sep){
            birds++;
            location = currentLocation;

            if (birds == B){
                return true;
            }
        }
    }
    return false;
}

//O(n log (xn - x0)) - Time
//O(1) - Space
int angryBirds(vector<int> nests, int bird){
    int N = nests.size();
    sort (nests.begin(), nests.end());

    //Binary Search
    int s = 0;
    int e = nests[N-1] - nests[0];
    
    int ans = -1;

    while(s <= e){
        int mid = (s+e)/2;

        bool canPlace = canPlaceBirds(bird, N, nests, mid);

        if(canPlace){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nestss = {1,2,4,8,9};
    int B = 3;
    
    cout << angryBirds(nestss,B) << endl;

    return 0;
}