//
// Created by Yehonatan on 14/06/2021.
//

#ifndef UNTITLED2_NODE_H
#define UNTITLED2_NODE_H

#include <iostream>


template <class T>
class Node {
private:
    T n_value;
    Node* next;
public:
    explicit Node(T);

    ~Node()=default;
    Node(Node& other)=default;

    Node& operator=(const Node& node)=default;
    T& getValue() ;
    Node* getNext();
    void setNext(Node* node);

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

};

template<class T>
Node<T>::Node(const T value)
        : n_value(value), next(nullptr) {}


template<class T>
std::ostream operator<<(std::ostream &os, const Node<T> &node) {
    return os << node.getValue() << std::endl;
}

template<class T>

T &Node<T>::getValue()  {
    return n_value;
}

template<class T>

Node<T> *Node<T>::getNext() {
    return this->next;
}

template<class T>

void Node<T>::setNext(Node<T> *node) {
    this->next = node;
}



#endif //UNTITLED2_NODE_H
