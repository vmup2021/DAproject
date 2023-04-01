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
#include <limits.h>

#include "Station_Edge.h"

class Graph {
    private :

    public :
            vector<Station> allStations;

            Graph();

            //Find functions
            Station* findStationByName(string stationName);

            //Read file functions
            void readStations(string lineName);
            void readEdges();

            void printStations(); //Testing purposes
            void setAllStationsUnvisited();

            //Search Algorithms
            vector<Edge*> bfsFindPath(string source, string destination);
            vector<Edge*> returningPath(Station *sink) const;

            //Max Flow
            int maxFlow(string source, string destination);

            //Max Flow of a given station considering the entire railway grid
            int entireMaxFlow(string sink);

            //Top pair of stations that require more trains
            void topK(int n);

            //(1) for the budget of Districts and (2) for budget for Municipalities
            void getBudget(int x);

            int shortestPathCost(string source, string destination);
};

#endif //DA__GRAPH_H
