#pragma once
#include <string>

#include "enums.h"

struct Movie {
    std::string name;
    CategoryMovie category;
    size_t year;

    Movie(const std::string& name, CategoryMovie category, size_t year): name(name), category(category), year(year) {}
};