//
// Created by Saaketh Koka on 4/13/21.
//

#include <string>
#include "DocumentParser.h"

class Pathfinder {
private:
    DSAdjacencyList<Currency> currencyList;


public:
    Pathfinder(const std::string& inputFile);
    void findPath() const;
    void printPath() const;

};


