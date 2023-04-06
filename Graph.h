/**
 * @file Graph.cpp
 * @author G07_4
 * @brief This file handles the generation and utilization of a railway network graph
 * @version 0.1
 * @date 2023-04-06
 *
 * @copyright Copyright (c) 2023
 *
 */
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
    /// @brief Vector of station nodes
    vector<Station> allStations;

    /**
     * @brief Construct a new Graph:: Graph object
     *
     */
    Graph();

    /**
     * @brief This function returns the station node with the name "stationName"
     *
     * @param stationName Name of the station node
     * @return Station* Station Node with name = "stationName"
     */
    Station *findStationByName(const string &stationName);

    /**
     * @brief This functions handles the generation of the graph nodes from the file "../stations.csv"
     *
     * @param lineName This is a constraint where we decide if we want to generate the graph with the full railway network or just part of it
     */
    void readStations(const string &lineName);

    /**
     * @brief This functions handles the generation of the node's edges from the file "../network.csv"
     *
     */
    void readEdges();

    /**
     * @brief This is an auxiliary function that sets the attribute visited of every station in the graph as false
     *
     */
    void setAllStationsUnvisited();

    /**
     * @brief This function returns a vector of edges that connect two stations
     *
     * @param source Name of the source station
     * @param destination Name of the destination station
     * @return vector<Edge *> Path between source and destination
     */
    vector<Edge *> bfsFindPath(const string &source, const string &destination);
    static vector<Edge *> returningPath(Station *sink);

    /**
     * @brief This function calculates the maximum number of simultaneous trains (max flow) that can travel between two stations
     *
     * @param source Name of the source station
     * @param destination Name of the destination station
     * @return int Number that simbolizes the maximum number of simultaneous trains that can travel between the two stations
     */
    int maxFlow(const string &source, const string &destination);

    /**
     * @brief This functions sorts the pairs of stations by the amount of trains they require when taking full advantage of the network capacity and prints a n number of them
     *
     * @param n Number of pairs of stations to print
     */
    void topK(int n);

    /**
     * @brief This function calculates the right budget for the purchasing and maintenance of trains by districts/municipalities
     *
     * @param x 1 to calculate by district, 2 to calculate by municipalities
     */
    void getBudget(int x);

    /**
     * @brief This function calculates the maximum number of trains that can simoultaneously arrive at a given station taking into consideration the entire railway grid
     *
     * @param sink Name of the station
     * @return int Maximum number of trains that can arrive at a given station taking into consideration the entire railway grid
     */
    int entireMaxFlow(const string &sink);

    /**
     * @brief This function calculates the minimum cost path between two stations
     *
     * @param source Name of the source station
     * @param destination Name of the destination station
     * @return int Cost of the minimum cost path between the two stations
     */
    int shortestPathCost(const string &source, const string &destination);

    /**
     * @brief This function calculates the number of edges/lines that exist in the entire railway grid
     *
     * @return int Number of lines that exist in the entire railway grid
     */
    int getLines();

    /**
     * @brief This function calculates the maximum number of trains that can simultaneously travel between two specific stations in a network of reduced connectivity
     *
     * @param source Name of the source station
     * @param destination Name of the destination station
     * @param station1 Name of one station that has a unusable line
     * @param station2 Name of the other station thas has the unusable line
     * @return int Maximum number of trains that can simultaneously travel between two specific stations in a network of reduced connectivity
     */
    int maxFlowReduced(const string &source, const string &destination, const string &station1, const string &station2);
};

#endif // DA__GRAPH_H
