//
// Created by Saaketh Koka on 4/13/21.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder(const std::string &inputFile) : currPath(), bestPath() {
    DocumentParser parser(inputFile);
    this->currencyList = parser.getAdjacencyList();
    numIters = 0;
    bestROI = 1;
    base = Currency("USD",1);
    currPath.push_back(base);
    DLListNode<Currency>* nextNode = this->currencyList.getVertexPtr(base);
    while(nextNode != nullptr){
        if(currPath.empty()){
            return;
        }
        findPath(nextNode);
        currPath.pop_back();
        nextNode = nextNode->next;
    }
    std::cout << bestROI << std::endl;
    for(const auto &c : bestPath){
        std::cout << c << std::endl;
    }
}

void Pathfinder::findPath(DLListNode<Currency>* node) {
    numIters++;
    if(numIters > 50000){
        return;
    }
    std::cout << numIters << std::endl;
    if(node == nullptr){
        return;
    }

    if(node->data.get_name() == "USD"){
        currPath.push_back(node->data);
        isBestPath();
        return;
    }
    if(isInCurrPath(node->data)){
        return;
    }
    currPath.push_back(node->data);
    DLListNode<Currency>* nextNode = this->currencyList.getVertexPtr(node->data);
    while(nextNode != nullptr){
        if(currPath.empty()){
            return;
        }
        findPath(nextNode);
        if(currPath.empty()){
            return;
        }
        currPath.pop_back();
        nextNode = nextNode->next;
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

bool Pathfinder::isBestPath() { //Runs in O(n) time
    double currRatio = 1;
    for(int i = 0; i < currPath.size() - 1; i++){
        DLListNode<Currency>* node = currencyList.getVertexPtr(currPath[i]);
        while(node != nullptr){
            if(node->data == currPath[i + 1]){
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
