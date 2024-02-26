#include "../graph.h"

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(0,5);
    g.addEdge(1,2);
    g.addEdge(2,3);
    cout << g.hasCycle(1) << endl;
}