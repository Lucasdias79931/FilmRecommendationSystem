#pragma once
#include <iostream>
#include "nodes.h"




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
    private:
        Linear_node *head;
        Linear_node *tail;
        size_t size;
        bool _isEmpty() const;
        void _insert_in_last(T data);
        
};