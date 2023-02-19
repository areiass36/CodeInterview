#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> x, pair<string,int> y){
    return x.second <= y.second;
}

//O(n log n) - Time
//O(1) - Space
int badness(vector<pair<string,int> > teams){
    sort(teams.begin(),teams.end(), compare);
    int badness = 0;
    for(int i = 0; i < teams.size(); i++){
        badness += abs(teams[i].second - (i + 1));
    }

    return badness;
}



int main() {

    vector<pair<string,int>> arr = {
        {"WinOrBooze",1},
        {"BallOfDuty",2},
        {"WhoKnows",2},
        {"BholeChature",1},
        {"DCECoders",5},
        {"StrangeCase",7},  
        {"WhoKnows",7},
    };

    cout << badness(arr) << endl;

    return 0;
}