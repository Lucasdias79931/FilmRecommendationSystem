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



