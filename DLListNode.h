//
// Created by Saaketh Koka on 2/16/21.
//

#ifndef LINKEDLISTS_DLLISTNODE_H
#define LINKEDLISTS_DLLISTNODE_H

#include <iostream>

template<typename T> class DLList;
template<typename T> class DSAdjacencyList;

template<class T>
class DLListNode {
public:
    DLListNode *next, *prev;
    T data;
    DLListNode(T val, DLListNode* n = nullptr, DLListNode* p = nullptr){
        next = n;
        prev = p;
        data = val;
    }

};




#endif //LINKEDLISTS_DLLISTNODE_H
