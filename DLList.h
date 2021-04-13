//
// Created by Saaketh Koka on 2/16/21.
//

#ifndef LINKEDLISTS_DLLIST_H
#define LINKEDLISTS_DLLIST_H
#include "DLListNode.h"
#include <stdexcept>
#include <exception>

template<class T>
class DLList{
    template<class U>friend class DSAdjacencyList;
private:
    DLListNode<T> *front;
    DLListNode<T> *back;
public:
    DLList();
    DLList(DLList const &list2BCopied);
    ~DLList();

    // = operator:
    DLList<T> operator=(const DLList<T> &list2BCopied);

    // Adds a new node to the end of list:
    void pushBack(const T &v);
    // Adds a new node to the front of list:
    void pushFront(const T &v);
    // Adds a new node after a specified element. Returns true if the element is found and node is inserted, false otherwise:
    bool insertAfter(T insertVAl, T prevVal);
    // Returns true if v is in list, false otherwise:
    bool contains(T v);
    // Deletes any node with value v from list. Returns true if deleted at least 1 node, else false:
    bool erase(T v);
    // Clones a new list and returns a pointer to that list:
    DLList<T>* clone();
    // Returns nth element in list:
    T at(int n);
    // Returns true if List is empty:
    bool isEmpty();
    // Removes and returns data from first element from list:
    T popFront();
    // Removes and returns data from last element from list:
    T popBack();
    // Returns data from the first element:
    T& peakFront();
    // Returns data from the last element:
    T& peakBack();
    // Returns Size of List:
    int getSize();

    DLListNode<T>* getFront();
    DLListNode<T>* getBack();

    // Prints each element in the list:
    void print();

    // Iterator gotten from:
    // http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
    class iterator {
        friend class DLList<T>;
    private:
        DLListNode<T> *nodePtr;
        // The constructor is private, so only our friends
        // can create instances of iterators.
        iterator(DLListNode<T> *newPtr) : nodePtr(newPtr) {}
    public:
        iterator() : nodePtr(nullptr) {}

        // Overload for the comparison operator !=
        bool operator!=(const iterator& itr) const {
            return nodePtr != itr.nodePtr;
        }

        // Overload for the dereference operator *
        T& operator*() const {
            return nodePtr->next->data;
        }

        // Overload for the postincrement operator ++
        iterator operator++(int) {
            iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }
        iterator operator--(int) {
            iterator temp = *this;
            nodePtr = nodePtr->prev;
            return temp;
        }
    };
    iterator begin() const {
        return iterator(front);
    }

    iterator end() const {
        return iterator(back);
    }
};

template<class T>
DLList<T>::DLList() {
    front = nullptr;
    back = nullptr;
}

template<class T>
DLList<T>::DLList(const DLList &list2BCopied) {
    this->front = nullptr;
    this->back = nullptr;
    DLListNode<T> *node = list2BCopied.front;
    while(node != nullptr){
        pushBack(node->data);
        node = node->next;
    }
}

template<class T>
DLList<T>::~DLList() {
    DLListNode<T> *node = front;
    front = nullptr;
    DLListNode<T> *nextNode;
    while(node != nullptr){
        nextNode = node->next;
        delete node;
        node = nextNode;
    }
    back = nullptr;
}

template<class T>
DLList<T> DLList<T>::operator=(const DLList<T> &list2BCopied) {
    this->front = nullptr;
    this->back = nullptr;
    DLListNode<T> *node = list2BCopied.front;
    while(node != nullptr){
        pushBack(node->data);
        node = node->next;
    }
    return *this;
}


template <class T>
void DLList<T>::pushBack(const T &v) {
    DLListNode<T> *node = new DLListNode<T>(v);
    if(front == nullptr){
        front = node;
        back = node;
    }
    else{
        node->prev = back;
        back->next = node;
        back = node;
    }
}

