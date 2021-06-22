#ifndef UNTITLED2_SORTEDLIST_H
#define UNTITLED2_SORTEDLIST_H

#include <cassert>
#include <stdexcept>
#include <iostream>

namespace mtm {

    template <class T>
    class Node {
    private:
        T n_value;
        Node* next;
    public:

        /**
         * Constructor for Node object
         * @param T: the generic type that Node stores.
         * */
        explicit Node(T);

        /**
         * Destructor for Node object - default
         * */
        ~Node()=default;

        /**
         * Copy Constructor for Node object - default
         * */
        Node(Node& other)=default;

        /**
         * Operator= for Node object - default
         * */
        Node& operator=(const Node& node)=default;

        /**
         * Function getValue():
         * @return - the value (not the copy) of T inside the Node.
         * */
        T& getValue() ;

        /**
         * Function getNext():
         * @return - pointer to the next Node.
         * */
        Node* getNext();

        /**
         * Function setNext():
         *@param node: the node this Node object will point next.
         * */
        void setNext(Node* node);

        /**
         * Operator<<
         * The Operator assigns the output to the os operator and returns os.
         * @param os: The output parameter to store the output.
         * @param Node<U>& - A reference to the node that will produce the output .
         * @@return: The output parameter.
         * */
        template<typename U>
        friend std::ostream& operator<< (std::ostream& os, const Node<U>&);

    };

    template<class T>
    Node<T>::Node(const T value)
            : n_value(value), next(nullptr) {}

