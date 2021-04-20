//
// Created by Saaketh Koka on 4/13/21.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder(const std::string &inputFile) : currPath(), bestPath() {
    DocumentParser parser(inputFile);
    this->currencyList = parser.getAdjacencyList();
    bestROI = 1;
    base = Currency("USD",1);
    currPath.pushBack(base);
    DLListNode<Currency>* nextNode = this->currencyList.getVertexPtr(base);
    while(nextNode != nullptr && ! currPath.isEmpty()){
        findPath(nextNode);
        currPath.popBack();
        nextNode = nextNode->next;
    }
}

void Pathfinder::findPath(DLListNode<Currency>* node) {
    if(node == nullptr){
        return;
    }

    if(node->data.get_name() == "USD"){
        currPath.pushBack(node->data);
        isBestPath();
        return;
    }
    if(isInCurrPath(node->data)){
        currPath.pushBack(node->data);
        return;
    }
    currPath.pushBack(node->data);
    DLListNode<Currency>* nextNode = this->currencyList.getVertexPtr(node->data);
    while(nextNode != nullptr){
        if(currPath.isEmpty()){
            return;
        }
        findPath(nextNode);
        if(currPath.isEmpty()){
            return;
        }
        currPath.popBack();
        nextNode = nextNode->next;
    }
}

int Pathfinder::findInVect(Currency c) {
    for(int i = 0; i < currPath.getSize(); i++){
        if(currPath.at(i) == c){
            return i;
        }
    }
    return -1;
}

bool Pathfinder::isInCurrPath(Currency c) {
    for(int i = 0; i < currPath.getSize(); i++){
        if(c == currPath.at(i)){
            return true;
        }
    }
    return false;
}

void Pathfinder::printPath() {
    std::cout << bestROI << std::endl;
    for(int i = 0; i < bestPath.getSize(); i++){
        std::cout << bestPath.at(i) << std::endl;
    }
}

bool Pathfinder::isBestPath() { //Runs in O(n) time
    double currRatio = 1;
    for(int i = 0; i < currPath.getSize() - 1; i++){
        DLListNode<Currency>* node = currencyList.getVertexPtr(currPath.at(i));
        while(node != nullptr){
            if(node->data == currPath.at(i + 1)){
                currRatio *= node->data.get_ratio();
                break;
            }
            node = node->next;
        }
    }
    if(currRatio > bestROI){
        bestPath = currPath;
        bestROI = currRatio;
        return true;
    }
    return false;
}
/*
Pathfinder::~Pathfinder() {
    std::vector<int> f;
    std::cout << "Sifdsa" << std::endl;
    currPath.clear();


}
 */
