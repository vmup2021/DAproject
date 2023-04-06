#include "Graph.h"

Graph::Graph() = default;

Station *Graph::findStationByName(const string &stationName = "")
{
    for (auto it = allStations.begin(); it != allStations.end(); it++)
    {
        if (it->getName() == stationName)
        {
            return it.base();
        }
    }

    // Name does not exist
    return nullptr;
}

void Graph::readStations(const string &lineName)
{
    ifstream file("../stations.csv");
    string line;
    string field;
    string delimiter = ",";
    int count = 0;

    vector<string> array_of_fields;

    while (getline(file, line))
    {
        if (count++ == 0)
            continue;

        int pos;
        while ((pos = line.find(delimiter)) != string::npos)
        {
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if (line.find(delimiter) == string::npos)
                array_of_fields.push_back(line);
        }

        // The graph can be one specific line(ex:Linha do Norte) or simply all the stations
        if (lineName == "all" || lineName == array_of_fields[4])
        {
            auto *station_ = new Station(array_of_fields[0], array_of_fields[1], array_of_fields[2], array_of_fields[3], array_of_fields[4]);
            allStations.push_back(*station_);
        }

        array_of_fields.clear();
    }
}

void Graph::readEdges()
{
    ifstream file("../network.csv");
    string line;
    string field;
    string delimiter = ",";
    int count = 0;

    vector<string> array_of_fields;

    while (getline(file, line))
    {
        if (count++ == 0)
            continue;

        int pos;
        while ((pos = line.find(delimiter)) != string::npos)
        {
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if (line.find(delimiter) == string::npos)
                array_of_fields.push_back(line);
        }

        // The two stations of the edge
        Station *s1 = findStationByName(array_of_fields[0]);
        Station *s2 = findStationByName(array_of_fields[1]);

        // The forward and backward edges
        Edge *e = new Edge(s1, s2, stoi(array_of_fields[2]) / 2, string(array_of_fields[3]));
        Edge *rev_e = new Edge(s2, s1, stoi(array_of_fields[2]) / 2, string(array_of_fields[3]));

        // Add the edges
        s1->addEdge(e);
        s2->addEdge(rev_e);

        e->setReverseEdge(rev_e);
        rev_e->setReverseEdge(e);

        array_of_fields.clear();
    }
}

void Graph::setAllStationsUnvisited()
{
    for (Station &station : allStations)
    {
        station.setVisited(false);
        station.setPrevStation(nullptr);
        station.setPrevEdge(nullptr);
    }
}

vector<Edge *> Graph::bfsFindPath(const string &source, const string &destination)
{
    // Need to set all the Stations as unvisited in the beginning of each BFS
    setAllStationsUnvisited();
    queue<Station *> q;

    Station *s = findStationByName(source);
    Station *d = findStationByName(destination);

    if (s == nullptr || d == nullptr)
    {
        cout << "Source or Destination inserted incorrectly" << endl;
        return {};
    }

    q.push(s);
    s->setVisited(true);

    while (!q.empty())
    {
        Station *current_station = q.front();
        q.pop();

        // Check if the current station is the destination
        if (current_station == d)
        {
            return returningPath(d);
        }

        for (auto &e : current_station->adj)
        {
            Station *next_station = e->getDestination();

            if (!next_station->getVisited() && e->getCapacity() - e->getFlow() > 0)
            {
                q.push(next_station);
                next_station->setVisited(true);
                next_station->setPrevEdge(e);
                next_station->setPrevStation(current_station);
            }
        }
    }

    // return empty vector in case the destination was never found
    return {};
}

vector<Edge *> Graph::returningPath(Station *sink)
{
    vector<Edge *> path;

    Station *current_station = sink;
    while (current_station != nullptr && current_station->getPrevEdge() != nullptr)
    {
        // Add the edge from the previous station to the returning path
        path.push_back(current_station->getPrevEdge());

        // Move the current station to the previous one
        current_station = current_station->getPrevStation();
    }
    // The path is reversed order !!!
    reverse(path.begin(), path.end());
    return path;
}

// T2.1
int Graph::maxFlow(const string &source, const string &destination)
{
    // Initialize all flows as zero
    for (auto &s : allStations)
    {
        for (auto &e : s.adj)
        {
            e->setFlow(0);
        }
    }

    // while exist augmenting path
    // increase flow in this path
    // update the residual network
    int max_flow = 0;

    // Augmenting path
    vector<Edge *> path;

    while (true)
    {
        path = bfsFindPath(source, destination);
        if (path.empty())
            break;

        // find the bottleneck capacity of the augmenting path
        int bottleneck = INT_MAX;
        for (auto &e : path)
        {
            if (e->getCapacity() - e->getFlow() < bottleneck)
                bottleneck = e->getCapacity() - e->getFlow();
        }

        // increase the flow on each edge of the augmenting path
        for (auto &e : path)
        {
            e->setFlow(e->getFlow() + bottleneck);
            Edge *rev = e->getReverseEdge();
            if (rev != nullptr)
                rev->setFlow(rev->getFlow() - bottleneck);
        }
        max_flow += bottleneck;
    }
    return max_flow;
}

