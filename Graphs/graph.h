#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v;
    list<int> *l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        for(int i=0; i < v; i++){
            cout << i << "-->";
            for(auto node : l[i]){
                cout << node << ",";
            }
            cout <<endl;
        }
    }

    void bfs(int src){
        queue<int> q;

        vector<bool> visited(this->v, false);
        q.push(src);
        while (not q.empty()){
            int node = q.front();
            cout << node << " ";
            q.pop();
            for(auto nbr : l[node]){
                if(not visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

#endif /* GRAPH_H */