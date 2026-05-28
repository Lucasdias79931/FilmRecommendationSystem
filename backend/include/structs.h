#pragma once
#include <string>

#include "enums.h"

struct Movie {
    std::string name;
    CategoryMovie category;
    size_t year;

    Movie(const std::string& name, CategoryMovie category, size_t year): name(name), category(category), year(year) {}
};


template <typename T>
struct Linear_node{
    T data;
    Linear_node<T> *prev, *next;

    Linear_node(T data):data(data), prev(nullptr), next(nullptr){}
    Linear_node(): prev(nullptr), next(nullptr){}
};



template <typename T>
struct Node_RedBlackTree{
    T data;
    Node_RedBlackTree<T> *left, *right;
    bool black
    Node_RedBlackTree(T data):data(data), black(true), left(nullptr), right(nullptr);
    Node_RedBlackTree():left(nullptr), right(nullptr), black(true);
};