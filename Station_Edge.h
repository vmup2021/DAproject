/**
 * @file Station_Edge.h
 * @author G07_4
 * @brief This file handles the generation and utilization of stations and edges(lines)
 * @version 0.1
 * @date 2023-04-06
 *
 * @copyright Copyright (c) 2023
 *
 */
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
    /// @brief Name of the station.
    string name;

    /// @brief District of the station.
    string district;

    /// @brief Municipality of the station.
    string municipality;

    /// @brief Township of the station.
    string township;

    /// @brief Line of the station.
    string line;

    /// @brief Variable utilized in max flow calculations.
    Edge *prevEdge;

    /// @brief Variable utilized in max flow calculations.
    Station *prevStation;

    /// @brief Variable utilized in max flow calculations.
    bool visited;

    /// @brief Variable utilized in the shortestPah calculations.
    int dist;

public:
    /// @brief Vector of edges (lines).
    vector<Edge *> adj;

    /**
     * @brief Construct a new Station object.
     *
     * @param name Name of the station.
     * @param district District of the station.
     * @param municipality Municipality of the station.
     * @param township Township of the station.
     * @param line Line of the station.
     */
    Station(string name, string district, string municipality, string township, string line);

    /**
     * @brief Adds an edge (line) to a station.
     *
     * @param e Edge to be added.
     */
    void addEdge(Edge *e);

    /**
     * @brief Set the Visited object.
     *
     * @param visited
     */
    void setVisited(bool visited);

    /**
     * @brief Get the Visited object.
     *
     * @return true
     * @return false
     */
    bool getVisited() const;

    /**
     * @brief Set the Prev Edge object.
     *
     * @param e
     */
    void setPrevEdge(Edge *e);

    /**
     * @brief Get the Prev Edge object.
     *
     * @return Edge*
     */
    Edge *getPrevEdge() const;

    /**
     * @brief Set the Prev Station object.
     *
     * @param s
     */
    void setPrevStation(Station *s);

    /**
     * @brief Get the Prev Station object.
     *
     * @return Station*
     */
    Station *getPrevStation() const;

    /**
     * @brief Set the Dist object.
     *
     * @param dist
     */
    void setDist(int dist);

    /**
     * @brief Get the Dist object.
     *
     * @return int
     */
    int getDist() const;

    /**
     * @brief Get the Name object.
     *
     * @return string
     */
    string getName() const;

    /**
     * @brief Get the District object.
     *
     * @return string
     */
    string getDistrict() const;

    /**
     * @brief Get the Municipality object.
     *
     * @return string
     */
    string getMunicipality() const;
};

class Edge
{

private:
    /// @brief Station that is the source of the edge
    Station *source;

    /// @brief Station that is the destination of the edge
    Station *destination;

    /// @brief Capacity of the edge
    int capacity;

    /// @brief Type of edge (Standard or alpha pendular)
    string type;

    /// @brief Variable utilized in the max flow calculations
    int flow;

    /// @brief Variable utilized in the max flow calculations
    Edge *reverse_edge;

public:
    /**
     * @brief Construct a new Edge object
     *
     * @param source
     * @param destination
     * @param capacity
     * @param type
     */
    Edge(Station *source, Station *destination, int capacity, string type);

    /**
     * @brief Get the destination station
     *
     */
    Station *getDestination() const;

    /**
     * @brief Get the Capacity object
     *
     * @return int
     */
    int getCapacity() const;

    /**
     * @brief Get the Type object
     *
     * @return string
     */
    string getType() const;

    /**
     * @brief Set the Flow object
     *
     * @param flow
     */
    void setFlow(int flow);

    /**
     * @brief Get the Flow object
     *
     * @return int
     */
    int getFlow() const;

    /**
     * @brief Set the Reverse Edge object
     *
     * @param edge
     */
    void setReverseEdge(Edge *edge);

    /**
     * @brief Get the Reverse Edge object
     *
     * @return Edge*
     */
    Edge *getReverseEdge();
};

#endif // DA__STATION_EDGE_H