// T2.2
void Graph::topK(int n)
{
    // Variable that represents a pair of stations
    typedef pair<Station *, Station *> par_of_stations;

    // Lambda function that compare two pair of stations
    auto comp = [this](par_of_stations a, par_of_stations b)
    {
        return maxFlow(a.first->getName(), a.second->getName()) > maxFlow(b.first->getName(), b.second->getName());
    };

    // Priority queue that keeps the pair with the Max Flow found in the graph in the top
    priority_queue<par_of_stations, vector<par_of_stations>, decltype(comp)> pq(comp);

    for (Station &s1 : allStations)
    {
        for (Station &s2 : allStations)
        {

            // Check first is at least exist a path between the stations
            if (bfsFindPath(s1.getName(), s2.getName()).empty())
                continue;

            par_of_stations temp(&s1, &s2);

            // If the pq has not reached its limit, just push it
            if (pq.size() < n)
                pq.push(temp);
            else if (comp(temp, pq.top()))
            {
                pq.pop();
                pq.push(temp);
            }
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().first->getName() << " to " << pq.top().second->getName() << endl;
        pq.pop();
    }
}

// T2.3
void Graph::getBudget(int x)
{
    map<string, int> districts_or_municipalities;

    switch (x)
    {
    case 1:
        for (Station &s1 : allStations)
        {
            for (Station &s2 : allStations)
            {
                districts_or_municipalities[s2.getDistrict()] += maxFlow(s1.getName(), s2.getName());
            }
        }
        for (auto const &entry : districts_or_municipalities)
        {
            cout << entry.first << ": " << entry.second << '\n';
        }

        break;
    case 2:
        for (Station &s1 : allStations)
        {
            for (Station &s2 : allStations)
            {
                districts_or_municipalities[s2.getMunicipality()] += maxFlow(s1.getName(), s2.getName());
            }
        }
        for (auto const &entry : districts_or_municipalities)
        {
            cout << entry.first << ": " << entry.second << '\n';
        }
    default:
        break;
    }
}

// T2.4
int Graph::entireMaxFlow(const string &sink)
{
    if (findStationByName(sink) == nullptr)
    {
        cout << "This station does not exist\n"
             << endl;
        return 0;
    }

    // Make a superSource point
    auto *superSource = new Station("superSource", "d", "m", "t", "l");

    for (Station &s : allStations)
    {
        if (s.getName() != sink && !bfsFindPath(s.getName(), sink).empty())
        {
            Edge *e = new Edge(superSource, &s, INT_MAX, "normal");
            superSource->addEdge(e);
        }
    }

    allStations.push_back(*superSource);

    return maxFlow("superSource", sink);
}

// T3.1
int Graph::shortestPathCost(const string &source, const string &destination)
{
    setAllStationsUnvisited();

    // Set all the distances as infinite first
    for (Station &s : allStations)
        s.setDist(INT_MAX);

    // Lambda function that compares two station based on the distance
    auto comp = [this](Station *a, Station *b)
    { return a->getDist() < b->getDist(); };

    // Priority queue to pick always the station with the lowest distance
    priority_queue<Station *, vector<Station *>, decltype(comp)> pq(comp);

    Station *s = findStationByName(source);
    Station *d = findStationByName(destination);
    s->setDist(0);
    pq.push(s);

    while (!pq.empty())
    {
        Station *current_station = pq.top();
        pq.pop();

        current_station->setVisited(true);

        // If the cost for the destination already has been set, the function can exit
        if (current_station == d)
            return d->getDist();

        for (auto &e : current_station->adj)
        {
            Station *next_station = e->getDestination();

            if (next_station->getVisited())
                continue;

            int new_dist = current_station->getDist() + e->getCapacity() * (e->getType() == "STANDARD" ? 2 : 4);
            if (new_dist < next_station->getDist())
            {
                next_station->setDist(new_dist);
                pq.push(next_station);
            }
        }
    }
    // Case that the source cannot reach the destination
    return 0;
}

int Graph::getLines()
{
    int lines = 0;
    for (auto &station : allStations)
    {
        lines += station.adj.size();
    }
    return lines / 2;
}

int Graph::maxFlowReduced(const string &source, const string &destination, const string &station1, const string &station2)
{
    // Initialize all flows as zero
    for (auto &s : allStations)
    {
        for (auto &e : s.adj)
        {
            e->setFlow(0);
        }
    }
    // while exist augmenting path
    // increase flow in this path
    // update the residual network
    int max_flow = 0;

    // Augmenting path
    vector<Edge *> path;

    while (true)
    {
        bool edgeInPath = false;
        path = bfsFindPath(source, destination);
        if (path.empty())
            break;
        for (auto it : path)
        {
            if (it->getSource()->getName() == station1 && it->getDestination()->getName() == station2 ||
                it->getSource()->getName() == station2 && it->getDestination()->getName() == station1)
            {
                edgeInPath = true;
                break;
            }
        }
        if (edgeInPath)
            break;

        // find the bottleneck capacity of the augmenting path
        int bottleneck = INT_MAX;
        for (auto &e : path)
        {
            if (e->getCapacity() - e->getFlow() < bottleneck)
                bottleneck = e->getCapacity() - e->getFlow();
        }

        // increase the flow on each edge of the augmenting path
        for (auto &e : path)
        {
            e->setFlow(e->getFlow() + bottleneck);
            Edge *rev = e->getReverseEdge();
            if (rev != nullptr)
                rev->setFlow(rev->getFlow() - bottleneck);
        }
        max_flow += bottleneck;
    }
    return max_flow;
}
