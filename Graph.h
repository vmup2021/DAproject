//
// Created by victo on 24/03/2023.
//

#ifndef DA__GRAPH_H
#define DA__GRAPH_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#include <climits>

#include "Station_Edge.h"

class Graph
{
private:
public:
    vector<Station> allStations;

    Graph();

    // Find functions
    Station *findStationByName(const string &stationName);

    // Read file functions
    void readStations(const string &lineName);
    void readEdges();

    void setAllStationsUnvisited();

    // Search Algorithms
    vector<Edge *> bfsFindPath(const string &source, const string &destination);
    static vector<Edge *> returningPath(Station *sink);

    // Max Flow
    int maxFlow(const string &source, const string &destination);

    // Max Flow of a given station considering the entire railway grid
    int entireMaxFlow(const string &sink);

    // Top pair of stations that require more trains
    void topK(int n);

    //(1) for the budget of Districts and (2) for budget for Municipalities
    void getBudget(int x);

    int shortestPathCost(const string &source, const string &destination);

    int getLines();

    // Max Flow Reduced Network
    int maxFlowReduced(const string &source, const string &destination, const string &station1, const string &station2);
};

#endif // DA__GRAPH_H
