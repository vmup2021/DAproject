//
// Created by joao on 05/04/2023.
//

#ifndef DA__MENU_H
#define DA__MENU_H

#include "Graph.h"

using namespace std;

void clearBuffer();
int menu();
int showMenu();

/********** Data Set Menu **********/
void dataSetFilesMenu(Graph *r);
int showDataSetFilesOptions(Graph *r);
void readFromFile(Graph *r);

/********** Basic Service Menu **********/
void basicServiceMenu(Graph *r);
int showBasicServiceOptions();
void maxTrainsBetweenStations(Graph *r);
void mostAmountOfTrains(Graph *r);
void largerBudgetDistricts(Graph *r);
void maxTrainsArriveAtStation(Graph *r);

/********** Cost Optimization Menu **********/
void costOptimizationMenu(Graph *r);
int showCostOptimizationOptions();
void minimumCostBetweenStations(Graph *r);

/********** Reliability Menu **********/
void reliabilityMenu(Graph *r);
int showReliabilityOptions();
void maxTrainsBetweenStationsReduced(Graph *r);
// void reportOnMostAffectedStations(Graph *r);

#endif // DA__MENU_H
