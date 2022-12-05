/*
Busy Life
You are actually very busy person. You have a long list of activities. Your aim is to finish much as activities as possible.
In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.

Either you can:
- watch movie, play DotA and sleep peacefully (or)
- date with crush, play DotA and sleep peacefully
*/

//https://www.spoj.com/problems/BUSYMAN/

#include <iostream>
#include <vector>

vector<pair<int,int>> readInput(int numberActivities){
  vector<pair<int,int>> activities(numberActivities);

  for(int i = 0; i < numberActivities; i++){
    int start, end;
    cin >> start >> end;
    activities.push_back({start,end});
  }
  
  return activities;
}

void solve() {
  int numberActivities;
  cin >> numberActivities;
  vector<pair<int,int>> activities = readInput(numberActivities);

  activities.sort(activities.begin(), activities.end());

  
}


int main(){

  int t; cin >> t;
  while(t--){
    solve();
  }
  
  return 0;
}