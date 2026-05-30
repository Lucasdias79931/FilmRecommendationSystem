#pragma once
#include "generic_linear_structure.h"

template <typename T>
class Linked_list final : public Generic_Linear_structure<T> {
    public:
        Linked_list(T data);
        Linked_list();

        ~Linked_list() = default;
};