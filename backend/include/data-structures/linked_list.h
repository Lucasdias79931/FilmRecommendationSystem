#pragma once
#include "structs.h"
#include "generic_linear_structure.h"

template <typename T>
class Linked_list final : public Generic_Linear_structure<T> {
    public:
        Linked_list();
        Linked_list(T data);

        
        ~Linked_list() = default;

        const Linear_node<T>* getNode() const;
        void push_back(T data);
};



template <typename T>
Linked_list<T>::Linked_list() : Generic_Linear_structure<T>() {}

template <typename T>
Linked_list<T>::Linked_list(T data) : Generic_Linear_structure<T>(data) {}

template <typename T>
void Linked_list<T>::push_back(T data) {
    this->_insert_in_last(data);
}

template <typename T>
const Linear_node<T>* Linked_list<T>::getNode() const {
    return this->head;
}