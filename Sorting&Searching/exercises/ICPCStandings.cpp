#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> x, pair<string,int> y){
    return x.second <= y.second;
}

//O(n log n) - Time
//O(1) - Space
int badness(vector<pair<string,int>> teams){
    sort(teams.begin(),teams.end(), compare);
    int badness = 0;
    for(int i = 0; i < teams.size(); i++){
        badness += abs(teams[i].second - (i + 1));
    }

    return badness;
}

//O(n) - Time
//O(1) - Space
int badness1(vector<pair<string,int>> teams){
    int bucket[teams.size()+1] = {0};
    for(auto pair : teams){
        bucket[pair.second]++;
    }

    int badness = 0;
    int position = 1;
    for(int i = 1; i <= teams.size(); i++){
        while(bucket[i]){
            badness += abs(position - i);
            bucket[i]--;
            position++;
        }
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

    cout << badness1(arr) << endl;

    return 0;
}