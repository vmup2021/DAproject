//
// Created by victo on 31/03/2023.
//

#ifndef DA__STATION_EDGE_H
#define DA__STATION_EDGE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Edge;

class Station
{
private:
    string name;
    string district;
    string municipality;
    string township;
    string line;

    // Variables utilized in max flow calculations
    Edge *prevEdge;
    Station *prevStation;
    bool visited;

    // Variables used in the shortestPah calculations
    int dist;

public:
    // Easier to access the edges
    vector<Edge *> adj;

    Station(string name, string district, string municipality, string township, string line);

    void addEdge(Edge *e);

    // Setters and Getters
    void setVisited(bool visited);
    bool getVisited() const;

    void setPrevEdge(Edge *e);
    Edge *getPrevEdge() const;

    void setPrevStation(Station *s);
    Station *getPrevStation() const;

    void setDist(int dist);
    int getDist() const;

    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
};

class Edge
{

private:
    Station *source;
    Station *destination;
    int capacity;
    string type;

    // Variables utilized in the max flow calculations
    int flow;
    Edge *reverse_edge;

public:
    Edge(Station *source, Station *destination, int capacity, string type);

    // Getters and Setters
    Station *getSource() const;
    Station *getDestination() const;
    int getCapacity() const;
    string getType() const;

    void setFlow(int flow);
    int getFlow() const;

    void setReverseEdge(Edge *edge);
    Edge *getReverseEdge();
};

#endif // DA__STATION_EDGE_H
