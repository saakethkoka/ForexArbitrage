//
// Created by Saaketh Koka on 4/13/21.
//

#include <string>
#include "DocumentParser.h"
#include <vector>
class Pathfinder {
private:
    DSAdjacencyList<Currency> currencyList;
    std::vector<Currency> currPath;


public:
    Pathfinder(const std::string& inputFile);
    void findPath() const;
    void printPath() const;

};


