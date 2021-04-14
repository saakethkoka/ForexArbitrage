//
// Created by Saaketh Koka on 4/13/21.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder(const std::string &inputFile) {
    DocumentParser parser(inputFile);
    this->currencyList = parser.getAdjacencyList();
}

void Pathfinder::findPath() const {

}
