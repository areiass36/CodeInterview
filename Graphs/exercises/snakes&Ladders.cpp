#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<int> graph[MAXN];
vector<bool> visited(MAXN,false);
vector<int> dist(MAXN,0);

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n+1,0);
    //place the ladders
    for(auto [head,tail] : snakes){
        board[head] = tail - head;
    }
    for(auto [start,end] : ladders){
        board[start] = end - start;
    }
    //place the snakes
    for(int u = 1; u < n; u++){
        for(int dice = 1; dice <= 6; dice++){
            int v = u + dice;
            v += board[v];
            if (v <= n){
                graph[u].push_back(v);
            }
        }
    }
    
    //BFS to get dist 
    queue<int> q;
    dist[1] = 0;
    visited[1] = true;
    q.push(1);
    while(not q.empty()){
        int node = q.front();
        q.pop();
        for(int v : graph[node]){
            if (not visited[v]){
                q.push(v);
                dist[v] = dist[node] + 1;
                visited[v] = true;
            }
        }
    }
    return dist[n];
}

int main(){
    vector<pair<int,int>> snakes = {
        {17,4},
        {31,30},
        {34,12}
    };
    vector<pair<int,int>> ladders = {
        {2,15},
        {5,7},
        {9,27},
        {18,29},
        {25,35}
    };
    cout << min_dice_throws(36,snakes,ladders) << endl;
}