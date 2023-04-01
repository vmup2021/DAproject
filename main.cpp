#include <iostream>

#include "Graph.h"

using namespace std;

int main() {

    Graph g;


    g.readStations("all");
    g.readEdges();


    cout << g.shortestPathCost("Lisboa Oriente", "Entroncamento");

//    g.topK(1);
//    cout << g.entireMaxFlow("Entroncamento");
//    g.getBudget(1);
//    cout << g.maxFlow("Lisboa Oriente", "Entroncamento");
//    cout << g.entireMaxFlow("Casa Branca");

}
