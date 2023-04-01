//
// Created by victo on 31/03/2023.
//
#include "Station_Edge.h"

Station::Station(string name, string district, string municipality, string township, string line) {
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
}

void Station::print() {
    cout << setw(20) << name << setw(20) << district << setw(20) << municipality << setw(20) << township << setw(20) << line << endl;
}

void Station::addEdge(Edge *e) {
    adj.push_back(e);
}

void Station::setVisited(bool visited) {
    this->visited = visited;
}

bool Station::getVisited() const {
    return this->visited;
}

void Station::setPrevEdge(Edge *e) {
    this->prevEdge = e;
}

Edge* Station::getPrevEdge() const {
    return prevEdge;
}

void Station::setPrevStation(Station *s) {
    this->prevStation = s;
}

Station* Station::getPrevStation() const {
    return prevStation;
}

string Station::getName() const{
    return name;
}

string Station::getDistrict() const {
    return district;
}

string Station::getMunicipality() const {
    return municipality;
}

void Station::setDist(int dist) { this->dist = dist; }
int Station::getDist() const { return dist; }


//Edge

Edge::Edge(Station *source, Station *destination, int capacity, string type) {
    this->source = source;
    this->destination = destination;
    this->capacity = capacity;
    this->type = type;
}

void Edge::print() {
    cout << setw(20) << source << setw(20) << destination << setw(20) << capacity << setw(20) << type << setw(20) << endl;
}

//Getters
Station* Edge::getSource() const { return this->source; }
Station* Edge::getDestination() const { return this->destination; }
int Edge::getCapacity() const { return this->capacity; }
string Edge::getType() const { return this->type; }

void Edge::setFlow(int flow) { this->flow = flow; }
int Edge::getFlow() const { return this->flow; }

void Edge::setReverseEdge(Edge *edge) { this->reverse_edge = edge;}
Edge* Edge::getReverseEdge() { return reverse_edge; }