template<class T>
bool DLList<T>::insertAfter(T insertVal, T prevVal){
    DLListNode<T> *node = front;
    while(node != nullptr){
        if(node->data == prevVal){
            DLListNode<T> *newNode = new DLListNode<T>(insertVal);
            newNode->next = node->next;
            newNode->prev = node;
            node->next = newNode;
            return true;
        }
        node = node->next;
    }
    return false;
}
// Returns true if v is in list, false otherwise:
template<class T>
bool DLList<T>::contains(T v) {
    DLListNode<T> *node = front;
    while(node != nullptr){
        if(node->data == v){
            return true;
        }
        node = node->next;
    }
    return false;

}

template<class T>
bool DLList<T>::erase(T v) {
    bool deletedANode = false;
    DLListNode<T> *node = front;
    DLListNode<T> *temp;
    while(node != nullptr){
        if(node->data == v){
            if(node->next == nullptr && node->prev == nullptr){
                delete node;
                front = nullptr;
                back = nullptr;
                return true;
            }
            else if(node->next == nullptr){
                this->back = node->prev;
                node->prev->next = nullptr;
            }
            else if(node->prev == nullptr){
                this->front = node->next;

            }
            else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            temp = node->next;
            delete node;
            node = temp;

            deletedANode = true;
            continue;
        }
        node = node->next;
    }
    return deletedANode;
}

template<class T>
void DLList<T>::print() {
    DLListNode<T> *node = front;
    while(node != nullptr){
        std::cout << node->data << std::endl;
        node = node->next;
    }
}

template<class T>
DLList<T>* DLList<T>::clone() {
    DLList<T> *list = new DLList<T>();
    DLListNode<T> *node  = front;
    while(node != nullptr){
        list->pushBack(node->data);
        node = node->next;
    }
    return list;
}

template<class T>
T DLList<T>::at(int n) {
    int i = 0;
    DLListNode<T> *node  = front;
    while(node != nullptr){
        if(i == n){
            return node->data;
        }
        i++;
        node = node->next;
    }
    throw std::out_of_range("Invalid index");
}

template<class T>
bool DLList<T>::isEmpty() {
    if(front != nullptr){
        return false;
    }
    else{
        return true;
    }
}

template<class T>
T DLList<T>::popFront() {
    T data;
    if(front != nullptr){
        DLListNode<T> *node = front;
        if(node->next != nullptr){
            front = node->next;
            node->next->prev = nullptr;
        }
        else{
            front = nullptr;
            back = nullptr;
        }
        data = node->data;
        delete node;
    }
    return data;
}

template<class T>
T DLList<T>::popBack() {
    T data;
    if(front != nullptr){
        DLListNode<T> *node = back;
        if(node->prev != nullptr){
            back = node->prev;
            node->prev->next = nullptr;
        }
        else{
            front = nullptr;
            back = nullptr;
        }
        data = node->data;
        delete node;
    }
    return data;
}

template<class T>
T& DLList<T>::peakFront() {
    if(front == nullptr){
        throw std::out_of_range("Invalid Access: List is empty");
    }
    return front->data;
}

template<class T>
T& DLList<T>::peakBack() {
    if(front == nullptr){
        throw std::out_of_range("Invalid Access: List is empty");
    }
    return back->data;
}

template<class T>
DLListNode<T> *DLList<T>::getFront() {
    return front;
}

template<class T>
DLListNode<T> *DLList<T>::getBack() {
    return back;
}

template<class T>
void DLList<T>::pushFront(const T &v) {
    DLListNode<T> *node = new DLListNode<T>(v);
    if(front == nullptr){
        front = node;
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
        front = node;
    }
}

template<class T>
int DLList<T>::getSize() {
    int counter = 0;
    DLListNode<T> *node = front;
    while(node != nullptr){
        counter++;
        node = node->next;
    }
    return counter;
}


#endif //LINKEDLISTS_DLLIST_H
