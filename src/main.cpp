#include <iostream>

#include "Graph.h"
#include "menu.h"

using namespace std;

int main()
{
    int menuOption;

    Graph r = Graph();

    cout << "=======================================" << endl;
    cout << "======== Welcome to DA Railway ========" << endl;
    cout << "=======================================" << endl;
    do
    {
        menuOption = menu();
        switch (menuOption)
        {
        case 1: // Problem Data and Interface
            dataSetFilesMenu(&r);
            break;
        case 2: // Basic Service Metrics
            basicServiceMenu(&r);
            break;
        case 3: // Operation Cost Optimization
            costOptimizationMenu(&r);
            break;
        case 4: // Reliability and Sensitivity to Line Failures
            reliabilityMenu(&r);
            break;
        case 0:
            continue;
        default:
            cout << "ERROR: Not a valid Operation! Please try again..." << endl;
        }
    } while (menuOption != 0);

    return 0;
}