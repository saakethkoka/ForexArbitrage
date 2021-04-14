//
// Created by Saaketh Koka on 3/25/21.
//

#include "DLList.h"
#pragma once

template<class T>
class DSAdjacencyList{
private:
    DLList<DLList<T> > list;
public:
    void addTwoWayEdge(T vertex1, T vertex2);
    void addOneWayEdge(T startVertex, T endVertex);
    bool containsVertex(T vertex);
    DLListNode<T>* getVertexPtr (T val);
    void printList();
};

template<class T>
void DSAdjacencyList<T>::addTwoWayEdge(T vertex1, T vertex2) {
    // Checking if the vertexes already exist in the list or not
    // If they do not, they will be added:
    if(!containsVertex(vertex1)){
        DLList<T> listToAdd;
        listToAdd.pushBack(vertex1);
        list.pushBack(listToAdd);
    }
    if(!containsVertex(vertex2)){
        DLList<T> listToAdd;
        listToAdd.pushBack(vertex2);
        list.pushBack(listToAdd);
    }

    DLListNode<DLList<T> > *outerNode = list.front;
    while(outerNode->data.front->data != vertex1){
        outerNode = outerNode->next;
    }
    // Checking to see if the inner linked list of vertex 1 contains vertex 2
    // If not, it adds it:
    if(!outerNode->data.contains(vertex2)){
        outerNode->data.pushBack(vertex2);
    }

    outerNode = list.front;
    while(outerNode->data.front->data != vertex2){
        outerNode = outerNode->next;
    }
    // Checking to see if the inner linked list of vertex 1 contains vertex 2
    // If not, it adds it:
    if(!outerNode->data.contains(vertex1)){
        outerNode->data.pushBack(vertex1);
    }
}

template<class T>
void DSAdjacencyList<T>::addOneWayEdge(T startVertex, T endVertex) {
    // Checking if the vertexes already exist in the list or not
    // If they do not, they will be added:
    if(!containsVertex(startVertex)){
        DLList<T> listToAdd;
        listToAdd.pushBack(startVertex);
        list.pushBack(listToAdd);
    }
//    if(!containsVertex(endVertex)){
//        DLList<T> listToAdd;
//        listToAdd.pushBack(endVertex);
//        list.pushBack(listToAdd);
//    }

    DLListNode<DLList<T> > *outerNode = list.front;
    while(outerNode->data.front->data != startVertex){
        outerNode = outerNode->next;
    }
    // Checking to see if the inner linked list of vertex 1 contains vertex 2
    // If not, it adds it:
    if(!outerNode->data.contains(endVertex)){
        outerNode->data.pushBack(endVertex);
    }
}

template<class T>
bool DSAdjacencyList<T>::containsVertex(T vertex) {
    DLListNode<DLList<T> > *node = list.front;
    while(node != nullptr){
        if(node->data.front->data == vertex){
            return true;
        }
        node = node->next;
    }
    return false;
}

template<class T>
void DSAdjacencyList<T>::printList() {
    DLListNode<DLList<T> > *outerNode = list.front;
    DLListNode<T> *innerNode;
    while(outerNode != nullptr){
        innerNode = outerNode->data.front;
        while(innerNode != nullptr){
            std::cout << innerNode->data << "->";
            innerNode = innerNode->next;
        }
        std::cout << "null" << std::endl;
        outerNode = outerNode->next;
    }
}

template<class T>
DLListNode<T> *DSAdjacencyList<T>::getVertexPtr(T val) {
    DLListNode<DLList<T> > *outerNode = list.front;
    while(outerNode != nullptr){
        if(outerNode->data.front->data == val){
            return outerNode->data.front->next;
        }
        outerNode = outerNode->next;
    }
    throw std::invalid_argument("Vertex is not in list");
}


