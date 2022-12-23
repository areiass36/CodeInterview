/*
Busy Life
You are actually very busy person. You have a long list of activities. Your aim is to finish much as activities as possible.
In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.

Either you can:
- watch movie, play DotA and sleep peacefully (or)
- date with crush, play DotA and sleep peacefully
*/

// https://www.spoj.com/problems/BUSYMAN/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<pair<int, int>> readInput(int numberActivities) {
    vector<pair<int, int>> activities;

    for (int i = 0; i < numberActivities; i++) {
        int start, end;
        cin >> start >> end;
        activities.push_back({start, end});
    }

    return activities;
}

void solve() {
    int numberActivities;
    cin >> numberActivities;
    vector<pair<int, int>> input = readInput(numberActivities);
    sort(input.begin(), input.end());

    unordered_map<int, int> map;

    for (auto pair : input) {
        map[pair.first] = pair.second;
    }

    int lastStartingHour = input[input.size() - 1].first;
    int ans = 1;
    for (int i = 0; i < input.size(); i++) {
        pair<int, int> current = input[i];
        int nextStartTime = current.second;

        int actitviesNumber = 1;
        while (nextStartTime <= lastStartingHour) {
            int nextFinishTime = map[nextStartTime];
            bool hasNextAct = nextFinishTime != 0;

            if (hasNextAct) {
                actitviesNumber++;
                nextStartTime = nextFinishTime;
            } else
                nextStartTime++;
        }
        ans = max(ans, actitviesNumber);
    }

    cout << ans << endl;
}

int countActivitesRev(vector<pair<int, int>> input);

int main() {

    /* int t; cin >> t;
    while(t--){
      solve();
    } */

    // to test udemy input
    //(7,9) (0,10) (4,5) (8,9) (4,10) (5,7)
    vector<pair<int, int>> arr{
        make_pair(7, 9),
        make_pair(0, 10),
        make_pair(4, 5),
        make_pair(8, 9),
        make_pair(4, 10),
        make_pair(5, 7)};
    cout << countActivites(arr) << endl;

    return 0;
}

// Udemy Revision
int countActivitesRev(vector<pair<int, int>> input) {
    sort(input.begin(), input.end());
    int n = input.size();

    unordered_map<int, int> map;

    for (auto pair : input) {
        map[pair.first] = pair.second;
    }

    int ans = 0;
    int lastActivity = input[n - 1].first;
    for (auto activity : input) {
        int cnt = 1;
        int nextActivity = activity.second;
        while (nextActivity <= lastActivity) {
            bool hasActivity = map[nextActivity] != 0;
            if (hasActivity) {
                cnt++;
                nextActivity = map[nextActivity];
            } else {
                nextActivity++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}

// Udemy
int countActivites(vector<pair<int, int>> input) {

    sort(input.begin(), input.end());

    unordered_map<int, int> map;

    for (auto pair : input) {
        map[pair.first] = pair.second;
    }

    int lastStartingHour = input[input.size() - 1].first;
    int ans = 1;
    for (int i = 0; i < input.size(); i++) {
        pair<int, int> current = input[i];
        int nextStartTime = current.second;
        int actitviesNumber = 1;
        while (nextStartTime <= lastStartingHour) {
            int nextFinishTime = map[nextStartTime];
            bool hasNextAct = nextFinishTime != 0;

            if (hasNextAct) {
                actitviesNumber++;
                nextStartTime = nextFinishTime;
            } else
                nextStartTime++;
        }
        ans = max(ans, actitviesNumber);
    }

    return ans;
}