#pragma once
#include <string>

#include "enums.h"

struct Movie {
    std::string id;
    std::string name;
    CategoryMovie category;

    std::string origin;
    std::string style; 
    std::string pace;  

    size_t year;
    float rate;

    Movie(
        const std::string& name,
        CategoryMovie category,
        const std::string& origin,
        const std::string& style,
        const std::string& pace,
        size_t year,
        float rate,
        const std::string& id
    )
    : name(name),
      category(category),
      origin(origin),
      style(style),
      pace(pace),
      year(year),
      rate(rate),
      id(id) {}

    Movie(
        const std::string& name,
        CategoryMovie category,
        const std::string& origin,
        const std::string& style,
        const std::string& pace,
        size_t year,
        float rate
    )
    : name(name),
      category(category),
      origin(origin),
      style(style),
      pace(pace),
      year(year),
      rate(rate){}
};


template <typename T>
struct Linear_node{
    T data;
    Linear_node<T> *prev, *next;

    Linear_node(T data):data(data), prev(nullptr), next(nullptr){}
    Linear_node(): prev(nullptr), next(nullptr){}
};


struct Filters {
    CategoryMovie category = CategoryMovie::UNKNOWN;
    std::string origin = "";
    std::string style = "";
    std::string pace = "";

    Filters() = default;

    Filters(CategoryMovie category,
            const std::string& origin,
            const std::string& style,
            const std::string& pace)
        : category(category), origin(origin), style(origin), pace(pace) {}
};
