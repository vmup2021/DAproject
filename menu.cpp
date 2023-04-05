#include "menu.h"

void clearBuffer()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

int menu()
{
    int menuOption;

    do
    {
        menuOption = showMenu();
        if (menuOption < 0 || menuOption > 9)
        {
            cout << "ERROR: Not a valid Operation! Please try again..." << endl;
        }
    } while (menuOption < 0 || menuOption > 9);

    return menuOption;
}

int showMenu()
{
    int menuOption;

    cout << endl;
    cout << " ____________________________________ " << endl;
    cout << "| --- What would you like to do? --- |" << endl;
    cout << "| 1 - Data Set                       |" << endl;
    cout << "| 2 - Basic Service Metrics          |" << endl;
    cout << "| 3 - Operation Cost Optimization    |" << endl;
    cout << "| 4 - Railway Network Reliability    |" << endl;
    cout << "| 0 - Exit                           |" << endl;
    cout << "|____________________________________|" << endl;
    cout << "Option: ";
    cin >> menuOption;
    clearBuffer();

    return menuOption;
}

/************** Data Set Menu ***************/
void dataSetFilesMenu(Graph *r)
{
    int menuOption;

    do
    {
        menuOption = showDataSetFilesOptions(r);
        switch (menuOption)
        {
        case 0:
            break;
        case 1:
            readFromFile(r);
            break;
        default:
            cout << "ERROR: Not a valid Operation! Please try again..." << endl;
        }
    } while (menuOption != 0);
}

int showDataSetFilesOptions(Graph *r)
{
    int menuOption;

    cout << "______________________________________" << endl;
    cout << "---- Railway Network Information ----" << endl;
    cout << "Total Stations: " << r->allStations.size() << endl;
    cout << "Total Lines: " << r->getLines() << endl;
    cout << "______________________________________" << endl;
    cout << " ---- What would you like to do? ---- " << endl;
    cout << " 1 - Load New Data Set" << endl;
    cout << " 0 - Back" << endl
         << endl;
    cout << "Option: ";
    cin >> menuOption;

    return menuOption;
}

void readFromFile(Graph *r)
{
    string lineName;

    clearBuffer();
    cout << "Enter line to be loaded(i.e. Linha do Norte)(Default: all): ";
    getline(cin, lineName);

    if (lineName.empty())
        r->readStations("all");
    else
        r->readStations(lineName);

    r->readEdges();
    cout << "Railway Network Updated!" << endl
         << endl;
}

/************* Basic Service Menu **************/
void basicServiceMenu(Graph *r)
{
    int menuOption;

    do
    {
        menuOption = showBasicServiceOptions();
        switch (menuOption)
        {
        case 0:
            break;
        case 1:
            maxTrainsBetweenStations(r);
            break;
        case 2:
            mostAmountOfTrains(r);
            break;
        case 3:
            largerBudgetDistricts(r);
            break;
        case 4:
            maxTrainsArriveAtStation(r);
            break;
        default:
            cout << "ERROR: Not a valid Operation! Please try again..." << endl;
        }
    } while (menuOption != 0);
}

int showBasicServiceOptions()
{
    int menuOption;

    cout << "______________________________________" << endl;
    cout << " -------- Basic Service Menu -------- " << endl;
    cout << "______________________________________" << endl;
    cout << " ---- What would you like to do? ----" << endl;
    cout << "1 - Calculate the maximum number of trains between two stations" << endl;
    cout << "2 - Determine the pair of stations that require the most amount of trains" << endl;
    cout << "3 - Report top-k municipalities and districts" << endl;
    cout << "4 - Report the maximum number of trains that can simultaneously arrive at a station" << endl;
    cout << "0 - Back" << endl
         << endl;
    cout << "Option: ";
    cin >> menuOption;

    return menuOption;
}

void maxTrainsBetweenStations(Graph *r)
{
    string source, destination;

    clearBuffer();
    cout << "Source: ";
    getline(cin, source);
    cout << "Destination: ";
    getline(cin, destination);
    cout << "Maximum number of trains (Max FLow) between " << source << " and " << destination << " is " << r->maxFlow(source, destination) << "." << endl
         << endl;
}

