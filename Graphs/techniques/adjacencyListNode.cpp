#include "../graphNode.h"

int main(){
    vector<string> cities = {"São Paulo", "São Carlos", "Salvador", "Rio de Janeiro"};
    Graph g(cities);

    g.addEdge("São Paulo", "São Carlos");
    g.addEdge("São Carlos", "Salvador");
    g.addEdge("São Carlos", "Rio de Janeiro");
    g.addEdge("Salvador", "Rio de Janeiro");
    g.addEdge("Rio de Janeiro", "São Paulo");

    g.printAdjList();

}