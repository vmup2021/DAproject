/**
 * @file menu.h
 * @author G07_4
 * @brief This file handles the menu.
 * @version 0.1
 * @date 2023-04-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef DA__MENU_H
#define DA__MENU_H

#include "Graph.h"

using namespace std;

/**
 * @brief Function to clear input buffer.
 *
 * Calls cin.clear() and cin.ignore().
 */
void clearBuffer();

/**
 * @brief Function to get menu options.
 *
 * Calls showMenu() to print menu options.
 * @see showMenu()
 *
 * @return int The menu option chosen by the user.
 */
int menu();

/**
 * @brief Prints the various menu options available on screen.
 *
 * @return int The menu option chosen by the user.
 */
int showMenu();

/********** Data Set Menu **********/

/**
 * @brief Function to get railway network data set menu options.
 *
 * Calls showDataSetFilesOptions() to print menu options.
 * @see showDataSetFilesOptions().
 *
 * @param r Railway Graph.
 */
void dataSetFilesMenu(Graph *r);

/**
 * @brief Prints railway network data set menu options available on screen.
 *
 * @param r Railway Graph.
 * @return int The data set menu option chosen by the user.
 */
int showDataSetFilesOptions(Graph *r);

/**
 * @brief Function to insert file information into railway graph.
 *
 * @param r Railway Graph.
 */
void readFromFile(Graph *r);

/********** Basic Service Menu **********/

/**
 * @brief Function to get railway network basic service menu options.
 *
 * Calls showBasicServiceOptions() to print menu options.
 * @see showBasicServiceOptions().
 *
 * @param r Railway Graph.
 */
void basicServiceMenu(Graph *r);

/**
 * @brief Prints railway network basic services menu options available on screen.
 *
 * @return int The data set menu option chosen by the user.
 */
int showBasicServiceOptions();

/**
 * @brief Function to calculate the maximum number of trains that can simultaneously travel between two specific stations.
 *
 * @param r Railway Graph.
 */
void maxTrainsBetweenStations(Graph *r);

/**
 * @brief Function to report the top x (you're choice) pair of stations that require the most amount of trains when taking full advantage of the existing network capacity.
 *
 * @param r Railway Graph.
 */
void mostAmountOfTrains(Graph *r);

/**
 * @brief Function to report the budget for each district or municipality.
 *
 * @param r Railway Graph.
 */
void largerBudgetDistricts(Graph *r);

/**
 * @brief Function to report the most amount of trains that t can simultaneously arrive at a given station, aking into consideration the entire railway grid.
 *
 * @param r Railway Graph.
 */
void maxTrainsArriveAtStation(Graph *r);

/********** Cost Optimization Menu **********/

/**
 * @brief Function to get railway network cost optimization menu options.
 *
 * Calls showCostOptimizationOptions() to print menu options.
 * @see showCostOptimizationOptions().
 *
 * @param r Railway Graph.
 */
void costOptimizationMenu(Graph *r);

/**
 * @brief Prints railway network cost optimization menu options available on screen.
 *
 * @return int The cost optimization menu option chosen by the user.
 */
int showCostOptimizationOptions();

/**
 * @brief Function to determine the minimum cost path between two specific stations.
 *
 * @param r Railway Graph.
 */
void minimumCostBetweenStations(Graph *r);

/********** Reliability Menu **********/

/**
 * @brief Function to get railway network reliability menu options.
 *
 * Calls showReliabilityOptions() to print menu options.
 * @see showReliabilityOptions().
 *
 * @param r Railway Graph.
 */
void reliabilityMenu(Graph *r);

/**
 * @brief Prints railway network basic services menu options available on screen.
 *
 * @return int The reliability menu option chosen by the user.
 */
int showReliabilityOptions();

/**
 * @brief Function to calculate the maximum number of trains that can simultaneously travel between two specific stations in a network of reduced connectivity.
 *
 * @param r Railway Graph.
 */
void maxTrainsBetweenStationsReduced(Graph *r);
// void reportOnMostAffectedStations(Graph *r);

#endif // DA__MENU_H
