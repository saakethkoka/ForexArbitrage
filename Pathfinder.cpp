//
// Created by Saaketh Koka on 4/13/21.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder(const std::string &inputFile) : currPath(), bestPath() {
    DocumentParser parser(inputFile);
    this->currencyList = parser.getAdjacencyList();
    bestROI = 1;
    base = Currency("USD",1);
    findPath();
}

void Pathfinder::findPath() {

}

int Pathfinder::findInVect(Currency c) {
    for(int i = 0; i < currPath.size(); i++){
        if(currPath[i] == c){
            return i;
        }
    }
    return -1;
}

bool Pathfinder::isInCurrPath(Currency c) {
    for(auto &d : currPath){
        if(c == d){
            return true;
        }
    }
    return false;
}

void Pathfinder::printPath() {
    for(auto &c : bestPath){
        std::cout << c << std::endl;
    }
    std::cout << "Rate: " << bestROI << std::endl;
}

bool Pathfinder::isBestPath() { //Runs in O(n) time
    double currRatio = 1;
    for(auto &c: currPath){
        currRatio *= c.get_ratio();
    }
    if(currRatio > bestROI){
        bestPath = currPath;
        bestROI = currRatio;
        return true;
    }
    return false;
}
