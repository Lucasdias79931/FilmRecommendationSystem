#pragma once
#include "structs.h"
#include "enums.h"
#include <iostream>




template <typename T>
class RedBlackTree{
    private:
        Node_tree *root;

    public:
        void insert(T data);
        
};