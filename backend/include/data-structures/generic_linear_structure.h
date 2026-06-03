#pragma once
#include <iostream>
#include "structs.h"




template <typename T>
class Generic_Linear_structure{
    /**
     * @brief Base class for linear data structures.
     *
     * Provides a common foundation for linear structures such as
     * linked lists, stacks, and queues. It maintains pointers to the
     * beginning (head) and end (tail) of the structure, allowing
     * derived classes to implement specific behaviors (e.g., LIFO for
     * stacks, FIFO for queues).
     *
     * @tparam T Type of elements stored in the structure.
     *
     * @note This class is intended to be extended, not used directly.
     */
    protected:
        Linear_node<T>* head;
        Linear_node<T>* tail;
        size_t size;
        bool _isEmpty() const;
        void _insert_in_last(const T&data);
        T _get_last();
    public:
        Generic_Linear_structure(T data);
        Generic_Linear_structure();

        virtual ~Generic_Linear_structure();
};






template <typename T>
Generic_Linear_structure<T>::Generic_Linear_structure()
    : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
Generic_Linear_structure<T>::Generic_Linear_structure(T data)
    : head(nullptr), tail(nullptr), size(0) {
    _insert_in_last(data);
}



template <typename T>
bool Generic_Linear_structure<T>::_isEmpty() const {
    return size == 0;
}

template <typename T>
void Generic_Linear_structure<T>::_insert_in_last(const T& data) {
    Linear_node<T>* newNode = new Linear_node<T>(data);

    if (_isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template <typename T>
T Generic_Linear_structure<T>::_get_last() {
    if (_isEmpty()) {
        throw std::runtime_error("Structure is empty");
    }

    return tail->data;
}

template <typename T>
Generic_Linear_structure<T>::~Generic_Linear_structure() {
    Linear_node<T>* current = head;

    while (current != nullptr) {
        Linear_node<T>* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}