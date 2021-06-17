#ifndef UNTITLED2_SORTEDLIST_H
#define UNTITLED2_SORTEDLIST_H

#include <cassert>
#include <stdexcept>
#include "Node.h"


template <class T>
class SortedList {
    Node<T> *head;
    Node<T> *last;
    int size;
public:
    SortedList();

    ~SortedList();

    SortedList(const SortedList &s_list);

    SortedList<T> &operator=(const SortedList &s_list);


    int length() const;

    class const_iterator;

    const_iterator begin() const;

    const_iterator end() const;

    void insert(const T& element);

    void remove(const_iterator it);

    template<typename Predicate>
    SortedList<T> filter(Predicate pred);

    template<typename FuncType>
    SortedList<T> apply(FuncType func);

    bool operator==(const SortedList &other) const;

};

template<class T>
SortedList<T>::SortedList()
        : size(0), head(nullptr), last(nullptr) {}



template<class T>
SortedList<T>::~SortedList() {
    if(head != nullptr){
        Node<T>* iterator = head;
        Node<T>* temp = iterator;
        while(iterator != last){
            iterator = iterator->getNext();
            delete temp;
            temp = iterator;
        }

        delete iterator;

    }
}

template<class T>
SortedList<T>::SortedList(const SortedList<T> &s_list){
    head = last = nullptr;
    size = 0;

    if(s_list.head == nullptr){
        return;
    }
    T value = s_list.last->getValue();
    this->insert(value);

    if (s_list.head != s_list.last) {

        Node<T> *iterator(s_list.head);

        while (iterator != s_list.last) {

            value = iterator->getValue();
            this->insert(value);
            iterator = iterator->getNext();

        }
    }


}


template<class T>
SortedList<T> &SortedList<T>::operator=(const SortedList<T> &s_list) {
    if (this == &s_list) {
        return *this;
    }

    //TODO: put this in a separate function?
    Node<T> *iterator = head;

    Node<T>* temp = head;
    if (iterator != last) {

        iterator = head->getNext();
        delete temp;
        while (iterator != last) {

            temp = iterator;
            iterator = iterator->getNext();
            delete temp;
        }
        delete iterator;
    }


    //TODO: put this in a separate function?
    size = 0;
    head = last = nullptr;

    if(s_list.head == nullptr){
        return *this;
    }

    T value = s_list.last->getValue();
    this->insert(value);
    if (s_list.head != s_list.last) {
        iterator = s_list.head;

        while (iterator != s_list.last) {

            value = iterator->getValue();
            this->insert(value);
            iterator = iterator->getNext();

        }

    }
    return *this;

}

template<class T>
bool SortedList<T>::operator==(const SortedList<T> &other) const {
    if (other.size != size) {
        return false;
    }
    Node<T> *this_iterator(head);
    Node<T> *other_iterator(other.head);

    //Both iterators are of the same length, therefore only need to check that one reached the end.
    while (this_iterator != last) {

        if (this_iterator->getValue() != other_iterator->getValue()) {
            return false;
        }
    }
    return last->getValue() == other.last->getValue();
}

template<class T>
int SortedList<T>::length() const {
    return size;
}



template<class T>
class SortedList<T>::const_iterator {
    int index;
    const SortedList<T> *s_list;


    friend class SortedList<T>;

    const_iterator(const SortedList<T> *s_list, int index);

    static T& findValue(const SortedList *sorted_list, int list_index) ;


public:
    const T& operator*() const;

    const_iterator &operator++();

    bool operator==(const const_iterator &it) const;

    ~const_iterator() = default;

    const_iterator(const const_iterator&) = default;


};



template<class T>
SortedList<T>::const_iterator::const_iterator(const SortedList<T> *s_list, int index):
        s_list(s_list), index(index) {
}

template<class T>
void SortedList<T>::insert(const T& element) {

    Node<T>* new_node = new Node<T>(element);
    if (head == nullptr) {
        head = last = new_node;
    }
    else if (head == last) { //size == 1
        if (head->getValue() > new_node->getValue()) {
            new_node->setNext(head);
            head = new_node;
        }
        else {
            head->setNext(new_node);
            last = new_node;
        }

    }
    else if(head->getValue() > new_node->getValue()){
        new_node->setNext(head);
        head = new_node;

    }

    else {

        Node<T> *iterator(head);
        while (iterator->getNext() != last && iterator->getNext()->getValue() < element) { //<= worked
            iterator = iterator->getNext();
        }

        if (iterator->getNext() == last && last->getValue() <= element) {
            last->setNext(new_node);
            last = new_node;
        }
        else{
            new_node->setNext(iterator->getNext());
            iterator->setNext(new_node);
        }

    }
    size++;

}

template<class T>
void SortedList<T>::remove(SortedList::const_iterator it) {

    //TODO check if const iterator could be invalid and think about empty list?
    if(begin() == it){
        Node<T> * iterator = head;
        head = head->getNext();
        delete iterator;
    }
    else {
        int counter = it.index;
        Node<T> *iterator = head;
        while (iterator->getNext() != last && counter - 1 > 0) {
            counter--;
            iterator = iterator->getNext();
        }

        if (iterator->getNext() == last) {
            last = iterator;
            delete iterator->getNext();

        }
        else {
            Node<T> *temp = iterator->getNext();
            iterator->setNext(iterator->getNext()->getNext());
            delete temp;
        }
    }

    size--;
}

template<class T>
bool SortedList<T>::const_iterator::operator==(const SortedList<T>::const_iterator &it) const {
    return index == it.index && s_list == it.s_list;
}

template<class T>
typename SortedList<T>::const_iterator &SortedList<T>::const_iterator::operator++() {
    const_iterator it = *this;
    if (it == s_list->end()) {
        throw std::out_of_range("Out of range");
    }
    ++index;

    return *this;
}

template<class T>
const T& SortedList<T>::const_iterator::operator*() const {
    assert(index >= 0 && index < s_list->length());
    return findValue(s_list, index);
}


template<class T>
T& SortedList<T>::const_iterator::findValue(const SortedList *sorted_list, int list_index) {
    Node<T> *iterator(sorted_list->head);
    while (list_index > 0) {
        iterator = iterator->getNext();
        list_index--;
    }
    return iterator->getValue();
}

template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const{
    return const_iterator(this, 0);
}

template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const {
    return const_iterator(this, size);
}

template<class T>
template<typename Predicate>
SortedList<T> SortedList<T>::filter(Predicate pred) {

    SortedList<T> new_sorted;
    for(auto it = this->begin(); !(it == this->end());++it){
        if(pred(*it)){
            new_sorted.insert(*it);
        }
    }

    return new_sorted;
}

template<class T>
template<typename FuncType>
SortedList<T> SortedList<T>::apply(FuncType func)
{
    SortedList<T> new_sorted;
    for(const_iterator it(begin()); !(it ==end()); ++it){
        T func_result = func(*it);
        new_sorted.insert(func_result);
    }
    return new_sorted;
}


#endif //UNTITLED2_SORTEDLIST_H
