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

    void _dfs(int node, vector<bool>& visited){
        visited[node] = true;
        cout << node << " ";
        for(int nbr : l[node]){
            if(not visited[nbr]){
                _dfs(nbr, visited);
            }
        }
        return;
    }

    void dfs(int src){
        vector<bool> visited(this->v,false);
        _dfs(src, visited);
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

    void shortestPathBFS(int src){
        queue<int> q;

        vector<bool> visited(this->v, false);
        vector<int> parent(this->v, -1);
        vector<int> dist(this->v, 0);

        q.push(src);
        visited[src] = true;
        parent[src] = src;
        dist[src] = 0;
        while (not q.empty()){
            int node = q.front();
            cout << node << " ";
            q.pop();
            for(auto nbr : l[node]){
                if(not visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = node;
                    dist[nbr] = dist[node] + 1;
                    visited[nbr] = true;
                }
            }
        }
        cout << endl;
        // print the shortest distance
        for(int i=0; i < v; i++){
            cout << "Shortest distance to " << i << " is " << dist[i] << endl;
        }

        // print the path
        for(int i=0; i < v; i++){
            cout << "Shortest path to " << i << " is " << dist[i] << " and path is " << endl;
            int temp = i;
            while (temp != src){
                cout << temp << "<--";
                temp = parent[temp];
            }
            cout << src << endl;
        }
    }
};

#endif /* GRAPH_H */