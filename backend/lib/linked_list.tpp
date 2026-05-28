#include "linked_list.h"




template <typename T>
Linked_list<T>::Linked_list(T data): Generic_Linear_structure<T>(data) {
}


template <typename T>
Linked_list<T>::Linked_list() : Generic_Linear_structure<T>() {}


template <typename T>
Linked_list<T>::~Linked_list() {}