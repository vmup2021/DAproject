#include "Station_Edge.h"

#include <utility>

Station::Station(string name, string district, string municipality, string township, string line)
{
    this->name = std::move(name);
    this->district = std::move(district);
    this->municipality = std::move(municipality);
    this->township = std::move(township);
    this->line = std::move(line);
}

void Station::addEdge(Edge *e)
{
    adj.push_back(e);
}

void Station::setVisited(bool visited)
{
    this->visited = visited;
}

bool Station::getVisited() const
{
    return this->visited;
}

void Station::setPrevEdge(Edge *e)
{
    this->prevEdge = e;
}

Edge *Station::getPrevEdge() const
{
    return prevEdge;
}

void Station::setPrevStation(Station *s)
{
    this->prevStation = s;
}

Station *Station::getPrevStation() const
{
    return prevStation;
}

string Station::getName() const
{
    return name;
}

string Station::getDistrict() const
{
    return district;
}

string Station::getMunicipality() const
{
    return municipality;
}

void Station::setDist(int distance)
{
    this->dist = distance;
}

int Station::getDist() const
{
    return dist;
}

Edge *Station::getEdge(const string& destination) const {
    for(auto e : this->adj){
        if(e->getDestination()->getName() == destination)
            return e;
    }
    return nullptr;
}

// Edge

Edge::Edge(Station *source, Station *destination, int capacity, string type)
{
    this->source = source;
    this->destination = destination;
    this->capacity = capacity;
    this->type = std::move(type);
}

// Getters
Station *Edge::getSource() const { return this->source; }
Station *Edge::getDestination() const { return this->destination; }
int Edge::getCapacity() const { return this->capacity; }
string Edge::getType() const { return this->type; }

void Edge::setFlow(int flow) { this->flow = flow; }
int Edge::getFlow() const { return this->flow; }

void Edge::setReverseEdge(Edge *edge) { this->reverse_edge = edge; }
Edge *Edge::getReverseEdge() { return reverse_edge; }