    template<class T>
    std::ostream& operator<< (std::ostream &os, const Node<T> &node) {
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

    template<class T>
    class SortedList {
        Node<T> *head;
        Node<T> *last;
        int size;
    public:

        /**
         * Constructor.
         * */
        SortedList();

        /**
         * Destructor.
         * The destructor iterates through every value in the SortedList and deletes it.
         * */
        ~SortedList();

        /**
         * Copy Constructor.
         * The Constructor iterates through the elements in the other SortedList and copies it using the
         * insert function.
         * @param s_list: the SortedList to be copied.
         * */
        SortedList(const SortedList &s_list);

        /**
         * Assignment Operator.
         * The function deletes every element in the SortedList and copies the elements in s_list using
         * the insert function.
         * @param s_list: The SortedList to be copied.
         * @return: the updated SortedList.
         * */
        SortedList<T> &operator=(const SortedList &s_list);

        /**
         * The function returns the length of the SortedList.
         * */
        int length() const;

        /**
         * Class const_iterator:
         * Creating a new class in order for the user to go over the items in the list.
         * */
        class const_iterator;

        /**
         * The function returns a const_iterator of the first index of the SortedList
         * */
        const_iterator begin() const;

        /**
         * The function returns a const_iterator to the end of the SortedList.
          **/
        const_iterator end() const;

        /**
         * The function inserts an element to the SortedList.
         * @param element: The type T element
         * */
        void insert(const T &element);

        /**
         * The function removes the Node that the const_iterator is pointing to.
         * @param it - a const_iterator that points to the element to be removed.
         * @throw std::out_of_range - if the iterator is pointed to an empty SortedList.
         */
        void remove(const_iterator it);

        /**
         * The function receives a boolean funcObject, and returns a SortedList that holds
         * all the elements that returned true in the funcObject.
         * @tparam Predicate - the type of funcObject.
         * @param pred - the funcObject that filters the SortedList elements.
         * @return - A new SortedList that has all the filtered elements.
         */
        template<typename Predicate>
        SortedList<T> filter(Predicate pred);

        /**
         * The function receives a funcObject, and returns a SortedList of type T. The element
         * in the new SortedList are elements in the old SortedList which were applied in the func.
         * @tparam FuncType - the type of funcObject.
         * @param func - the funcObject which applies the elements in the old SortedList.
         * @return - A new SortedList that holds the applied elements from func.
         */
        template<typename FuncType>
        SortedList<T> apply(FuncType func);
    };


    template<class T>
    SortedList<T>::SortedList()
            : head(nullptr), last(nullptr), size(0) {}


    template<class T>
    SortedList<T>::~SortedList() {
        if (head != nullptr) {
            Node<T> *iterator = head;
            Node<T> *temp = iterator;
            while (iterator != last) {
                iterator = iterator->getNext();
                delete temp;
                temp = iterator;
            }

            delete iterator;

        }
    }

    template<class T>
    SortedList<T>::SortedList(const SortedList<T> &s_list) {
        head = last = nullptr;
        size = 0;

        if (s_list.head == nullptr) {
            return;
        }
        T value = s_list.last->getValue();
        this->insert(value);

        if (s_list.head != s_list.last) {

            Node<T> *iterator(s_list.head);

            while (iterator != s_list.last) {

                T it_value = iterator->getValue();
                this->insert(it_value);
                iterator = iterator->getNext();

            }
        }


    }


    template<class T>
    SortedList<T> &SortedList<T>::operator=(const SortedList<T> &s_list) {
        if (this == &s_list) {
            return *this;
        }

        Node<T> *iterator = head;

        Node<T> *temp = head;
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

        size = 0;
        head = last = nullptr;

        if (s_list.head == nullptr) {
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
    int SortedList<T>::length() const {
        return size;
    }


    template<class T>
    class SortedList<T>::const_iterator {
        int index;
        const SortedList<T> *s_list;

        friend class SortedList<T>;

        /**
         * Create a new const_iterator. Private constructor,
         * meaning that the user cannot call this constructor
         * @param s_list - the list that the iterator will point on.
         * @param index - the amount of elements from the beginning to the current
         * element the iterator is pointing on.
         */
        const_iterator(const SortedList<T> *s_list, int index);

        /**
         * The function returns the value of an element that the iterator is pointing on
         * @param sorted_list - the list that the iterator is pointing on.
         * @param list_index - the amount of elements from the beginning to the current
         * element the iterator is pointing on.
         * @return - The element that the iterator is pointing on.
         */
        static T &findValue(const SortedList *sorted_list, int list_index);


    public:

        /**
         * Destructor for const_iterator. Default.
         */
        ~const_iterator() = default;

        /**
         * Copy constructor for const_iterator. Default.
         */
        const_iterator(const const_iterator &) = default;

        /**
         * Assignment operator for const_iterator. Default.
         * @return
         */
        const_iterator& operator=(const const_iterator&)=default;

        /**
         * Operator * for const_iterator.
         * @return - the value of the element that the const_iterator is pointing on.
         */
        const T &operator*() const;

        /**
         * Prefix increment operator for const_iterator. The const_iterator first increments and then
         * returns the value.
         * @throw - out_of_range if the const_iterator is standing on the last element.
         * @return - the value of the const_iterator will stand on after the increment.
         */
        const_iterator &operator++();

        /**
         * Postfix increment operator for const_iterator. The const_iterator first returns the
         * value and then increments.
         * @throw - out_of_range if the const_iterator is standing on the last element.
         * @return - the value of the const_iterator before it increments.
         */
        const_iterator operator++(int);

        /**
         * Operator== for const_iterator.
         * @param it - the iterator to compare.
         * @return - true if the iterators are pointing to the same element in SortedList.
         */
        bool operator==(const const_iterator &it) const;


    };


    template<class T>
    SortedList<T>::const_iterator::const_iterator(const SortedList<T> *s_list, int index):
            index(index), s_list(s_list) {
    }

    template<class T>
    void SortedList<T>::insert(const T &element) {

        Node<T> *new_node = new Node<T>(element);
        if (head == nullptr) {
            head = last = new_node;
        } else if (head == last) { //size == 1
            if (new_node->getValue() < head->getValue()) {
                new_node->setNext(head);
                head = new_node;
            } else {
                head->setNext(new_node);
                last = new_node;
            }

        } else if (new_node->getValue() < head->getValue()) {
            new_node->setNext(head);
            head = new_node;

        }
        else {

            Node<T> *iterator(head);
            while (iterator->getNext() != last && iterator->getNext()->getValue() < element) {
                iterator = iterator->getNext();
            }

            if (iterator->getNext() == last && last->getValue() < element) {
                last->setNext(new_node);
                last = new_node;
            } else {
                new_node->setNext(iterator->getNext());
                iterator->setNext(new_node);
            }

        }
        size++;
    }

    template<class T>
    void SortedList<T>::remove(SortedList::const_iterator it) {

        if(it == end()){
            throw std::out_of_range("Iterator pointing to an empty list. Out of range.");
        }
        if (begin() == it) {
            Node<T> *iterator = head;
            head = head->getNext();
            delete iterator;
        } else {
            int counter = it.index;
            Node<T> *iterator = head;
            while (iterator->getNext() != last && counter - 1 > 0) {
                counter--;
                iterator = iterator->getNext();
            }

            if (iterator->getNext() == last) {
                last = iterator;
                delete iterator->getNext();

            } else {
                Node<T> *temp = iterator->getNext();
                iterator->setNext(iterator->getNext()->getNext());
                delete temp;
            }
        }

        size--;
    }

    template<class T>
    bool SortedList<T>::const_iterator::operator==(const SortedList<T>::const_iterator &it) const {
        return index == it.index;
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
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++(int) {
        auto it = *this;
        if (it == s_list->end()) {
            throw std::out_of_range("Out of range");
        }
        ++*this;
        return it;
    }


    template<class T>
    const T &SortedList<T>::const_iterator::operator*() const {
        assert(index >= 0 && index < s_list->length());
        return findValue(s_list, index);
    }


    template<class T>
    T &SortedList<T>::const_iterator::findValue(const SortedList *sorted_list, int list_index) {
        Node<T> *iterator(sorted_list->head);
        while (list_index > 0) {
            iterator = iterator->getNext();
            list_index--;
        }
        return iterator->getValue();
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const {
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
        for (auto it = this->begin(); !(it == this->end()); ++it) {
            if (pred(*it)) {
                new_sorted.insert(*it);
            }
        }

        return new_sorted;
    }

    template<class T>
    template<typename FuncType>
    SortedList<T> SortedList<T>::apply(FuncType func) {
        SortedList<T> new_sorted;
        for (const_iterator it(begin()); !(it == end()); ++it) {
            T func_result = func(*it);
            new_sorted.insert(func_result);
        }
        return new_sorted;
    }
}

#endif //UNTITLED2_SORTEDLIST_H
