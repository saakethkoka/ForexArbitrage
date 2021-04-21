//
// Created by Saaketh Koka on 4/13/21.
//

#include <string>
#include <vector>
#include "DocumentParser.h"
class Pathfinder {
private:
    DSAdjacencyList<Currency> currencyList; //This is the adjacency list of the currency pairs
    DLList<Currency> currPath; //This is the most recently calculated path
    DLList<Currency> bestPath; //This is the best path (one directional)
    Currency base; //This is the currency from which the code begins and ends
    double bestROI; //This is the amoutn that the best path returns in one walk
    int findInVect(Currency& c);
    bool isInCurrPath(Currency& c);
    bool isBestPath(); //This method checks if the currPath has a larger ratio than bestPath. If so, it swaps the two

public:
    Pathfinder(const std::string& inputFile); //constructor
  //  ~Pathfinder();
    void findPath(DLListNode<Currency>*& node); //This generates values for the bestROI and bestPath
    double printPath(double amount = 1, double prevProfit = 0); //This generates the output for the program
    double getBestROI();

};


