#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H
#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    string name;
    list<string> nbrs; //neightborhoods

    Node(string name){
        this->name = name;
    }
};

class Graph {
    unordered_map<string,Node*> m;
public:
    Graph(vector<string> vertexes){
        for(auto vertex : vertexes) {
            m[vertex] = new Node(vertex);
        }
    }

    void addEdge(string x, string y, bool undir=false){
        m[x]->nbrs.push_back(y);
        if (undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList() {
        for(auto [point, vertex] : m){
            cout << point << "-->";
            for(auto nbr : vertex->nbrs){
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }
};

#endif /* GRAPH_NODE_H */