void mostAmountOfTrains(Graph *r)
{
    string a;

    clearBuffer();
    cout << "How many pairs do you want to see? ";
    getline(cin, a);
    int n = stoi(a);

    r->topK(n);
}

void largerBudgetDistricts(Graph *r)
{
    string a;

    clearBuffer();
    cout << "Do you want to get budget for districts(press 1) ou municipalities(press 2)? ";
    getline(cin, a);
    int n = stoi(a);

    r->getBudget(n);
}

void maxTrainsArriveAtStation(Graph *r)
{
    string station;

    clearBuffer();
    cout << "Enter station to be tested: ";
    getline(cin, station);
    cout << "A maximum of " << r->entireMaxFlow(station) << " can arrive simultaneously at " << station << "." << endl << endl;
}

/************* Cost Optimization Menu *************/
void costOptimizationMenu(Graph *r)
{
    int menuOption;

    do
    {
        menuOption = showCostOptimizationOptions();
        switch (menuOption)
        {
        case 0: // Go back
            break;
        case 1:
            minimumCostBetweenStations(r);
            break;
        default:
            cout << "ERROR: Not a valid Operation! Please try again..." << endl;
        }
    } while (menuOption != 0);
}

int showCostOptimizationOptions()
{
    int menuOption;

    cout << endl
         << endl
         << endl;
    cout << "______________________________________" << endl;
    cout << " ------ Cost Optimization Menu ------" << endl;
    cout << "______________________________________" << endl;
    cout << " ---- What would you like to do? ---- " << endl;
    cout << "1 - Get the minimum cost path between two stations" << endl;
    cout << "0 - Back" << endl
         << endl;
    cout << "Option: ";
    cin >> menuOption;

    return menuOption;
}

void minimumCostBetweenStations(Graph *r)
{
    string source, destination;

    clearBuffer();
    cout << "Source: ";
    getline(cin, source);

    cout << "Destination: ";
    getline(cin, destination);

    int result = r->shortestPathCost(source, destination);
    if(result == 0)
        cout << "There is no path between " << source << " and " << destination << "." << endl << endl;
    else
        cout << "The minimum cost path between " << source << " and " << destination << " is " << result << "." << endl << endl;
}

/************* Reliability Menu *************/
void reliabilityMenu(Graph *r)
{
    int menuOption;

    do
    {
        menuOption = showReliabilityOptions();
        switch (menuOption)
        {
        case 0:
            break;
        case 1:
            maxTrainsBetweenStationsReduced(r);
            break;
        case 2:
            // reportOnMostAffectedStations(r);
            break;
        default:
            cout << "ERROR: Not a valid Operation! Please try again..." << endl;
        }
    } while (menuOption != 0);
}

int showReliabilityOptions()
{
    int menuOption;

    cout << "______________________________________" << endl;
    cout << " --------- Reliability Menu --------- " << endl;
    cout << "______________________________________" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1 - Calculate the maximum number of trains between two stations with reduced connectivity" << endl;
    cout << "2 - Report on the stations that are the most affected by each segment failure" << endl;
    cout << "0 - Back" << endl
         << endl;
    cout << "Option: ";
    cin >> menuOption;

    return menuOption;
}

void maxTrainsBetweenStationsReduced(Graph *r)
{
    string source, destination;

    clearBuffer();
    cout << "Source: ";
    getline(cin, source);

    cout << "Destination: ";
    getline(cin, destination);

    string station1, station2;

    cout << "Remove line between station: ";
    getline(cin, station1);

    cout << "And station: ";
    getline(cin, station2);

    cout << "Maximum number of trains (Max FLow) between " << source << " and " << destination << " without connection between " << station1 << " and " << station2 << " is " << r->maxFlowReduced(source, destination, station1, station2) << "." << endl
         << endl;
}
/*
void reportOnMostAffectedStations(Graph *r){

}
*/