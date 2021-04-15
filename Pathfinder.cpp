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
    currPath.push_back(base);
    DLListNode<Currency> *currNode = currencyList.getVertexPtr(base);
    solve(1, currNode);
}

void Pathfinder::solve(double rate, DLListNode<Currency> *currNode) {
    std::cout << currPath.size() << std::endl;
    currPath.push_back(currNode->data);
    rate *= currNode->data.get_ratio();
    if(currNode->data == base && currPath.size() != 1){
        if(bestROI < rate){
            bestROI = rate;
            bestPath = currPath;
        }
        currPath.pop_back();
        return;
    }
    if(currPath.empty()){
        return;
    }

    while(currNode != nullptr){

        if(isInCurrPath(currNode->data)){
            currNode = currNode->next;
            continue;
        }

        currNode = currencyList.getVertexPtr(currNode->data);
        solve(rate, currNode);
        currNode = currNode->next;
    }
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
